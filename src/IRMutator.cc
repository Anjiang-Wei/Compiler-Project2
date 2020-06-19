/*
 * MIT License
 * 
 * Copyright (c) 2020 Size Zheng

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

#include "IRMutator.h"
#include "IRPrinter.h"

namespace Boost {

namespace Internal {

Expr IRMutator::mutate(const Expr &expr) {
    return expr.mutate_expr(this);
}


Stmt IRMutator::mutate(const Stmt &stmt) {
    return stmt.mutate_stmt(this);
}


Group IRMutator::mutate(const Group &group) {
    return group.mutate_group(this);
}


Expr IRMutator::visit(Ref<const IntImm> op) {
    return op;
}


Expr IRMutator::visit(Ref<const UIntImm> op) {
    return op;
}


Expr IRMutator::visit(Ref<const FloatImm> op) {
    return FloatImm::make(op->type(), 0.0);
}


Expr IRMutator::visit(Ref<const StringImm> op) {
    return op;
}


Expr IRMutator::visit(Ref<const Unary> op) {
    Expr new_a = mutate(op->a);
    return Unary::make(op->type(), op->op_type, new_a);
}


Expr IRMutator::visit(Ref<const Binary> op) {
    Expr res;
    Expr new_a = mutate(op->a);
    Expr new_b = mutate(op->b);
    bool zero_flag_l = (new_a.node_type() == IRNodeType::FloatImm);
    bool zero_flag_r = (new_b.node_type() == IRNodeType::FloatImm);

    switch(op->op_type){
        case BinaryOpType::Add:
        case BinaryOpType::Sub: {
            if (zero_flag_l && zero_flag_r) {
                return FloatImm::make(op->type(), 0.0);
            } else if (zero_flag_l) {
                res = (op->op_type == BinaryOpType::Sub) ? 
                    Unary::make(op->type(), UnaryOpType::Neg, new_b): new_b;
            } else if (zero_flag_r) {
                res = new_a;
            } else {
                res = Binary::make(op->type(), op->op_type, new_a, new_b);
            }
            break;
        }
        case BinaryOpType::Mul: {
            Expr item1 = Binary::make(op->type(), op->op_type, new_a, op->b);
            Expr item2 = Binary::make(op->type(), op->op_type, op->a, new_b);
            
            if (zero_flag_l && zero_flag_r) {
                return FloatImm::make(op->type(), 0.0);
            } else if (zero_flag_l) {
                res = item2;
            } else if (zero_flag_r) {
                res = item1;
            } else {
                res = Binary::make(op->type(), BinaryOpType::Add, item1, item2);
            }
            break;
        }
        case BinaryOpType::Div: {
            Expr item1 = Binary::make(op->type(), BinaryOpType::Mul, new_a, op->b);
            Expr item2 = Binary::make(op->type(), BinaryOpType::Mul, op->a, new_b);
            Expr divisor = Cast::make(op->type(), op->type(),
                Binary::make(op->type(), BinaryOpType::Mul, op->b, op->b));
            Expr dividend;
            if (zero_flag_l && zero_flag_r) {
                return FloatImm::make(op->type(), 0.0);
            } else if (zero_flag_r) {
                res = Binary::make(op->type(), BinaryOpType::Div, new_a, op->b);
                break;
            } else if (zero_flag_l) {
                dividend = Unary::make(op->type(), UnaryOpType::Neg, item2);
            } else {
                dividend = Binary::make(op->type(), BinaryOpType::Sub, item1, item2);
            }
            res = Binary::make(op->type(), BinaryOpType::Div, dividend, divisor);
            break;
        }
        default: {
        }
    }
    return Cast::make(res->type(), res->type(), res);
}


Expr IRMutator::visit(Ref<const Compare> op) {
    Expr new_a = mutate(op->a);
    Expr new_b = mutate(op->b);
    return Compare::make(op->type(), op->op_type, new_a, new_b);
}


Expr IRMutator::visit(Ref<const Select> op) {
    Expr new_cond = mutate(op->cond);
    Expr new_true_value = mutate(op->true_value);
    Expr new_false_value = mutate(op->false_value);
    return Select::make(op->type(), new_cond, new_true_value, new_false_value);
}


Expr IRMutator::visit(Ref<const Call> op) {
    std::vector<Expr> new_args;
    for (auto arg : op->args) {
        new_args.push_back(mutate(arg));
    }
    return Call::make(op->type(), new_args, op->func_name, op->call_type);
}


Expr IRMutator::visit(Ref<const Cast> op) {
    Expr new_val = mutate(op->val);
    return Cast::make(op->type(), op->new_type, new_val);
}


Expr IRMutator::visit(Ref<const Ramp> op) {
    Expr new_base = mutate(op->base);
    return Ramp::make(op->type(), new_base, op->stride, op->lanes);
}


Expr IRMutator::visit(Ref<const Var> op) {
    if (is_left) {
        left = Var::make(op->type(), "d" + op->name, op->args, op->shape);
        set_left = true;
    } else if (set_left) {
        if (op->name == grad_to) {
            if (!grad_set) {
                // should rename args later
                grad = Var::make(op->type(), "d" + op->name, op->args, op->shape);
                grad_set = true;
            }
            // should be modified later for index transformation
            // before: args, transformed: new_args
            std::vector<Expr> new_args;
            for (auto arg : left.as<Var>()->args) {
                new_args.push_back(mutate(arg));
            }
            return Var::make(left.as<Var>()->type(), left.as<Var>()->name, 
                new_args, left.as<Var>()->shape);
        } else {
            return FloatImm::make(op->type(), 0.0);
        }
    } 
    return Var::make(op->type(), op->name, op->args, op->shape);   
}


Expr IRMutator::visit(Ref<const Dom> op) {
    Expr new_begin = mutate(op->begin);
    Expr new_extent = mutate(op->extent);
    return Dom::make(op->type(), new_begin, new_extent);
}


Expr IRMutator::visit(Ref<const Index> op) {
    Expr new_dom = mutate(op->dom);
    return Index::make(op->type(), op->name, new_dom, op->index_type);
}


Stmt IRMutator::visit(Ref<const LoopNest> op) {
    std::vector<Expr> new_index_list;
    std::vector<Stmt> new_body_list;
    for (auto index : op->index_list) {
        new_index_list.push_back(mutate(index));
    }
    for (auto body : op->body_list) {
        new_body_list.push_back(mutate(body));
    }
    return LoopNest::make(new_index_list, new_body_list);
}


Stmt IRMutator::visit(Ref<const IfThenElse> op) {
    Expr new_cond = mutate(op->cond);
    Stmt new_true_case = mutate(op->true_case);
    Stmt new_false_case = mutate(op->false_case);
    return IfThenElse::make(new_cond, new_true_case, new_false_case);
}


Stmt IRMutator::visit(Ref<const Move> op) {
    is_left = true;
    Expr new_dst = mutate(op->dst);
    is_left = false;
    Expr new_src = mutate(op->src);
    return Move::make(grad, new_src, op->move_type);
}


Group IRMutator::visit(Ref<const Kernel> op) {
    std::vector<Expr> new_inputs;
    for (auto expr : op->inputs) {
        new_inputs.push_back(mutate(expr));
    }
    std::vector<Expr> new_outputs;
    for (auto expr : op->outputs) {
        new_outputs.push_back(mutate(expr));
    }
    std::vector<Stmt> new_stmt_list;
    for (auto stmt : op->stmt_list) {
        new_stmt_list.push_back(mutate(stmt));
    }
    return Kernel::make(op->name, new_inputs, new_outputs, new_stmt_list, op->kernel_type);
}


}  // namespace Internal

}  // namespace Boost

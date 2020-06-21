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

#include "assert.h"
#include "IRMutator.h"
#include "IRPrinter.h"
#include "string.h"
#include "transform.h"
#include <algorithm>

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

Expr distribute_divisor(Expr a, Expr b) {
    if (a.node_type() == IRNodeType::Cast) {
        return distribute_divisor(a.as<Cast>()->val, b);
    } else if (a.node_type() == IRNodeType::Binary) {
        switch(a.as<Binary>()->op_type) {
            case BinaryOpType::Add: 
            case BinaryOpType::Sub: {
                Expr new_a = distribute_divisor(a.as<Binary>()->a, b);
                Expr new_b = distribute_divisor(a.as<Binary>()->b, b);
                return Binary::make(a.type(), a.as<Binary>()->op_type, new_a, new_b);
            }
            default: {}
        }
    }
    return Binary::make(a.type(), BinaryOpType::Div, a, b);
}

Expr IRMutator::visit(Ref<const Binary> op) {
    //In order to initialized a matrix equation, we need to first rename binary indexes
    // Adding them separately to X and Y
    if (should_rename) {
        if (op->op_type == BinaryOpType::Add) {
            Expr item1 = op->a;
            Expr item2 = op->b;
            bool first_occurred = true;
            for (auto item: X) {
                if (item.as<Index>()->name == item1.as<Index>()->name) {
                    first_occurred = false;
                }
            }
            if (first_occurred) {
                X.push_back(item1);
                matrix_add_indice.push_back(X.size() - 1);
            }
            first_occurred = true;
            for (auto item: X) {
                if (item.as<Index>()->name == item2.as<Index>()->name) {
                    first_occurred = false;
                }
            }
            if (first_occurred) {
                matrix_transform = true;
                X.push_back(item2);
            }            
        }
        //return op;
    }
    if (index_tranform == true) {
        Expr res;
        switch (op->op_type) {
            //Equation z = index_i + const_a Or z = const_a + index_i has solution:
            //index_i = z - const_a
            case BinaryOpType::Add: {
                if (op->a->node_type() == IRNodeType::Index && op->b->node_type() == IRNodeType::IntImm) {
                    res = Binary::make(op->type(), BinaryOpType::Sub, op->a, op->b);
                    return res;
                }
                if (op->a->node_type() == IRNodeType::IntImm && op->b->node_type() == IRNodeType::Index) {
                    res = Binary::make(op->type(), BinaryOpType::Sub, op->b, op->a);
                    return res;
                }
                else {
                    return op;
                }
            }
            //Equation z = index_i - const_a has solution:
            //index_i = z + const_a
            case BinaryOpType::Sub: {
                if (op->a->node_type() == IRNodeType::Index && op->b->node_type() == IRNodeType::IntImm) {
                    res = Binary::make(op->type(), BinaryOpType::Add, op->a, op->b);
                    return Cast::make(res->type(), res->type(), res);
                }
                else {
                    return op;
                }
            }
            //Equation z0 = index_i //const_a, z1 = index_i % const_a has solution:
            //index_i = z0 * const_a + z1
            case BinaryOpType::Mod: {
                //std::cout << "Inside Mod\n";
                if (op->a->node_type() == IRNodeType::Index && op->b->node_type() == IRNodeType::IntImm) {
                    DivMode = true;
                    if (DivModInt != -1 && DivModInt != op->b.as<IntImm>()->value()) {
                        std::cout << "Cannot handle this kind of case now!";
                    }
                    DivModInt = op->b.as<IntImm>()->value();
                    res = Binary::make(op->type(), BinaryOpType::Mod, op->a, op->b);
                    return Cast::make(res->type(), res->type(), res);
                }
                else {
                    return op;
                }
            }
            case BinaryOpType::Div: {
                //std::cout << "Inside Div\n";
                if (op->a->node_type() == IRNodeType::Index && op->b->node_type() == IRNodeType::IntImm) {
                    DivMode = true;
                    if (DivModInt != -1 && DivModInt != op->b.as<IntImm>()->value()) {
                        std::cout << "Cannot handle this kind of case now!";
                    }
                    DivModInt = op->b.as<IntImm>()->value();
                    res = Binary::make(op->type(), BinaryOpType::Div, op->a, op->b);
                    return Cast::make(res->type(), res->type(), res);
                }
                else{
                    return op;
                }
            }
            default:{
            }
        }
    }
    else 
    {
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
                if (matrix_transform) {
                    enter_indice_replacement = true;
                    item1 = Binary::make(op->type(), op->op_type, new_a, mutate(op->b));
                    item2 = Binary::make(op->type(), op->op_type, op->a, mutate(new_b));
                    enter_indice_replacement = false;
                }                
                
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
                    res = distribute_divisor(new_a, op->b);
                    // res = Binary::make(op->type(), BinaryOpType::Div, new_a, op->b);
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
        return res;
    }
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
    if (enter_indice_replacement) {
        std::vector<Expr> new_args;
        for (auto args: op->args) {
            new_args.push_back(mutate(args));
        }
        return Var::make(op->type(), op->name, new_args, op->shape);
    }
    // std::cout << "-----------" << std::endl;
    // std::cout << op->name << std::endl;
    // std::cout << "args is below" << std::endl;    
    // for (auto args: op->args) {
    //     IRPrinter printer;
    //     std::string code = printer.print(args);
    //     if (args.node_type()== IRNodeType::FloatImm) {
    //         std::cout << "float type: ";
    //     }
    //     else if (args.node_type() == IRNodeType::Binary) {
    //         std::cout << "binary type: ";
    //         std::cout << (short)args.as<Binary>()->a.node_type();//a.as<Index>()->name;
    //         std::cout << (short)args.as<Binary>()->b.node_type();
    //     }
    //     else if (args.node_type() == IRNodeType::Index) {
    //         std:: cout << "index type: ";
    //     }
    //     else {
    //         std:: cout << "unknown type " << (short)args.node_type() << ":";
    //     }
    //     std::cout << code << ", ";
    // }
    // std:: cout << std::endl;
    // std::cout << "----------------" << std::endl;

    if (is_left) {
        //std::cout << "is_left: " << op->name << '\n';
        left = Var::make(op->type(), "d" + op->name, op->args, op->shape);
        set_left = true;
    } 
    else if (set_left) {
        if (op->name == grad_to) {

            if (!grad_set) {
                //std::cout << "grad_set: " << op->name << '\n';
                // should rename args later? For example: p+r, i//16, etc...
                for (auto args: op->args) {
                    if (args.node_type() == IRNodeType::Binary) {
                        should_rename = true;
                    }
                }
                if (should_rename) {
                    //std::cout << op->name <<"-------indices should be renamed!!-----------\n";
                    for (auto args: op->args) {
                        if (args.node_type() == IRNodeType::Binary) {
                            Type index_type = Type::int_scalar(32);
                            Expr dom_n = Dom::make(index_type, -100, 100);
                            //renamed expression is needed!
                            Expr renamed_expr = Index::make(index_type, "z" + std::to_string(rename_num), dom_n, IndexType::Spatial);
                            rename_num += 1;
                            rename_args.push_back(renamed_expr);
                            Y.push_back(renamed_expr);
                            mutate(args);
                        }
                        else {
                            rename_args.push_back(args);
                            bool first_occurred = true;
                            for (auto item: X) {
                                if (item.as<Index>()->name == args.as<Index>()->name) {
                                    first_occurred = false;
                                }
                            }
                            if (first_occurred) {
                                X.push_back(args);
                            }
                            first_occurred = true;
                            for (auto item: Y) {
                                if (item.as<Index>()->name == args.as<Index>()->name) {
                                    first_occurred = false;
                                }
                            }
                            if (first_occurred) {
                                Y.push_back(args);
                            }                            
                        }
                    }
                    grad = Var::make(op->type(), "d" + op->name, rename_args, op->shape);
                } 
                else {
                    grad = Var::make(op->type(), "d" + op->name, op->args, op->shape);
                }
                grad_set = true;
            }

            for (auto args: op->args) {
                if (args.node_type() == IRNodeType::Binary) {
                    //std::cout << "binary type: ";
                    index_tranform = true;
                }
                // else if (args.node_type() == IRNodeType::Index) {
                //     std:: cout << "index type: ";
                // }
                // else {
                //     std:: cout << "unknown type " << (short)args.node_type() << ":";
                // }
            }

            // should be modified later for index transformation
            // before: args, transformed: new_args
            std::vector<Expr> new_args;
            if (index_tranform == true) {
                for (auto args: op->args) {
                    new_args.push_back(mutate(args));
                }
            }
            else {
                for (auto arg : left.as<Var>()->args) {
                    new_args.push_back(mutate(arg));
                }
            }
            if (should_rename) {
                new_args.clear();
                for (auto args: left.as<Var>()->args) {
                    new_args.push_back(mutate(args));
                }
            }
                    
            index_tranform = false;
            // std::cout << "----------!!!hey guys! Mutate here!!!!!for " << left.as<Var>()->name << '\n';
            // IRPrinter printer;
            // std::cout << "####X######\n";
            // for (auto itemX : X) {
            //     std::string code = printer.print(itemX);
            //     std::cout << code << ", ";
            // }
            // std::cout << "#####Y######\n";
            // for (auto itemY: Y) {
            //     std::string code = printer.print(itemY);
            //     std::cout << code << ", ";
            // }
            // std::cout << "###matrix_add_indice";
            // for (auto integer: matrix_add_indice) {
            //     std::cout << integer << ", ";
            // }
            // std::cout << "-----------------########\n";
            if (matrix_transform)
            {
                solve();
            }
            if (matrix_transform) {
                new_args.clear();
                IRPrinter printer;
                for (auto items: left.as<Var>()->args) {
                    // std::string code = printer.print(items);
                    // std::cout << code << " ,";
                    new_args.push_back(mutate(items));
                }
            }
            return Var::make(left.as<Var>()->type(), left.as<Var>()->name, 
                new_args, left.as<Var>()->shape);
        } 
        else 
        {
            return FloatImm::make(op->type(), 0.0);
        }
    } 
    //std::cout << "----------Can any one reach here?----------" << "\n";
    return Var::make(op->type(), op->name, op->args, op->shape);   
}


Expr IRMutator::visit(Ref<const Dom> op) {
    Expr new_begin = mutate(op->begin);
    Expr new_extent = mutate(op->extent);
    return Dom::make(op->type(), new_begin, new_extent);
}


Expr IRMutator::visit(Ref<const Index> op) {
    Expr new_dom = mutate(op->dom);
    if (enter_indice_replacement) {
        if (indice_replacement.find(op->name) != indice_replacement.end()) {
            return indice_replacement[op->name];
        }
    }
    if (matrix_transform) {
        if (indice_replacement.find(op->name) != indice_replacement.end()) {
            return indice_replacement[op->name];
        }
    }
    if (should_rename) {
        if (DivMode == true) {
            Expr divisor_renamer = rename_args[0];
            Expr remainder_renamer = rename_args[1];
            Type index_type = Type::int_scalar(32);
            Expr DivModInteger = IntImm::make(index_type, DivModInt);
            Expr tmp_expr = Binary::make(index_type, BinaryOpType::Mul, divisor_renamer, DivModInteger);
            Expr new_indice = Binary::make(index_type, BinaryOpType::Add, tmp_expr, remainder_renamer);
            return Cast::make(new_indice->type(), new_indice->type(), new_indice);
        }
        else if (grad_set == false){
            Type index_type = Type::int_scalar(32);
            Expr dom_p = Dom::make(index_type, -100, 100);
            Expr p = Index::make(index_type, op->name, dom_p, IndexType::Spatial);
            bool first_occurred = true;
            for (auto item: X) {
                if (item.as<Index>()->name == p.as<Index>()->name) {
                    first_occurred = false;
                }
            }
            if (first_occurred) {
                X.push_back(p);
            }
        }

    }
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
    
    void IRMutator::Print(matrix M) {
        for(int i=0;i<M.n_rows;i++) {
            std::cout<<"row "<<i<<": ";
            for(int j=0;j<M.n_cols;j++) {
                std::cout<<M.value(i,j)<<" ";
            }
            std::cout<<std::endl;
        }
    }



    void IRMutator::solve()
    {
        int A_row = Y.size(); 
        int A_column = X.size();
        int a[A_row * A_column] = {};
        int bias = 0;
        for (int row = 0; row < A_row; row++) {
            for (int col = 0; col < A_column; col++) {
                if (row + bias == col) {
                    a[row * A_column + col] = 1;
                    if (std::find(matrix_add_indice.begin(), matrix_add_indice.end(), col) 
                        != matrix_add_indice.end()) {
                            a[row * A_column + col + 1] = 1;
                            bias += 1;
                    }
                }
                
            }
        }
        matrix A(A_row,A_column);
        matrix U(A_row,A_row);
        matrix S(A_row,A_column);
        matrix V(A_column,A_column);

        A.insert(a);

        std::cout << "A is intialized as" << std::endl;
        Print(A);

        U = identity(U.n_rows);
        V = identity(V.n_rows);
        S = A;

        transform(S,U,V);
        matrix R = U*A*V;
        std::cout<<"U*A*V="<<std::endl;
        Print(R);
        std::cout<<"--------------------"<<std::endl<<"S="<<std::endl;
        Print(S);
        std::cout<<"--------------------"<<std::endl<<"U="<<std::endl;
        Print(U);
        std::cout<<"--------------------"<<std::endl<<"V="<<std::endl;
        Print(V);
        extUY.clear();
        //Since U is an identity matrix here
        for (auto item: Y) {
            extUY.push_back(item);
        }

        //Later, we should add some more indices to match the dimension
        //r0, r1, etc...
        for (int i = 0; i < A_column - A_row; i++) {
            Type index_type = Type::int_scalar(32);
            Expr dom_p = Dom::make(index_type, -100, 100);
            Expr p = Index::make(index_type, "r" + std::to_string(i), dom_p, IndexType::Spatial);
            extUY.push_back(p);
        }

        for(int i=0;i<V.n_rows;i++) 
        {
            bool first_one = true;
            bool no_binary = true;
            for(int j=0;j<V.n_cols;j++) {
                if (V.value(i,j) != 0) {
                    if (first_one == false) {
                        no_binary = false;
                    }
                    else
                    {
                        first_one = false;
                    }

                }
            }
            if (no_binary) 
            //this means that there is a one-to-one projection from Y to X for this index (row:i)
            {
                int non_zero_index = 0;
                for (int j = 0; j < V.n_cols; j++) {
                    if (V.value(i, j) != 0) {
                        non_zero_index = j;
                    }
                }
                // std::cout << "------------HAHAHAHA!!!!--------------\n";
                // std::cout << X[i].as<Index>()->name << "is replaced as " << extUY[non_zero_index].as<Index>()->name << "\n";
                indice_replacement[X[i].as<Index>()->name] = extUY[non_zero_index];
            }
            else {
                int positive_one_index = 0;
                int negative_one_index = 0;
                for (int j = 0; j < V.n_cols; j++) {
                    if (V.value(i, j) == 1) {
                        positive_one_index = j;
                    }
                    if (V.value(i, j) == -1) {
                        negative_one_index = j;
                    }
                }
                Expr positive_index = extUY[positive_one_index];
                Expr negative_index = extUY[negative_one_index];
                Type index_type = Type::int_scalar(32);
                Expr tmp_expr = Binary::make(index_type, BinaryOpType::Sub, positive_index, negative_index);
                IRPrinter printer;
                std::string code = printer.print(tmp_expr);
                // std::cout << "------------HAHAHAHA!!!!--------------\n";
                // std::cout << X[i].as<Index>()->name << " is replaced as " << code << "\n";
                indice_replacement[X[i].as<Index>()->name] = tmp_expr;
            }
        }


    }



}  // namespace Internal

}  // namespace Boost

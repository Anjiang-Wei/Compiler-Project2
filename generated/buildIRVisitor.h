#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "antlr4-runtime.h"
#include "projectExprVisitor.h"

using namespace Boost::Internal;

class buildIRVistor : public projectExprVisitor {
public:
    // Each stmt has a index map which maps from a var name to a Index
    std::vector<std::map<std::string, Expr> > indexes;
    int curmap = 0;
    bool lhs_flag = false;
    Type data_type;
    Type index_type;

    std::vector<Expr> idx;
    std::vector<size_t> shape;

    // used for record reduce idx
    std::set<std::string> spatial_str;
    std::set<std::string> reduce_str;
    std::vector<Expr> reduce_idx;
    std::vector<Expr> expr_idx;
    std::vector<std::string> text_idx;

    std::vector<Stmt> loop_stmts; // inner loops
    std::vector<Stmt> kernel_stmts; // outer loops
    Expr tmpVar; // dest for move stmts

    // used for inner loops
    std::string outside_op = "+";
    bool inside_flag = false;

    std::map<std::string, Expr> vars; // used for arguments

    antlrcpp::Any visitProg(projectExprParser::ProgContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitPBegin(projectExprParser::PBeginContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitPBeginR(projectExprParser::PBeginRContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitStmt(projectExprParser::StmtContext *ctx) override {
        //--------Build tmp array--------
        Expr LHSVar = ctx->children[0]->accept(this);
        std::vector<size_t> LHSShape = LHSVar.as<Var>()->shape;
        std::vector<Expr> LHSIdxs = LHSVar.as<Var>()->args;
        std::string tmpName = "_tmp";
        tmpName += std::to_string(curmap);
        tmpVar = Var::make(data_type, tmpName, LHSIdxs, LHSShape);

        // Generate tmp declaration. Use MoveType::LocalToLocal to tell the visitor;
        // TODO: Maybe this is too DIRTY !!! Perhaps there is some better way to implement it.
        Stmt genDeclaration = Move::make(tmpVar, 0, MoveType::LocalToLocal);
        kernel_stmts.push_back(genDeclaration);

        //--------Process RHS--------
        ctx->children[2]->accept(this);
        Stmt main_loop = LoopNest::make(LHSIdxs, loop_stmts);
        loop_stmts.clear();
        kernel_stmts.push_back(main_loop);

        //--------Assign tmp to input--------
        Expr InputVar = Var::make(data_type, LHSVar.as<Var>()->name, LHSIdxs, LHSShape);
        Stmt moveBackAssign = Move::make(InputVar, tmpVar, MoveType::MemToMem);
        Stmt moveBackLoop = LoopNest::make(LHSIdxs, {moveBackAssign});
        kernel_stmts.push_back(moveBackLoop);
        curmap++;

        //--------Clear spatial index---------
        spatial_str.clear(); 

        return NULL;
    }

    antlrcpp::Any visitLhs(projectExprParser::LhsContext *ctx) override {
        lhs_flag = true;
        Expr expr = ctx->children[0]->accept(this);
        lhs_flag = false;
        return expr;
    }

    antlrcpp::Any visitRhsE(projectExprParser::RhsEContext *ctx) override {
        if (inside_flag) {
            Expr expr = ctx->children[0]->accept(this); // should be a var
            std::pair<std::string, Expr> op_pair = ctx->children[1]->accept(this);
            if (op_pair.first == "")
                return expr;
            if (op_pair.first == "+")
                return Binary::make(data_type, BinaryOpType::Add, expr, op_pair.second);
            else if (op_pair.first == "-")
                return Binary::make(data_type, BinaryOpType::Sub, expr, op_pair.second);
        } else {
            inside_flag = true;
            Expr expr = ctx->children[0]->accept(this); // should be a var or expression
            inside_flag = false;
            Expr src;
            if (outside_op == "+")
                src = Binary::make(data_type, BinaryOpType::Add, tmpVar, expr);
            else if (outside_op == "-")
                src = Binary::make(data_type, BinaryOpType::Sub, tmpVar, expr);
            Stmt move = Move::make(tmpVar, src, MoveType::MemToMem);
            IRPrinter printer_;

            // Find the expression in the indexes;
            std::vector<Expr> reduce_expr_idx;
            std::vector<std::string> reduce_text_idx;
            // the item in `expr_idx` and `text_idx` should match
            assert(expr_idx.size() == text_idx.size());
            for (size_t i = 0; i < expr_idx.size(); ++i) {
                if (expr_idx[i].node_type() == IRNodeType::Binary) {
                    reduce_expr_idx.push_back(expr_idx[i]);
                    reduce_text_idx.push_back(text_idx[i]);
                }
            }
            expr_idx.clear();
            text_idx.clear();
            Stmt finalNode;
            Stmt innerLoop;
            // Build the `IfThenElse` stmt when there is expression in index to judge whether
            // the index is out of range.
            for (size_t i = 0; i < reduce_expr_idx.size(); ++i) {
                Expr upper = indexes[curmap][reduce_text_idx[i]].as<Index>()->dom.as<Dom>()->extent;
                Expr lower = indexes[curmap][reduce_text_idx[i]].as<Index>()->dom.as<Dom>()->begin;
                Expr cmpNode_U =
                        Compare::make(data_type, CompareOpType::LT, reduce_expr_idx[i], upper);
                Expr cmpNode_B =
                        Compare::make(data_type, CompareOpType::GE, reduce_expr_idx[i], lower);
                Expr andNode =
                        Binary::make(data_type, BinaryOpType::And, cmpNode_U, cmpNode_B);
                if (i == 0)
                    finalNode = IfThenElse::make(andNode, move, Stmt());
                else {
                    finalNode = IfThenElse::make(andNode, finalNode, Stmt());
                }
            }
            if (!reduce_text_idx.empty()) {
                innerLoop = LoopNest::make(reduce_idx, {finalNode});
            } else innerLoop = LoopNest::make(reduce_idx, {move});

            // add this inner loop to outer loop
            loop_stmts.push_back(innerLoop);
            reduce_idx.clear();
            reduce_str.clear();
            std::pair<std::string, Expr> op_pair = ctx->children[1]->accept(this);

            // [added by yy] [question] Maybe just a placeholder?
            return Var::make(data_type, "token", {}, {});
        }
        return NULL;
    }

    antlrcpp::Any visitRhsER(projectExprParser::RhsERContext *ctx) override {
        size_t n = ctx->children.size();
        if (n == 0)
            return std::pair<std::string, Expr>("", NULL);
        std::string op = ctx->children[0]->getText();
        outside_op = op;
        Expr expr = ctx->children[1]->accept(this);
        return std::pair<std::string, Expr>(op, expr);
    }

    antlrcpp::Any visitRhsI(projectExprParser::RhsIContext *ctx) override {
        size_t n = ctx->children.size();
        Expr expr;
        std::string text;
        std::pair<std::string, Expr> op_pair;
        if (n == 2) {
            expr = ctx->children[0]->accept(this); // should return a var
            op_pair = ctx->children[1]->accept(this);
        } else {
            expr = ctx->children[1]->accept(this);
            expr = Cast::make(expr->type(), expr->type(), expr);
            op_pair = ctx->children[3]->accept(this);
        }
        if (op_pair.first == "")
            return expr;
        if (op_pair.first == "*")
            return Binary::make(data_type, BinaryOpType::Mul, expr, op_pair.second);
        else if (op_pair.first == "//" || op_pair.first == "/")
            return Binary::make(data_type, BinaryOpType::Div, expr, op_pair.second);
        else if (op_pair.first == "%")
            return Binary::make(data_type, BinaryOpType::Mod, expr, op_pair.second);
        return visitChildren(ctx);
    }

    antlrcpp::Any visitRhsIR(projectExprParser::RhsIRContext *ctx) override {
        size_t n = ctx->children.size();
        if (n == 0)
            return std::pair<std::string, Expr>("", NULL);
        std::string op = ctx->children[0]->getText();
        Expr expr = ctx->children[1]->accept(this);
        return std::pair<std::string, Expr>(op, expr);
    }

    antlrcpp::Any visitTRef(projectExprParser::TRefContext *ctx) override {
        visitChildren(ctx);
        std::string name = ctx->ID()->getText();
        Expr var = Var::make(data_type, name, idx, shape);
        for (const auto &item : idx) {
            expr_idx.push_back(item);
        }
        idx.clear();
        shape.clear();
        if (vars.find(name) == vars.end())
            vars.insert(std::pair<std::string, Expr>(name, var));
        // IRPrinter printer;
        // std::string code = printer.print(var);
        // std::cout << code << '\n';
        return var;
    }

    antlrcpp::Any visitSRef(projectExprParser::SRefContext *ctx) override {
        // visitChildren(ctx);
        std::string name = ctx->ID()->getText();
        Expr var = Var::make(data_type, name, {}, {});
        if (vars.find(name) == vars.end())
            vars.insert(std::pair<std::string, Expr>(name, var));
        // IRPrinter printer;
        // std::string code = printer.print(var);
        // std::cout << code << '\n';
        shape.clear();
        return var;
    }

    antlrcpp::Any visitCList(projectExprParser::CListContext *ctx) override {
        int num = std::stoi(ctx->children[0]->getText());
        shape.push_back(num);
        ctx->children[1]->accept(this);
        return NULL;
    }

    antlrcpp::Any visitCListR(projectExprParser::CListRContext *ctx) override {
        size_t n = ctx->children.size();
        if (n > 0) {
            int num = std::stoi(ctx->children[1]->getText());
            shape.push_back(num);
            ctx->children[2]->accept(this);
        }
        return NULL;
    }

    antlrcpp::Any visitAList(projectExprParser::AListContext *ctx) override {
        Expr expr = ctx->children[0]->accept(this);
        idx.push_back(expr);
        text_idx.push_back(ctx->idExprE()->getText());
        ctx->children[1]->accept(this);
        return NULL;
    }

    antlrcpp::Any visitAListR(projectExprParser::AListRContext *ctx) override {
        size_t n = ctx->children.size();
        if (n > 0) {
            Expr expr = ctx->children[1]->accept(this);
            idx.push_back(expr);
            text_idx.push_back(ctx->idExprE()->getText());
            ctx->children[2]->accept(this);
        }
        return NULL;
    }

    antlrcpp::Any visitIdExprE(projectExprParser::IdExprEContext *ctx) override {
        Expr expr = ctx->children[0]->accept(this);
        // IRPrinter printer;
        // std::string code = printer.print(expr);
        // std::cout << code << '\n';
        std::pair<std::string, Expr> op_pair = ctx->children[1]->accept(this);
        if (op_pair.first == "")
            return expr;
        if (op_pair.first == "+")
            return Binary::make(data_type, BinaryOpType::Add, expr, op_pair.second);
        else if (op_pair.first == "-")
            return Binary::make(data_type, BinaryOpType::Sub, expr, op_pair.second);
        // This place shouldn't be reached
        return NULL;
    }

    antlrcpp::Any visitIdExprER(projectExprParser::IdExprERContext *ctx) override {
        size_t n = ctx->children.size();
        if (n == 0)
            return std::pair<std::string, Expr>("", NULL);
        std::string op = ctx->children[0]->getText();
        Expr expr = ctx->children[1]->accept(this);
        return std::pair<std::string, Expr>(op, expr);
        // return NULL;
    }

    antlrcpp::Any visitIdExprI(projectExprParser::IdExprIContext *ctx) override {
        size_t n = ctx->children.size();
        Expr expr;
        std::string text;
        std::pair<std::string, Expr> op_pair;
        if (n == 2) {
            text = ctx->children[0]->getText();
            if (ctx->IntV() != NULL) {
                expr = IntImm::make(Type::int_scalar(32), std::stoi(text));
            } else {
                auto it = indexes[curmap].find(text);
                if (it != indexes[curmap].end()) {
                    expr = it->second;
                    if (lhs_flag) {
                        spatial_str.insert(text);
                    } else {
                        if (spatial_str.find(text) == spatial_str.end() &&
                            reduce_str.find(text) == reduce_str.end()) {
                            reduce_idx.push_back(expr);
                            reduce_str.insert(text);
                        }
                    }
                }
            }
            op_pair = ctx->children[1]->accept(this);
        } else {
            expr = ctx->children[1]->accept(this);
            expr = Cast::make(expr->type(), expr->type(), expr);
            op_pair = ctx->children[3]->accept(this);
        }
        if (op_pair.first == "")
            return expr;
        if (op_pair.first == "*")
            return Binary::make(data_type, BinaryOpType::Mul, expr, op_pair.second);
        else if (op_pair.first == "//")
            return Binary::make(data_type, BinaryOpType::Div, expr, op_pair.second);
        else if (op_pair.first == "%")
            return Binary::make(data_type, BinaryOpType::Mod, expr, op_pair.second);
        else throw (std::invalid_argument("Unknown Error"));
    }

    antlrcpp::Any visitIdExprIR(projectExprParser::IdExprIRContext *ctx) override {
        size_t n = ctx->children.size();
        if (n == 0)
            return std::pair<std::string, Expr>("", NULL);
        std::string op = ctx->children[0]->getText();
        Expr expr = ctx->children[1]->accept(this);
        return std::pair<std::string, Expr>(op, expr);
        // return visitChildren(ctx);
    }

    antlrcpp::Any visitConVal(projectExprParser::ConValContext *ctx) override {
        std::string name = ctx->getText();
        Expr var = Var::make(data_type, name, {}, {});
        return var;
    }


};

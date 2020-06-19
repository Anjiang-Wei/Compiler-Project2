#pragma once


#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "antlr4-runtime.h"
#include "projectExprVisitor.h"
#include "IR.h"
#include "IRMutator.h"
#include "IRVisitor.h"
#include "IRPrinter.h"
#include "type.h"

using namespace Boost::Internal;

class SimpleIRVisitor : public projectExprVisitor {
public:
    std::vector<std::map<std::string, Expr> > indexes;
    Boost::Internal::Type index_type = Boost::Internal::Type::int_scalar(32);
    Boost::Internal::Type data_type;
    std::vector<Stmt> kernel_stmts;
    std::map<std::string, Expr> vars;

    std::vector<Expr> idx;
    std::vector<size_t> shape;
    int curMap = 0;

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
        Expr LHS = ctx->children[0]->accept(this);
        Expr RHS = ctx->children[2]->accept(this);
        Stmt stmt = Move::make(LHS, RHS, MoveType::MemToMem);
        kernel_stmts.push_back(stmt);
        return stmt;
    }

    antlrcpp::Any visitLhs(projectExprParser::LhsContext *ctx) override {
        return ctx->children[0]->accept(this);
    }

    antlrcpp::Any visitRhsE(projectExprParser::RhsEContext *ctx) override {
        Expr expr = ctx->children[0]->accept(this);
        std::pair<std::string, Expr> op_pair = ctx->children[1]->accept(this);
        if (op_pair.first == "")
            return expr;
        if (op_pair.first == "+")
            return Binary::make(data_type, BinaryOpType::Add, expr, op_pair.second);
        else if (op_pair.first == "-")
            return Binary::make(data_type, BinaryOpType::Sub, expr, op_pair.second);
        assert (false);
    }

    antlrcpp::Any visitRhsER(projectExprParser::RhsERContext *ctx) override {
        size_t n = ctx->children.size();
        if (n == 0)
            return std::pair<std::string, Expr>("", NULL);
        std::string op = ctx->children[0]->getText();
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
        else throw (std::invalid_argument("Unknown Error"));
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
        idx.clear();
        shape.clear();
        if (vars.find(name) == vars.end())
            vars.insert(std::pair<std::string, Expr>(name, var));
        return var;
    }

    antlrcpp::Any visitSRef(projectExprParser::SRefContext *ctx) override {
        visitChildren(ctx);
        std::string name = ctx->ID()->getText();
        Expr var = Var::make(data_type, name, {}, {});
        if (vars.find(name) == vars.end())
            vars.insert(std::pair<std::string, Expr>(name, var));
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
        ctx->children[1]->accept(this);
        return NULL;
    }

    antlrcpp::Any visitAListR(projectExprParser::AListRContext *ctx) override {
        size_t n = ctx->children.size();
        if (n > 0) {
            Expr expr = ctx->children[1]->accept(this);
            idx.push_back(expr);
            ctx->children[2]->accept(this);
        }
        return NULL;
    }

    antlrcpp::Any visitIdExprE(projectExprParser::IdExprEContext *ctx) override {
        Expr expr = ctx->children[0]->accept(this);
        std::pair<std::string, Expr> op_pair = ctx->children[1]->accept(this);
        if (op_pair.first == "")
            return expr;
        if (op_pair.first == "+")
            return Binary::make(data_type, BinaryOpType::Add, expr, op_pair.second);
        else if (op_pair.first == "-")
            return Binary::make(data_type, BinaryOpType::Sub, expr, op_pair.second);
        assert (false);
    }

    antlrcpp::Any visitIdExprER(projectExprParser::IdExprERContext *ctx) override {
        size_t n = ctx->children.size();
        if (n == 0)
            return std::pair<std::string, Expr>("", NULL);
        std::string op = ctx->children[0]->getText();
        Expr expr = ctx->children[1]->accept(this);
        return std::pair<std::string, Expr>(op, expr);
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
                auto it = indexes[curMap].find(text);
                assert (it != indexes[curMap].end());
                expr = it->second;
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
    }

    antlrcpp::Any visitConVal(projectExprParser::ConValContext *ctx) override {
        Expr imm;
        std::string text = ctx->children[0]->getText();
        if (ctx->IntV() != NULL) {
            imm = IntImm::make(Type::int_scalar(32), std::stoi(text));
        } else {
            assert (ctx->FloatV() != NULL);
            imm = FloatImm::make(Type::float_scalar(32), std::stof(text));
        }
        return imm;
    }


};


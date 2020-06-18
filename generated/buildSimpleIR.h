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
    std::vector<Stmt> kernel_stmts;
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
        visitChildren(ctx);
        return NULL;
    }

    antlrcpp::Any visitLhs(projectExprParser::LhsContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitRhsE(projectExprParser::RhsEContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitRhsER(projectExprParser::RhsERContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitRhsI(projectExprParser::RhsIContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitRhsIR(projectExprParser::RhsIRContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitTRef(projectExprParser::TRefContext *ctx) override {
        visitChildren(ctx);
        return NULL;
    }

    antlrcpp::Any visitSRef(projectExprParser::SRefContext *ctx) override {
        visitChildren(ctx);
        return NULL;
    }

    antlrcpp::Any visitCList(projectExprParser::CListContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitCListR(projectExprParser::CListRContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitAList(projectExprParser::AListContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitAListR(projectExprParser::AListRContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitIdExprE(projectExprParser::IdExprEContext *ctx) override {
        return ctx->getText();
    }

    antlrcpp::Any visitIdExprER(projectExprParser::IdExprERContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitIdExprI(projectExprParser::IdExprIContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitIdExprIR(projectExprParser::IdExprIRContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitConVal(projectExprParser::ConValContext *ctx) override {
        return visitChildren(ctx);
    }


};


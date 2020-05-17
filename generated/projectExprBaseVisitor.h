
// Generated from projectExpr.g4 by ANTLR 4.8

#pragma once


#include <iostream>
#include <string>
#include "antlr4-runtime.h"
#include "projectExprVisitor.h"
#include "IR.h"
#include "IRMutator.h"
#include "IRVisitor.h"
#include "IRPrinter.h"
#include "type.h"


/**
 * This class provides an empty implementation of projectExprVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  projectExprBaseVisitor : public projectExprVisitor {
public:
  std::vector<std::map<std::string, Boost::Internal::Expr> > domains;

  virtual antlrcpp::Any visitProg(projectExprParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPBegin(projectExprParser::PBeginContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPBeginR(projectExprParser::PBeginRContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmt(projectExprParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLhs(projectExprParser::LhsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRhsE(projectExprParser::RhsEContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRhsER(projectExprParser::RhsERContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRhsI(projectExprParser::RhsIContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRhsIR(projectExprParser::RhsIRContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTRef(projectExprParser::TRefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSRef(projectExprParser::SRefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCList(projectExprParser::CListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCListR(projectExprParser::CListRContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAList(projectExprParser::AListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAListR(projectExprParser::AListRContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdExprE(projectExprParser::IdExprEContext *ctx) override {
    
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdExprER(projectExprParser::IdExprERContext *ctx) override {
    antlrcpp::Any result = defaultResult();
      size_t n = ctx->children.size();
      std::cout << "num: " << n <<'\n';
      for (size_t i = 0; i < n; i++) {
        std::cout << ctx->children[i]->toStringTree()<<'\n';
      }
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdExprI(projectExprParser::IdExprIContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdExprIR(projectExprParser::IdExprIRContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConVal(projectExprParser::ConValContext *ctx) override {
    return visitChildren(ctx);
  }


};


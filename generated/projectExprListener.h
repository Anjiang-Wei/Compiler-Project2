
// Generated from projectExpr.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "projectExprParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by projectExprParser.
 */
class  projectExprListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProg(projectExprParser::ProgContext *ctx) = 0;
  virtual void exitProg(projectExprParser::ProgContext *ctx) = 0;

  virtual void enterPBegin(projectExprParser::PBeginContext *ctx) = 0;
  virtual void exitPBegin(projectExprParser::PBeginContext *ctx) = 0;

  virtual void enterPBeginR(projectExprParser::PBeginRContext *ctx) = 0;
  virtual void exitPBeginR(projectExprParser::PBeginRContext *ctx) = 0;

  virtual void enterStmt(projectExprParser::StmtContext *ctx) = 0;
  virtual void exitStmt(projectExprParser::StmtContext *ctx) = 0;

  virtual void enterLhs(projectExprParser::LhsContext *ctx) = 0;
  virtual void exitLhs(projectExprParser::LhsContext *ctx) = 0;

  virtual void enterRhsE(projectExprParser::RhsEContext *ctx) = 0;
  virtual void exitRhsE(projectExprParser::RhsEContext *ctx) = 0;

  virtual void enterRhsER(projectExprParser::RhsERContext *ctx) = 0;
  virtual void exitRhsER(projectExprParser::RhsERContext *ctx) = 0;

  virtual void enterRhsI(projectExprParser::RhsIContext *ctx) = 0;
  virtual void exitRhsI(projectExprParser::RhsIContext *ctx) = 0;

  virtual void enterRhsIR(projectExprParser::RhsIRContext *ctx) = 0;
  virtual void exitRhsIR(projectExprParser::RhsIRContext *ctx) = 0;

  virtual void enterTRef(projectExprParser::TRefContext *ctx) = 0;
  virtual void exitTRef(projectExprParser::TRefContext *ctx) = 0;

  virtual void enterSRef(projectExprParser::SRefContext *ctx) = 0;
  virtual void exitSRef(projectExprParser::SRefContext *ctx) = 0;

  virtual void enterCList(projectExprParser::CListContext *ctx) = 0;
  virtual void exitCList(projectExprParser::CListContext *ctx) = 0;

  virtual void enterCListR(projectExprParser::CListRContext *ctx) = 0;
  virtual void exitCListR(projectExprParser::CListRContext *ctx) = 0;

  virtual void enterAList(projectExprParser::AListContext *ctx) = 0;
  virtual void exitAList(projectExprParser::AListContext *ctx) = 0;

  virtual void enterAListR(projectExprParser::AListRContext *ctx) = 0;
  virtual void exitAListR(projectExprParser::AListRContext *ctx) = 0;

  virtual void enterIdExprE(projectExprParser::IdExprEContext *ctx) = 0;
  virtual void exitIdExprE(projectExprParser::IdExprEContext *ctx) = 0;

  virtual void enterIdExprER(projectExprParser::IdExprERContext *ctx) = 0;
  virtual void exitIdExprER(projectExprParser::IdExprERContext *ctx) = 0;

  virtual void enterIdExprI(projectExprParser::IdExprIContext *ctx) = 0;
  virtual void exitIdExprI(projectExprParser::IdExprIContext *ctx) = 0;

  virtual void enterIdExprIR(projectExprParser::IdExprIRContext *ctx) = 0;
  virtual void exitIdExprIR(projectExprParser::IdExprIRContext *ctx) = 0;

  virtual void enterConVal(projectExprParser::ConValContext *ctx) = 0;
  virtual void exitConVal(projectExprParser::ConValContext *ctx) = 0;


};


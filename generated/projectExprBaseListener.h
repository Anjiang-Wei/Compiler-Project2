
// Generated from projectExpr.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "projectExprListener.h"


/**
 * This class provides an empty implementation of projectExprListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  projectExprBaseListener : public projectExprListener {
public:

  virtual void enterProg(projectExprParser::ProgContext * /*ctx*/) override { }
  virtual void exitProg(projectExprParser::ProgContext * /*ctx*/) override { }

  virtual void enterPBegin(projectExprParser::PBeginContext * /*ctx*/) override { }
  virtual void exitPBegin(projectExprParser::PBeginContext * /*ctx*/) override { }

  virtual void enterPBeginR(projectExprParser::PBeginRContext * /*ctx*/) override { }
  virtual void exitPBeginR(projectExprParser::PBeginRContext * /*ctx*/) override { }

  virtual void enterStmt(projectExprParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(projectExprParser::StmtContext * /*ctx*/) override { }

  virtual void enterLhs(projectExprParser::LhsContext * /*ctx*/) override { }
  virtual void exitLhs(projectExprParser::LhsContext * /*ctx*/) override { }

  virtual void enterRhsE(projectExprParser::RhsEContext * /*ctx*/) override { }
  virtual void exitRhsE(projectExprParser::RhsEContext * /*ctx*/) override { }

  virtual void enterRhsER(projectExprParser::RhsERContext * /*ctx*/) override { }
  virtual void exitRhsER(projectExprParser::RhsERContext * /*ctx*/) override { }

  virtual void enterRhsI(projectExprParser::RhsIContext * /*ctx*/) override { }
  virtual void exitRhsI(projectExprParser::RhsIContext * /*ctx*/) override { }

  virtual void enterRhsIR(projectExprParser::RhsIRContext * /*ctx*/) override { }
  virtual void exitRhsIR(projectExprParser::RhsIRContext * /*ctx*/) override { }

  virtual void enterTRef(projectExprParser::TRefContext * /*ctx*/) override { }
  virtual void exitTRef(projectExprParser::TRefContext * /*ctx*/) override { }

  virtual void enterSRef(projectExprParser::SRefContext * /*ctx*/) override { }
  virtual void exitSRef(projectExprParser::SRefContext * /*ctx*/) override { }

  virtual void enterCList(projectExprParser::CListContext * /*ctx*/) override { }
  virtual void exitCList(projectExprParser::CListContext * /*ctx*/) override { }

  virtual void enterCListR(projectExprParser::CListRContext * /*ctx*/) override { }
  virtual void exitCListR(projectExprParser::CListRContext * /*ctx*/) override { }

  virtual void enterAList(projectExprParser::AListContext * /*ctx*/) override { }
  virtual void exitAList(projectExprParser::AListContext * /*ctx*/) override { }

  virtual void enterAListR(projectExprParser::AListRContext * /*ctx*/) override { }
  virtual void exitAListR(projectExprParser::AListRContext * /*ctx*/) override { }

  virtual void enterIdExprE(projectExprParser::IdExprEContext * /*ctx*/) override { }
  virtual void exitIdExprE(projectExprParser::IdExprEContext * /*ctx*/) override { }

  virtual void enterIdExprER(projectExprParser::IdExprERContext * /*ctx*/) override { }
  virtual void exitIdExprER(projectExprParser::IdExprERContext * /*ctx*/) override { }

  virtual void enterIdExprI(projectExprParser::IdExprIContext * /*ctx*/) override { }
  virtual void exitIdExprI(projectExprParser::IdExprIContext * /*ctx*/) override { }

  virtual void enterIdExprIR(projectExprParser::IdExprIRContext * /*ctx*/) override { }
  virtual void exitIdExprIR(projectExprParser::IdExprIRContext * /*ctx*/) override { }

  virtual void enterConVal(projectExprParser::ConValContext * /*ctx*/) override { }
  virtual void exitConVal(projectExprParser::ConValContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};


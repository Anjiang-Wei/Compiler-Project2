
// Generated from projectExpr.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "projectExprParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by projectExprParser.
 */
class  projectExprVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by projectExprParser.
   */
    virtual antlrcpp::Any visitProg(projectExprParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitPBegin(projectExprParser::PBeginContext *context) = 0;

    virtual antlrcpp::Any visitPBeginR(projectExprParser::PBeginRContext *context) = 0;

    virtual antlrcpp::Any visitStmt(projectExprParser::StmtContext *context) = 0;

    virtual antlrcpp::Any visitLhs(projectExprParser::LhsContext *context) = 0;

    virtual antlrcpp::Any visitRhsE(projectExprParser::RhsEContext *context) = 0;

    virtual antlrcpp::Any visitRhsER(projectExprParser::RhsERContext *context) = 0;

    virtual antlrcpp::Any visitRhsI(projectExprParser::RhsIContext *context) = 0;

    virtual antlrcpp::Any visitRhsIR(projectExprParser::RhsIRContext *context) = 0;

    virtual antlrcpp::Any visitTRef(projectExprParser::TRefContext *context) = 0;

    virtual antlrcpp::Any visitSRef(projectExprParser::SRefContext *context) = 0;

    virtual antlrcpp::Any visitCList(projectExprParser::CListContext *context) = 0;

    virtual antlrcpp::Any visitCListR(projectExprParser::CListRContext *context) = 0;

    virtual antlrcpp::Any visitAList(projectExprParser::AListContext *context) = 0;

    virtual antlrcpp::Any visitAListR(projectExprParser::AListRContext *context) = 0;

    virtual antlrcpp::Any visitIdExprE(projectExprParser::IdExprEContext *context) = 0;

    virtual antlrcpp::Any visitIdExprER(projectExprParser::IdExprERContext *context) = 0;

    virtual antlrcpp::Any visitIdExprI(projectExprParser::IdExprIContext *context) = 0;

    virtual antlrcpp::Any visitIdExprIR(projectExprParser::IdExprIRContext *context) = 0;

    virtual antlrcpp::Any visitConVal(projectExprParser::ConValContext *context) = 0;


};


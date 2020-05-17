
// Generated from projectExpr.g4 by ANTLR 4.8


#include "projectExprListener.h"
#include "projectExprVisitor.h"

#include "projectExprParser.h"


using namespace antlrcpp;
using namespace antlr4;

projectExprParser::projectExprParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

projectExprParser::~projectExprParser() {
  delete _interpreter;
}

std::string projectExprParser::getGrammarFileName() const {
  return "projectExpr.g4";
}

const std::vector<std::string>& projectExprParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& projectExprParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

projectExprParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

projectExprParser::PBeginContext* projectExprParser::ProgContext::pBegin() {
  return getRuleContext<projectExprParser::PBeginContext>(0);
}


size_t projectExprParser::ProgContext::getRuleIndex() const {
  return projectExprParser::RuleProg;
}

void projectExprParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void projectExprParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}


antlrcpp::Any projectExprParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<projectExprVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

projectExprParser::ProgContext* projectExprParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, projectExprParser::RuleProg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(40);
    pBegin();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PBeginContext ------------------------------------------------------------------

projectExprParser::PBeginContext::PBeginContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

projectExprParser::StmtContext* projectExprParser::PBeginContext::stmt() {
  return getRuleContext<projectExprParser::StmtContext>(0);
}

projectExprParser::PBeginRContext* projectExprParser::PBeginContext::pBeginR() {
  return getRuleContext<projectExprParser::PBeginRContext>(0);
}


size_t projectExprParser::PBeginContext::getRuleIndex() const {
  return projectExprParser::RulePBegin;
}

void projectExprParser::PBeginContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPBegin(this);
}

void projectExprParser::PBeginContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPBegin(this);
}


antlrcpp::Any projectExprParser::PBeginContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<projectExprVisitor*>(visitor))
    return parserVisitor->visitPBegin(this);
  else
    return visitor->visitChildren(this);
}

projectExprParser::PBeginContext* projectExprParser::pBegin() {
  PBeginContext *_localctx = _tracker.createInstance<PBeginContext>(_ctx, getState());
  enterRule(_localctx, 2, projectExprParser::RulePBegin);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(42);
    stmt();
    setState(43);
    pBeginR();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PBeginRContext ------------------------------------------------------------------

projectExprParser::PBeginRContext::PBeginRContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

projectExprParser::StmtContext* projectExprParser::PBeginRContext::stmt() {
  return getRuleContext<projectExprParser::StmtContext>(0);
}

projectExprParser::PBeginRContext* projectExprParser::PBeginRContext::pBeginR() {
  return getRuleContext<projectExprParser::PBeginRContext>(0);
}


size_t projectExprParser::PBeginRContext::getRuleIndex() const {
  return projectExprParser::RulePBeginR;
}

void projectExprParser::PBeginRContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPBeginR(this);
}

void projectExprParser::PBeginRContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPBeginR(this);
}


antlrcpp::Any projectExprParser::PBeginRContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<projectExprVisitor*>(visitor))
    return parserVisitor->visitPBeginR(this);
  else
    return visitor->visitChildren(this);
}

projectExprParser::PBeginRContext* projectExprParser::pBeginR() {
  PBeginRContext *_localctx = _tracker.createInstance<PBeginRContext>(_ctx, getState());
  enterRule(_localctx, 4, projectExprParser::RulePBeginR);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(49);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case projectExprParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(45);
        stmt();
        setState(46);
        pBeginR();
        break;
      }

      case projectExprParser::EOF: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

projectExprParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

projectExprParser::LhsContext* projectExprParser::StmtContext::lhs() {
  return getRuleContext<projectExprParser::LhsContext>(0);
}

projectExprParser::RhsEContext* projectExprParser::StmtContext::rhsE() {
  return getRuleContext<projectExprParser::RhsEContext>(0);
}


size_t projectExprParser::StmtContext::getRuleIndex() const {
  return projectExprParser::RuleStmt;
}

void projectExprParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void projectExprParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}


antlrcpp::Any projectExprParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<projectExprVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

projectExprParser::StmtContext* projectExprParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 6, projectExprParser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(51);
    lhs();
    setState(52);
    match(projectExprParser::T__0);
    setState(53);
    rhsE();
    setState(54);
    match(projectExprParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LhsContext ------------------------------------------------------------------

projectExprParser::LhsContext::LhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

projectExprParser::TRefContext* projectExprParser::LhsContext::tRef() {
  return getRuleContext<projectExprParser::TRefContext>(0);
}


size_t projectExprParser::LhsContext::getRuleIndex() const {
  return projectExprParser::RuleLhs;
}

void projectExprParser::LhsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLhs(this);
}

void projectExprParser::LhsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLhs(this);
}


antlrcpp::Any projectExprParser::LhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<projectExprVisitor*>(visitor))
    return parserVisitor->visitLhs(this);
  else
    return visitor->visitChildren(this);
}

projectExprParser::LhsContext* projectExprParser::lhs() {
  LhsContext *_localctx = _tracker.createInstance<LhsContext>(_ctx, getState());
  enterRule(_localctx, 8, projectExprParser::RuleLhs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(56);
    tRef();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RhsEContext ------------------------------------------------------------------

projectExprParser::RhsEContext::RhsEContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

projectExprParser::RhsIContext* projectExprParser::RhsEContext::rhsI() {
  return getRuleContext<projectExprParser::RhsIContext>(0);
}

projectExprParser::RhsERContext* projectExprParser::RhsEContext::rhsER() {
  return getRuleContext<projectExprParser::RhsERContext>(0);
}


size_t projectExprParser::RhsEContext::getRuleIndex() const {
  return projectExprParser::RuleRhsE;
}

void projectExprParser::RhsEContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRhsE(this);
}

void projectExprParser::RhsEContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRhsE(this);
}


antlrcpp::Any projectExprParser::RhsEContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<projectExprVisitor*>(visitor))
    return parserVisitor->visitRhsE(this);
  else
    return visitor->visitChildren(this);
}

projectExprParser::RhsEContext* projectExprParser::rhsE() {
  RhsEContext *_localctx = _tracker.createInstance<RhsEContext>(_ctx, getState());
  enterRule(_localctx, 10, projectExprParser::RuleRhsE);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
    rhsI();
    setState(59);
    rhsER();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RhsERContext ------------------------------------------------------------------

projectExprParser::RhsERContext::RhsERContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

projectExprParser::RhsEContext* projectExprParser::RhsERContext::rhsE() {
  return getRuleContext<projectExprParser::RhsEContext>(0);
}


size_t projectExprParser::RhsERContext::getRuleIndex() const {
  return projectExprParser::RuleRhsER;
}

void projectExprParser::RhsERContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRhsER(this);
}

void projectExprParser::RhsERContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRhsER(this);
}


antlrcpp::Any projectExprParser::RhsERContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<projectExprVisitor*>(visitor))
    return parserVisitor->visitRhsER(this);
  else
    return visitor->visitChildren(this);
}

projectExprParser::RhsERContext* projectExprParser::rhsER() {
  RhsERContext *_localctx = _tracker.createInstance<RhsERContext>(_ctx, getState());
  enterRule(_localctx, 12, projectExprParser::RuleRhsER);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(66);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case projectExprParser::T__2: {
        enterOuterAlt(_localctx, 1);
        setState(61);
        match(projectExprParser::T__2);
        setState(62);
        rhsE();
        break;
      }

      case projectExprParser::T__3: {
        enterOuterAlt(_localctx, 2);
        setState(63);
        match(projectExprParser::T__3);
        setState(64);
        rhsE();
        break;
      }

      case projectExprParser::T__1:
      case projectExprParser::T__5: {
        enterOuterAlt(_localctx, 3);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RhsIContext ------------------------------------------------------------------

projectExprParser::RhsIContext::RhsIContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

projectExprParser::RhsEContext* projectExprParser::RhsIContext::rhsE() {
  return getRuleContext<projectExprParser::RhsEContext>(0);
}

projectExprParser::RhsIRContext* projectExprParser::RhsIContext::rhsIR() {
  return getRuleContext<projectExprParser::RhsIRContext>(0);
}

projectExprParser::TRefContext* projectExprParser::RhsIContext::tRef() {
  return getRuleContext<projectExprParser::TRefContext>(0);
}

projectExprParser::SRefContext* projectExprParser::RhsIContext::sRef() {
  return getRuleContext<projectExprParser::SRefContext>(0);
}

projectExprParser::ConValContext* projectExprParser::RhsIContext::conVal() {
  return getRuleContext<projectExprParser::ConValContext>(0);
}


size_t projectExprParser::RhsIContext::getRuleIndex() const {
  return projectExprParser::RuleRhsI;
}

void projectExprParser::RhsIContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRhsI(this);
}

void projectExprParser::RhsIContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRhsI(this);
}


antlrcpp::Any projectExprParser::RhsIContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<projectExprVisitor*>(visitor))
    return parserVisitor->visitRhsI(this);
  else
    return visitor->visitChildren(this);
}

projectExprParser::RhsIContext* projectExprParser::rhsI() {
  RhsIContext *_localctx = _tracker.createInstance<RhsIContext>(_ctx, getState());
  enterRule(_localctx, 14, projectExprParser::RuleRhsI);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(82);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(68);
      match(projectExprParser::T__4);
      setState(69);
      rhsE();
      setState(70);
      match(projectExprParser::T__5);
      setState(71);
      rhsIR();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(73);
      tRef();
      setState(74);
      rhsIR();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(76);
      sRef();
      setState(77);
      rhsIR();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(79);
      conVal();
      setState(80);
      rhsIR();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RhsIRContext ------------------------------------------------------------------

projectExprParser::RhsIRContext::RhsIRContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

projectExprParser::RhsIContext* projectExprParser::RhsIRContext::rhsI() {
  return getRuleContext<projectExprParser::RhsIContext>(0);
}


size_t projectExprParser::RhsIRContext::getRuleIndex() const {
  return projectExprParser::RuleRhsIR;
}

void projectExprParser::RhsIRContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRhsIR(this);
}

void projectExprParser::RhsIRContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRhsIR(this);
}


antlrcpp::Any projectExprParser::RhsIRContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<projectExprVisitor*>(visitor))
    return parserVisitor->visitRhsIR(this);
  else
    return visitor->visitChildren(this);
}

projectExprParser::RhsIRContext* projectExprParser::rhsIR() {
  RhsIRContext *_localctx = _tracker.createInstance<RhsIRContext>(_ctx, getState());
  enterRule(_localctx, 16, projectExprParser::RuleRhsIR);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(93);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case projectExprParser::T__6: {
        enterOuterAlt(_localctx, 1);
        setState(84);
        match(projectExprParser::T__6);
        setState(85);
        rhsI();
        break;
      }

      case projectExprParser::T__7: {
        enterOuterAlt(_localctx, 2);
        setState(86);
        match(projectExprParser::T__7);
        setState(87);
        rhsI();
        break;
      }

      case projectExprParser::T__8: {
        enterOuterAlt(_localctx, 3);
        setState(88);
        match(projectExprParser::T__8);
        setState(89);
        rhsI();
        break;
      }

      case projectExprParser::T__9: {
        enterOuterAlt(_localctx, 4);
        setState(90);
        match(projectExprParser::T__9);
        setState(91);
        rhsI();
        break;
      }

      case projectExprParser::T__1:
      case projectExprParser::T__2:
      case projectExprParser::T__3:
      case projectExprParser::T__5: {
        enterOuterAlt(_localctx, 5);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TRefContext ------------------------------------------------------------------

projectExprParser::TRefContext::TRefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* projectExprParser::TRefContext::ID() {
  return getToken(projectExprParser::ID, 0);
}

projectExprParser::CListContext* projectExprParser::TRefContext::cList() {
  return getRuleContext<projectExprParser::CListContext>(0);
}

projectExprParser::AListContext* projectExprParser::TRefContext::aList() {
  return getRuleContext<projectExprParser::AListContext>(0);
}


size_t projectExprParser::TRefContext::getRuleIndex() const {
  return projectExprParser::RuleTRef;
}

void projectExprParser::TRefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTRef(this);
}

void projectExprParser::TRefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTRef(this);
}


antlrcpp::Any projectExprParser::TRefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<projectExprVisitor*>(visitor))
    return parserVisitor->visitTRef(this);
  else
    return visitor->visitChildren(this);
}

projectExprParser::TRefContext* projectExprParser::tRef() {
  TRefContext *_localctx = _tracker.createInstance<TRefContext>(_ctx, getState());
  enterRule(_localctx, 18, projectExprParser::RuleTRef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    match(projectExprParser::ID);
    setState(96);
    match(projectExprParser::T__10);
    setState(97);
    cList();
    setState(98);
    match(projectExprParser::T__11);
    setState(99);
    match(projectExprParser::T__12);
    setState(100);
    aList();
    setState(101);
    match(projectExprParser::T__13);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SRefContext ------------------------------------------------------------------

projectExprParser::SRefContext::SRefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* projectExprParser::SRefContext::ID() {
  return getToken(projectExprParser::ID, 0);
}

projectExprParser::CListContext* projectExprParser::SRefContext::cList() {
  return getRuleContext<projectExprParser::CListContext>(0);
}


size_t projectExprParser::SRefContext::getRuleIndex() const {
  return projectExprParser::RuleSRef;
}

void projectExprParser::SRefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSRef(this);
}

void projectExprParser::SRefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSRef(this);
}


antlrcpp::Any projectExprParser::SRefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<projectExprVisitor*>(visitor))
    return parserVisitor->visitSRef(this);
  else
    return visitor->visitChildren(this);
}

projectExprParser::SRefContext* projectExprParser::sRef() {
  SRefContext *_localctx = _tracker.createInstance<SRefContext>(_ctx, getState());
  enterRule(_localctx, 20, projectExprParser::RuleSRef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(103);
    match(projectExprParser::ID);
    setState(104);
    match(projectExprParser::T__10);
    setState(105);
    cList();
    setState(106);
    match(projectExprParser::T__11);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CListContext ------------------------------------------------------------------

projectExprParser::CListContext::CListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* projectExprParser::CListContext::IntV() {
  return getToken(projectExprParser::IntV, 0);
}

projectExprParser::CListRContext* projectExprParser::CListContext::cListR() {
  return getRuleContext<projectExprParser::CListRContext>(0);
}


size_t projectExprParser::CListContext::getRuleIndex() const {
  return projectExprParser::RuleCList;
}

void projectExprParser::CListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCList(this);
}

void projectExprParser::CListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCList(this);
}


antlrcpp::Any projectExprParser::CListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<projectExprVisitor*>(visitor))
    return parserVisitor->visitCList(this);
  else
    return visitor->visitChildren(this);
}

projectExprParser::CListContext* projectExprParser::cList() {
  CListContext *_localctx = _tracker.createInstance<CListContext>(_ctx, getState());
  enterRule(_localctx, 22, projectExprParser::RuleCList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    match(projectExprParser::IntV);
    setState(109);
    cListR();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CListRContext ------------------------------------------------------------------

projectExprParser::CListRContext::CListRContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* projectExprParser::CListRContext::IntV() {
  return getToken(projectExprParser::IntV, 0);
}

projectExprParser::CListRContext* projectExprParser::CListRContext::cListR() {
  return getRuleContext<projectExprParser::CListRContext>(0);
}


size_t projectExprParser::CListRContext::getRuleIndex() const {
  return projectExprParser::RuleCListR;
}

void projectExprParser::CListRContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCListR(this);
}

void projectExprParser::CListRContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCListR(this);
}


antlrcpp::Any projectExprParser::CListRContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<projectExprVisitor*>(visitor))
    return parserVisitor->visitCListR(this);
  else
    return visitor->visitChildren(this);
}

projectExprParser::CListRContext* projectExprParser::cListR() {
  CListRContext *_localctx = _tracker.createInstance<CListRContext>(_ctx, getState());
  enterRule(_localctx, 24, projectExprParser::RuleCListR);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(115);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case projectExprParser::T__14: {
        enterOuterAlt(_localctx, 1);
        setState(111);
        match(projectExprParser::T__14);
        setState(112);
        match(projectExprParser::IntV);
        setState(113);
        cListR();
        break;
      }

      case projectExprParser::T__11: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AListContext ------------------------------------------------------------------

projectExprParser::AListContext::AListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

projectExprParser::IdExprEContext* projectExprParser::AListContext::idExprE() {
  return getRuleContext<projectExprParser::IdExprEContext>(0);
}

projectExprParser::AListRContext* projectExprParser::AListContext::aListR() {
  return getRuleContext<projectExprParser::AListRContext>(0);
}


size_t projectExprParser::AListContext::getRuleIndex() const {
  return projectExprParser::RuleAList;
}

void projectExprParser::AListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAList(this);
}

void projectExprParser::AListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAList(this);
}


antlrcpp::Any projectExprParser::AListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<projectExprVisitor*>(visitor))
    return parserVisitor->visitAList(this);
  else
    return visitor->visitChildren(this);
}

projectExprParser::AListContext* projectExprParser::aList() {
  AListContext *_localctx = _tracker.createInstance<AListContext>(_ctx, getState());
  enterRule(_localctx, 26, projectExprParser::RuleAList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(117);
    idExprE();
    setState(118);
    aListR();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AListRContext ------------------------------------------------------------------

projectExprParser::AListRContext::AListRContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

projectExprParser::IdExprEContext* projectExprParser::AListRContext::idExprE() {
  return getRuleContext<projectExprParser::IdExprEContext>(0);
}

projectExprParser::AListRContext* projectExprParser::AListRContext::aListR() {
  return getRuleContext<projectExprParser::AListRContext>(0);
}


size_t projectExprParser::AListRContext::getRuleIndex() const {
  return projectExprParser::RuleAListR;
}

void projectExprParser::AListRContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAListR(this);
}

void projectExprParser::AListRContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAListR(this);
}


antlrcpp::Any projectExprParser::AListRContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<projectExprVisitor*>(visitor))
    return parserVisitor->visitAListR(this);
  else
    return visitor->visitChildren(this);
}

projectExprParser::AListRContext* projectExprParser::aListR() {
  AListRContext *_localctx = _tracker.createInstance<AListRContext>(_ctx, getState());
  enterRule(_localctx, 28, projectExprParser::RuleAListR);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(125);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case projectExprParser::T__14: {
        enterOuterAlt(_localctx, 1);
        setState(120);
        match(projectExprParser::T__14);
        setState(121);
        idExprE();
        setState(122);
        aListR();
        break;
      }

      case projectExprParser::T__13: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdExprEContext ------------------------------------------------------------------

projectExprParser::IdExprEContext::IdExprEContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

projectExprParser::IdExprIContext* projectExprParser::IdExprEContext::idExprI() {
  return getRuleContext<projectExprParser::IdExprIContext>(0);
}

projectExprParser::IdExprERContext* projectExprParser::IdExprEContext::idExprER() {
  return getRuleContext<projectExprParser::IdExprERContext>(0);
}


size_t projectExprParser::IdExprEContext::getRuleIndex() const {
  return projectExprParser::RuleIdExprE;
}

void projectExprParser::IdExprEContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdExprE(this);
}

void projectExprParser::IdExprEContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdExprE(this);
}


antlrcpp::Any projectExprParser::IdExprEContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<projectExprVisitor*>(visitor))
    return parserVisitor->visitIdExprE(this);
  else
    return visitor->visitChildren(this);
}

projectExprParser::IdExprEContext* projectExprParser::idExprE() {
  IdExprEContext *_localctx = _tracker.createInstance<IdExprEContext>(_ctx, getState());
  enterRule(_localctx, 30, projectExprParser::RuleIdExprE);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    idExprI();
    setState(128);
    idExprER();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdExprERContext ------------------------------------------------------------------

projectExprParser::IdExprERContext::IdExprERContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

projectExprParser::IdExprEContext* projectExprParser::IdExprERContext::idExprE() {
  return getRuleContext<projectExprParser::IdExprEContext>(0);
}


size_t projectExprParser::IdExprERContext::getRuleIndex() const {
  return projectExprParser::RuleIdExprER;
}

void projectExprParser::IdExprERContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdExprER(this);
}

void projectExprParser::IdExprERContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdExprER(this);
}


antlrcpp::Any projectExprParser::IdExprERContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<projectExprVisitor*>(visitor))
    return parserVisitor->visitIdExprER(this);
  else
    return visitor->visitChildren(this);
}

projectExprParser::IdExprERContext* projectExprParser::idExprER() {
  IdExprERContext *_localctx = _tracker.createInstance<IdExprERContext>(_ctx, getState());
  enterRule(_localctx, 32, projectExprParser::RuleIdExprER);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(135);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case projectExprParser::T__2: {
        enterOuterAlt(_localctx, 1);
        setState(130);
        match(projectExprParser::T__2);
        setState(131);
        idExprE();
        break;
      }

      case projectExprParser::T__3: {
        enterOuterAlt(_localctx, 2);
        setState(132);
        match(projectExprParser::T__3);
        setState(133);
        idExprE();
        break;
      }

      case projectExprParser::T__5:
      case projectExprParser::T__13:
      case projectExprParser::T__14: {
        enterOuterAlt(_localctx, 3);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdExprIContext ------------------------------------------------------------------

projectExprParser::IdExprIContext::IdExprIContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* projectExprParser::IdExprIContext::ID() {
  return getToken(projectExprParser::ID, 0);
}

projectExprParser::IdExprIRContext* projectExprParser::IdExprIContext::idExprIR() {
  return getRuleContext<projectExprParser::IdExprIRContext>(0);
}

projectExprParser::IdExprEContext* projectExprParser::IdExprIContext::idExprE() {
  return getRuleContext<projectExprParser::IdExprEContext>(0);
}

tree::TerminalNode* projectExprParser::IdExprIContext::IntV() {
  return getToken(projectExprParser::IntV, 0);
}


size_t projectExprParser::IdExprIContext::getRuleIndex() const {
  return projectExprParser::RuleIdExprI;
}

void projectExprParser::IdExprIContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdExprI(this);
}

void projectExprParser::IdExprIContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdExprI(this);
}


antlrcpp::Any projectExprParser::IdExprIContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<projectExprVisitor*>(visitor))
    return parserVisitor->visitIdExprI(this);
  else
    return visitor->visitChildren(this);
}

projectExprParser::IdExprIContext* projectExprParser::idExprI() {
  IdExprIContext *_localctx = _tracker.createInstance<IdExprIContext>(_ctx, getState());
  enterRule(_localctx, 34, projectExprParser::RuleIdExprI);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(146);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case projectExprParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(137);
        match(projectExprParser::ID);
        setState(138);
        idExprIR();
        break;
      }

      case projectExprParser::T__4: {
        enterOuterAlt(_localctx, 2);
        setState(139);
        match(projectExprParser::T__4);
        setState(140);
        idExprE();
        setState(141);
        match(projectExprParser::T__5);
        setState(142);
        idExprIR();
        break;
      }

      case projectExprParser::IntV: {
        enterOuterAlt(_localctx, 3);
        setState(144);
        match(projectExprParser::IntV);
        setState(145);
        idExprIR();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdExprIRContext ------------------------------------------------------------------

projectExprParser::IdExprIRContext::IdExprIRContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

projectExprParser::IdExprIContext* projectExprParser::IdExprIRContext::idExprI() {
  return getRuleContext<projectExprParser::IdExprIContext>(0);
}


size_t projectExprParser::IdExprIRContext::getRuleIndex() const {
  return projectExprParser::RuleIdExprIR;
}

void projectExprParser::IdExprIRContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdExprIR(this);
}

void projectExprParser::IdExprIRContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdExprIR(this);
}


antlrcpp::Any projectExprParser::IdExprIRContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<projectExprVisitor*>(visitor))
    return parserVisitor->visitIdExprIR(this);
  else
    return visitor->visitChildren(this);
}

projectExprParser::IdExprIRContext* projectExprParser::idExprIR() {
  IdExprIRContext *_localctx = _tracker.createInstance<IdExprIRContext>(_ctx, getState());
  enterRule(_localctx, 36, projectExprParser::RuleIdExprIR);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(155);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case projectExprParser::T__6: {
        enterOuterAlt(_localctx, 1);
        setState(148);
        match(projectExprParser::T__6);
        setState(149);
        idExprI();
        break;
      }

      case projectExprParser::T__9: {
        enterOuterAlt(_localctx, 2);
        setState(150);
        match(projectExprParser::T__9);
        setState(151);
        idExprI();
        break;
      }

      case projectExprParser::T__8: {
        enterOuterAlt(_localctx, 3);
        setState(152);
        match(projectExprParser::T__8);
        setState(153);
        idExprI();
        break;
      }

      case projectExprParser::T__2:
      case projectExprParser::T__3:
      case projectExprParser::T__5:
      case projectExprParser::T__13:
      case projectExprParser::T__14: {
        enterOuterAlt(_localctx, 4);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConValContext ------------------------------------------------------------------

projectExprParser::ConValContext::ConValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* projectExprParser::ConValContext::FloatV() {
  return getToken(projectExprParser::FloatV, 0);
}

tree::TerminalNode* projectExprParser::ConValContext::IntV() {
  return getToken(projectExprParser::IntV, 0);
}


size_t projectExprParser::ConValContext::getRuleIndex() const {
  return projectExprParser::RuleConVal;
}

void projectExprParser::ConValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConVal(this);
}

void projectExprParser::ConValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<projectExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConVal(this);
}


antlrcpp::Any projectExprParser::ConValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<projectExprVisitor*>(visitor))
    return parserVisitor->visitConVal(this);
  else
    return visitor->visitChildren(this);
}

projectExprParser::ConValContext* projectExprParser::conVal() {
  ConValContext *_localctx = _tracker.createInstance<ConValContext>(_ctx, getState());
  enterRule(_localctx, 38, projectExprParser::RuleConVal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    _la = _input->LA(1);
    if (!(_la == projectExprParser::IntV

    || _la == projectExprParser::FloatV)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> projectExprParser::_decisionToDFA;
atn::PredictionContextCache projectExprParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN projectExprParser::_atn;
std::vector<uint16_t> projectExprParser::_serializedATN;

std::vector<std::string> projectExprParser::_ruleNames = {
  "prog", "pBegin", "pBeginR", "stmt", "lhs", "rhsE", "rhsER", "rhsI", "rhsIR", 
  "tRef", "sRef", "cList", "cListR", "aList", "aListR", "idExprE", "idExprER", 
  "idExprI", "idExprIR", "conVal"
};

std::vector<std::string> projectExprParser::_literalNames = {
  "", "'='", "';'", "'+'", "'-'", "'('", "')'", "'*'", "'/'", "'%'", "'//'", 
  "'<'", "'>'", "'['", "']'", "','"
};

std::vector<std::string> projectExprParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "IntV", 
  "FloatV", "WS", "ID"
};

dfa::Vocabulary projectExprParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> projectExprParser::_tokenNames;

projectExprParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x15, 0xa2, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x34, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 
    0x45, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x5, 0x9, 0x55, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 
    0x60, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x5, 0xe, 0x76, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x80, 0xa, 0x10, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x5, 0x12, 0x8a, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x5, 0x13, 0x95, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x9e, 0xa, 0x14, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x2, 0x2, 0x16, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
    0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 
    0x26, 0x28, 0x2, 0x3, 0x3, 0x2, 0x12, 0x13, 0x2, 0xa0, 0x2, 0x2a, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x6, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0x35, 0x3, 0x2, 0x2, 0x2, 0xa, 0x3a, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0x3c, 0x3, 0x2, 0x2, 0x2, 0xe, 0x44, 0x3, 0x2, 0x2, 0x2, 0x10, 0x54, 
    0x3, 0x2, 0x2, 0x2, 0x12, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x14, 0x61, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0x69, 0x3, 0x2, 0x2, 0x2, 0x18, 0x6e, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0x75, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x77, 0x3, 0x2, 0x2, 
    0x2, 0x1e, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x20, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x22, 0x89, 0x3, 0x2, 0x2, 0x2, 0x24, 0x94, 0x3, 0x2, 0x2, 0x2, 0x26, 
    0x9d, 0x3, 0x2, 0x2, 0x2, 0x28, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 
    0x5, 0x4, 0x3, 0x2, 0x2b, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x5, 
    0x8, 0x5, 0x2, 0x2d, 0x2e, 0x5, 0x6, 0x4, 0x2, 0x2e, 0x5, 0x3, 0x2, 
    0x2, 0x2, 0x2f, 0x30, 0x5, 0x8, 0x5, 0x2, 0x30, 0x31, 0x5, 0x6, 0x4, 
    0x2, 0x31, 0x34, 0x3, 0x2, 0x2, 0x2, 0x32, 0x34, 0x3, 0x2, 0x2, 0x2, 
    0x33, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x33, 0x32, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x7, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x5, 0xa, 0x6, 0x2, 0x36, 0x37, 
    0x7, 0x3, 0x2, 0x2, 0x37, 0x38, 0x5, 0xc, 0x7, 0x2, 0x38, 0x39, 0x7, 
    0x4, 0x2, 0x2, 0x39, 0x9, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x5, 0x14, 
    0xb, 0x2, 0x3b, 0xb, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x5, 0x10, 0x9, 
    0x2, 0x3d, 0x3e, 0x5, 0xe, 0x8, 0x2, 0x3e, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0x3f, 0x40, 0x7, 0x5, 0x2, 0x2, 0x40, 0x45, 0x5, 0xc, 0x7, 0x2, 0x41, 
    0x42, 0x7, 0x6, 0x2, 0x2, 0x42, 0x45, 0x5, 0xc, 0x7, 0x2, 0x43, 0x45, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x44, 0x41, 0x3, 
    0x2, 0x2, 0x2, 0x44, 0x43, 0x3, 0x2, 0x2, 0x2, 0x45, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x46, 0x47, 0x7, 0x7, 0x2, 0x2, 0x47, 0x48, 0x5, 0xc, 0x7, 
    0x2, 0x48, 0x49, 0x7, 0x8, 0x2, 0x2, 0x49, 0x4a, 0x5, 0x12, 0xa, 0x2, 
    0x4a, 0x55, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x5, 0x14, 0xb, 0x2, 0x4c, 
    0x4d, 0x5, 0x12, 0xa, 0x2, 0x4d, 0x55, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 
    0x5, 0x16, 0xc, 0x2, 0x4f, 0x50, 0x5, 0x12, 0xa, 0x2, 0x50, 0x55, 0x3, 
    0x2, 0x2, 0x2, 0x51, 0x52, 0x5, 0x28, 0x15, 0x2, 0x52, 0x53, 0x5, 0x12, 
    0xa, 0x2, 0x53, 0x55, 0x3, 0x2, 0x2, 0x2, 0x54, 0x46, 0x3, 0x2, 0x2, 
    0x2, 0x54, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x54, 0x4e, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x51, 0x3, 0x2, 0x2, 0x2, 0x55, 0x11, 0x3, 0x2, 0x2, 0x2, 0x56, 
    0x57, 0x7, 0x9, 0x2, 0x2, 0x57, 0x60, 0x5, 0x10, 0x9, 0x2, 0x58, 0x59, 
    0x7, 0xa, 0x2, 0x2, 0x59, 0x60, 0x5, 0x10, 0x9, 0x2, 0x5a, 0x5b, 0x7, 
    0xb, 0x2, 0x2, 0x5b, 0x60, 0x5, 0x10, 0x9, 0x2, 0x5c, 0x5d, 0x7, 0xc, 
    0x2, 0x2, 0x5d, 0x60, 0x5, 0x10, 0x9, 0x2, 0x5e, 0x60, 0x3, 0x2, 0x2, 
    0x2, 0x5f, 0x56, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x58, 0x3, 0x2, 0x2, 0x2, 
    0x5f, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5f, 
    0x5e, 0x3, 0x2, 0x2, 0x2, 0x60, 0x13, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 
    0x7, 0x15, 0x2, 0x2, 0x62, 0x63, 0x7, 0xd, 0x2, 0x2, 0x63, 0x64, 0x5, 
    0x18, 0xd, 0x2, 0x64, 0x65, 0x7, 0xe, 0x2, 0x2, 0x65, 0x66, 0x7, 0xf, 
    0x2, 0x2, 0x66, 0x67, 0x5, 0x1c, 0xf, 0x2, 0x67, 0x68, 0x7, 0x10, 0x2, 
    0x2, 0x68, 0x15, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x7, 0x15, 0x2, 0x2, 
    0x6a, 0x6b, 0x7, 0xd, 0x2, 0x2, 0x6b, 0x6c, 0x5, 0x18, 0xd, 0x2, 0x6c, 
    0x6d, 0x7, 0xe, 0x2, 0x2, 0x6d, 0x17, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 
    0x7, 0x12, 0x2, 0x2, 0x6f, 0x70, 0x5, 0x1a, 0xe, 0x2, 0x70, 0x19, 0x3, 
    0x2, 0x2, 0x2, 0x71, 0x72, 0x7, 0x11, 0x2, 0x2, 0x72, 0x73, 0x7, 0x12, 
    0x2, 0x2, 0x73, 0x76, 0x5, 0x1a, 0xe, 0x2, 0x74, 0x76, 0x3, 0x2, 0x2, 
    0x2, 0x75, 0x71, 0x3, 0x2, 0x2, 0x2, 0x75, 0x74, 0x3, 0x2, 0x2, 0x2, 
    0x76, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x5, 0x20, 0x11, 0x2, 0x78, 
    0x79, 0x5, 0x1e, 0x10, 0x2, 0x79, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 
    0x7, 0x11, 0x2, 0x2, 0x7b, 0x7c, 0x5, 0x20, 0x11, 0x2, 0x7c, 0x7d, 0x5, 
    0x1e, 0x10, 0x2, 0x7d, 0x80, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x80, 0x3, 0x2, 
    0x2, 0x2, 0x7f, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7e, 0x3, 0x2, 0x2, 
    0x2, 0x80, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x5, 0x24, 0x13, 0x2, 
    0x82, 0x83, 0x5, 0x22, 0x12, 0x2, 0x83, 0x21, 0x3, 0x2, 0x2, 0x2, 0x84, 
    0x85, 0x7, 0x5, 0x2, 0x2, 0x85, 0x8a, 0x5, 0x20, 0x11, 0x2, 0x86, 0x87, 
    0x7, 0x6, 0x2, 0x2, 0x87, 0x8a, 0x5, 0x20, 0x11, 0x2, 0x88, 0x8a, 0x3, 
    0x2, 0x2, 0x2, 0x89, 0x84, 0x3, 0x2, 0x2, 0x2, 0x89, 0x86, 0x3, 0x2, 
    0x2, 0x2, 0x89, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0x8b, 0x8c, 0x7, 0x15, 0x2, 0x2, 0x8c, 0x95, 0x5, 0x26, 0x14, 0x2, 
    0x8d, 0x8e, 0x7, 0x7, 0x2, 0x2, 0x8e, 0x8f, 0x5, 0x20, 0x11, 0x2, 0x8f, 
    0x90, 0x7, 0x8, 0x2, 0x2, 0x90, 0x91, 0x5, 0x26, 0x14, 0x2, 0x91, 0x95, 
    0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x7, 0x12, 0x2, 0x2, 0x93, 0x95, 0x5, 
    0x26, 0x14, 0x2, 0x94, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x94, 0x8d, 0x3, 0x2, 
    0x2, 0x2, 0x94, 0x92, 0x3, 0x2, 0x2, 0x2, 0x95, 0x25, 0x3, 0x2, 0x2, 
    0x2, 0x96, 0x97, 0x7, 0x9, 0x2, 0x2, 0x97, 0x9e, 0x5, 0x24, 0x13, 0x2, 
    0x98, 0x99, 0x7, 0xc, 0x2, 0x2, 0x99, 0x9e, 0x5, 0x24, 0x13, 0x2, 0x9a, 
    0x9b, 0x7, 0xb, 0x2, 0x2, 0x9b, 0x9e, 0x5, 0x24, 0x13, 0x2, 0x9c, 0x9e, 
    0x3, 0x2, 0x2, 0x2, 0x9d, 0x96, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x98, 0x3, 
    0x2, 0x2, 0x2, 0x9d, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9c, 0x3, 0x2, 
    0x2, 0x2, 0x9e, 0x27, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x9, 0x2, 0x2, 
    0x2, 0xa0, 0x29, 0x3, 0x2, 0x2, 0x2, 0xb, 0x33, 0x44, 0x54, 0x5f, 0x75, 
    0x7f, 0x89, 0x94, 0x9d, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

projectExprParser::Initializer projectExprParser::_init;

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

class indexCollectVisitor : public projectExprVisitor {
public:
    Boost::Internal::Type index_type; // always int_scalar;
    // `indexes` is the target value. Each stmt means a map from index(std::string) to an `Index` type.
    std::vector<std::map<std::string, Boost::Internal::Expr> > indexes;

    // Temp values to build indexes
    std::vector<int> bounds;
    std::vector<std::string> names;
    std::map<std::string, Boost::Internal::Expr> tmpMap;

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
        // std:: cout << tmpMap.size();
        // for (auto it = tmpMap.begin(); it!=tmpMap.end(); it++) {
        //   std::cout << it->first << ' '  << '\n';
        // }
        indexes.push_back(tmpMap);
        tmpMap.clear();
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
        size_t n = names.size();
        for (size_t i = 0; i < n; i++) {
            auto it = tmpMap.find(names[i]);
            if (it != tmpMap.end()) {
                int v = (it->second).as<Index>()->dom.as<Dom>()->extent.as<IntImm>()->value();    
                if (v > bounds[i]) {
                    Boost::Internal::Expr dom =
                        Boost::Internal::Dom::make(index_type, 0, bounds[i]);
                    Boost::Internal::Expr idx =
                            Boost::Internal::Index::make(index_type, names[i], dom,
                        Boost::Internal::IndexType::Spatial);
                    tmpMap[names[i]] = idx;
                }
                continue;
            }
            // std::cout << names[i] << ' ' << bounds[i] << '\n';
            Boost::Internal::Expr dom =
                    Boost::Internal::Dom::make(index_type, 0, bounds[i]);
            Boost::Internal::Expr idx =
                    Boost::Internal::Index::make(index_type, names[i], dom,
            	Boost::Internal::IndexType::Spatial);
            tmpMap.insert(std::pair<std::string, Boost::Internal::Expr>(names[i], idx));
        }
        names.clear();
        bounds.clear();
        return NULL;
    }

    antlrcpp::Any visitSRef(projectExprParser::SRefContext *ctx) override {
        visitChildren(ctx);
        bounds.clear();
        return NULL;
    }

    antlrcpp::Any visitCList(projectExprParser::CListContext *ctx) override {
        std::string tmp = ctx->IntV()->getText();
        int num = std::stoi(tmp);
        bounds.push_back(num);
        return visitChildren(ctx);
    }

    antlrcpp::Any visitCListR(projectExprParser::CListRContext *ctx) override {
        size_t n = ctx->children.size();
        if (n > 0) {
            std::string tmp = ctx->IntV()->getText();
            int num = std::stoi(tmp);
            bounds.push_back(num);
        }
        return visitChildren(ctx);
    }

    antlrcpp::Any visitAList(projectExprParser::AListContext *ctx) override {
        std::string tmp = ctx->children[0]->accept(this);
        names.push_back(tmp);
        return visitChildren(ctx);
    }

    antlrcpp::Any visitAListR(projectExprParser::AListRContext *ctx) override {
        size_t n = ctx->children.size();
        if (n > 0) {
            std::string tmp = ctx->children[1]->accept(this);
            names.push_back(tmp);
        }
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


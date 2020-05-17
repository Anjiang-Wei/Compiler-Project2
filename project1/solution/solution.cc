#include <fstream>
#include <iostream>
#include <algorithm>
#include <json/json.h>
#include <string>
#include <vector>
#include <exception>
#include <sys/types.h>
#include <dirent.h>
#include "projectExprLexer.h"
#include "projectExprParser.h"
#include "projectExprBaseVisitor.h"
#include "indexCollectVisitor.h"
#include "buildIRVisitor.h"

/* need include ../run.h
 * parameters should be passed as ref
 * inputs are ahead of outputs
 * some questions about reading files
 */
using namespace Boost::Internal;

void generate_codes(const std::string& file_name) {
    std::string in_path = "./cases/" + file_name + ".json";
    std::string out_path;

    //-----------READ json file------------
    std::string input_case, tmp_line;
    std::ifstream ifile(in_path, std::ios::in);
    while (std::getline(ifile, tmp_line)) {
        input_case += tmp_line + '\n';
    }

    //-----------Parse Json File-----------
    // Useful result:
    //      case_name; dtype; kernel; ins; outs; out_path;
    bool res;
    Json::String errs;
    Json::Value root;
    Json::CharReaderBuilder readerBuilder;
    std::string case_name, dtype, kernel;
    std::vector<std::string> ins, outs;
    std::unique_ptr<Json::CharReader> const jsonReader(readerBuilder.newCharReader());
    res = jsonReader->parse(input_case.c_str(), input_case.c_str() + input_case.length(),
                            &root, &errs);
    if (!res || !errs.empty()) {
        std::cout << "\033[31m[ERROR]\033[0mparseJson err. " << errs << std::endl;
    }
    case_name = root["name"].asString();
    dtype = root["data_type"].asString();
    kernel = root["kernel"].asString();
    for (const auto &i : root["ins"]) {
        ins.push_back(i.asString());
    }
    for (const auto &i : root["outs"]) {
        if (std::find(ins.begin(), ins.end(), i.asString()) == ins.end()) // filter repeated names
            outs.push_back(i.asString());
    }
    out_path = "./kernels/" + case_name + ".cc";

    //-----------Use Antlr to Do Lexer and Parser-----------
    // Useful result: prog -- the root of syntax tree;
    //                tokens -- token stream;
    antlr4::ANTLRInputStream input(kernel);
    projectExprLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    projectExprParser parser(&tokens);
    projectExprParser::ProgContext *prog = parser.prog();
    if (parser.getNumberOfSyntaxErrors() > 0) {
        std::cout << "syntax error" << std::endl;
        throw(std::invalid_argument("Syntax parse error"));
    }

    //-----------Use Visitor to Build AST-----------
    // Collect a loose bound;
    indexCollectVisitor dvisitor;
    dvisitor.index_type = Boost::Internal::Type::int_scalar(32);
    dvisitor.visitProg(prog);
    /* [debug] use for print bound table;
    for (const auto & each_item : dvisitor.indexes[0]) {
        std::cout << "Name: " << each_item.first << std::endl;
        std::cout << "Index name: " << each_item.second.as<Index>()->name << std::endl;
        std::cout << "Bound: " << each_item.second.as<Index>()->dom.as<Dom>()->extent.as<IntImm>()->value() << std::endl;
    } */


    // Pass some global value collected from dvisitor(bound collector) to visitor(translator);
    buildIRVistor visitor;
    if (dtype == "float")
        visitor.data_type = Boost::Internal::Type::float_scalar(32);
    else if (dtype == "int")
        visitor.data_type = Boost::Internal::Type::int_scalar(32);
    visitor.indexes = dvisitor.indexes;
    visitor.index_type = Boost::Internal::Type::int_scalar(32);

    // Start to build IR tree;
    visitor.visitProg(prog);

    // Build inputs and outputs
    std::vector<Expr> inputs;
    std::vector<Expr> outputs;
    size_t n = ins.size();
    for (size_t i = 0; i < n; i++) {
        auto it = visitor.vars.find(ins[i]);
        if (it != visitor.vars.end())
            inputs.push_back(it->second);
    }
    n = outs.size();
    for (size_t i = 0; i < n; i++) {
        auto it = visitor.vars.find(outs[i]);
        if (it != visitor.vars.end())
            outputs.push_back(it->second);
    }

    // Get the root node of IR tree and generate Cpp code to `out_path`;
    Boost::Internal::Group kernels =
            Boost::Internal::Kernel::make(case_name, inputs, outputs,visitor.kernel_stmts,
                    Boost::Internal::KernelType::CPU);
    Boost::Internal::IRPrinter printer;
    std::string code = printer.print(kernels);
    // std::cout << code << '\n';
    std::ofstream ofile(out_path, std::ios::out);
    ofile << "#include \"../run.h\"\n\n";
    ofile << code;
}

void get_files(std::vector<std::string>& files) {
    /* Get all the files in `cases/`, and store them into `files`;
     * */
    DIR* dirptr = opendir("./cases");
    struct dirent * dp;
    while ((dp = readdir(dirptr)) != nullptr) {
        if (dp->d_name[0] == '.') continue;
        files.emplace_back(dp->d_name);
    }
    closedir(dirptr);
}

int main(int argc, const char *argv[]) {
    /* TODO:
     *   1. Bound inference can be done in the first pass;
     *   2. Find a better way to generate tmp declaration;
     * */
    std::vector<std::string> file_names;
    get_files(file_names);
    for (const auto & file_name: file_names) {
        std::string case_name = file_name.substr(0, file_name.length() - 5);
        generate_codes(case_name);
    }
    return 0;
}

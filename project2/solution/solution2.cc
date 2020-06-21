#include <iostream>
#include <string>
#include <json/json.h>
#include <vector>
#include <dirent.h>
#include "projectExprLexer.h"
#include "projectExprParser.h"
#include "projectExprBaseVisitor.h"
#include "indexCollectVisitor.h"
#include "buildIRVisitor.h"
#include "buildSimpleIR.h"
#include "JsonPrinter.h"

void generate_final_code(std::string &kernel, std::vector<std::string> &ins,
                         std::vector<std::string> &outs, std::string &out_path,
                         std::string &dtype, std::string &case_name) {
    antlr4::ANTLRInputStream input(kernel);
    projectExprLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    projectExprParser parser(&tokens);
    projectExprParser::ProgContext *prog = parser.prog();
    if (parser.getNumberOfSyntaxErrors() > 0) {
        std::cout << "syntax error" << std::endl;
        throw (std::invalid_argument("Syntax parse error"));
    }
    indexCollectVisitor dvisitor;
    dvisitor.index_type = Boost::Internal::Type::int_scalar(32);
    dvisitor.visitProg(prog);
    buildIRVistor visitor;
    if (dtype == "float")
        visitor.data_type = Boost::Internal::Type::float_scalar(32);
    else if (dtype == "int")
        visitor.data_type = Boost::Internal::Type::int_scalar(32);
    visitor.indexes = dvisitor.indexes;
    visitor.index_type = Boost::Internal::Type::int_scalar(32);
    visitor.visitProg(prog);
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
    Boost::Internal::Group kernels =
            Boost::Internal::Kernel::make(case_name, inputs, outputs, visitor.kernel_stmts,
                                          Boost::Internal::KernelType::CPU);
    Boost::Internal::IRPrinter printer;
    std::string code = printer.print(kernels);
    std::ofstream ofile(out_path, std::ios::out);
    ofile << "#include \"../run2.h\"\n\n";
    ofile << code;
}

void generate_codes(const std::string &file_name) {
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
    //      case_name; dtype; kernel; ins; outs; out_path; grad_to;
    bool res;
    Json::String errs;
    Json::Value root;
    Json::CharReaderBuilder readerBuilder;
    std::string case_name, dtype, kernel;
    std::vector<std::string> ins, outs, grad_to;
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
        if (std::find(ins.begin(), ins.end(), i.asString()) != ins.end()) {
            // assert this will not happen;
            assert (false);
        }
        outs.push_back(i.asString());
    }
    for (const auto &i : root["grad_to"]) {
        grad_to.push_back(i.asString());
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
        throw (std::invalid_argument("Syntax parse error"));
    }

    indexCollectVisitor dvisitor;
    dvisitor.index_type = Boost::Internal::Type::int_scalar(32);
    dvisitor.visitProg(prog);

    SimpleIRVisitor svisitor;
    svisitor.indexes = dvisitor.indexes;
    if (dtype == "float")
        svisitor.data_type = Boost::Internal::Type::float_scalar(32);
    else if (dtype == "int")
        svisitor.data_type = Boost::Internal::Type::int_scalar(32);
    svisitor.visitProg(prog);
    // Build inputs and outputs
    std::vector<Expr> inputs;
    std::vector<Expr> outputs;
    size_t n = ins.size();
    for (size_t i = 0; i < n; i++) {
        auto it = svisitor.vars.find(ins[i]);
        if (it != svisitor.vars.end())
            inputs.push_back(it->second);
    }
    n = outs.size();
    for (size_t i = 0; i < n; i++) {
        auto it = svisitor.vars.find(outs[i]);
        if (it != svisitor.vars.end())
            outputs.push_back(it->second);
    }
    Boost::Internal::Stmt kernels = svisitor.kernel_stmts[0];
            // Boost::Internal::Kernel::make(case_name, inputs, outputs, svisitor.kernel_stmts,
            //                               Boost::Internal::KernelType::CPU);
    /* [debug] [created by yy]
    std::cout << "\033[31m[DEBUG]\033[0m " << case_name << std::endl;
    Boost::Internal::IRPrinter printer_;
    std::cout << printer_.print(kernels) << std::endl;
     */

    std::string new_kernels;
    for (const auto &grad : grad_to) {
        Boost::Internal::IRMutator mutator;
        Boost::Internal::JsonPrinter printer;
        mutator.grad_to = grad;
        Boost::Internal::Stmt temp_kernel = mutator.mutate(kernels);
        std::string new_kernel = printer.print(temp_kernel);
        new_kernels += new_kernel;
    }
    // std::cout << new_kernels << std::endl;

    // ----------Use Project1 to build the final result----------
    std::vector<std::string> new_ins(ins), new_outs;
    // assert there is only one output in each case, and this out will not be in 'ins'
    assert (outs.size() == 1);
    new_ins.push_back('d' + outs[0]);
    for (const auto &grad : grad_to) {
        new_outs.push_back('d' + grad);
    }
    generate_final_code(new_kernels, new_ins, new_outs, out_path, dtype, case_name);
}

void get_files(std::vector<std::string> &files) {
    /* Get all the files in `cases/`, and store them into `files`;
     * */
    DIR *dirptr = opendir("./cases");
    struct dirent *dp;
    while ((dp = readdir(dirptr)) != nullptr) {
        if (dp->d_name[0] == '.') continue;
        files.emplace_back(dp->d_name);
    }
    closedir(dirptr);
}


int main() {
    std::vector<std::string> file_names;
    get_files(file_names);
    for (const auto &file_name: file_names) {
        std::string case_name = file_name.substr(0, file_name.length() - 5);
        generate_codes(case_name);
    }
    return 0;
}
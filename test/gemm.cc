#include <string>
#include <iostream>

#include "IR.h"
#include "IRMutator.h"
#include "IRVisitor.h"
#include "IRPrinter.h"
#include "type.h"

using namespace Boost::Internal;

int main() {
    const int M = 1024;
    const int N = 512;
    const int K = 256;
    Type index_type = Type::int_scalar(32);
    Type data_type = Type::float_scalar(32);

    // index i
    Expr dom_i = Dom::make(index_type, 0, M);
    Expr i = Index::make(index_type, "i", dom_i, IndexType::Spatial);

    // index j
    Expr dom_j = Dom::make(index_type, 0, N);
    Expr j = Index::make(index_type, "j", dom_j, IndexType::Spatial);

    // index k
    Expr dom_k = Dom::make(index_type, 0, K);
    Expr k = Index::make(index_type, "k", dom_k, IndexType::Reduce);

    // A
    Expr expr_A = Var::make(data_type, "A", {i, k}, {M, K});

    // B
    Expr expr_B = Var::make(data_type, "B", {k, j}, {K, N});

    // C
    Expr expr_C = Var::make(data_type, "C", {i, j}, {M, N});

    Expr expr_D = Var::make(data_type, "D", {i, j}, {M, N});

    // main stmt
    Stmt main_stmt = Move::make(
        expr_D,
        Binary::make(data_type, BinaryOpType::Mul, 
            Binary::make(data_type, BinaryOpType::Mul, expr_A, expr_B),
            expr_C),
        MoveType::MemToMem
    );

    // loop nest
    // Stmt loop_nest = LoopNest::make({i, j, k}, {main_stmt});

    // kernel
    Group kernel = Kernel::make("simple_gemm", {expr_A, expr_B}, {expr_C}, {main_stmt}, KernelType::CPU);

    // visitor
    IRVisitor visitor;
    kernel.visit_group(&visitor);

    // mutator
    IRMutator mutator;
    mutator.grad_to = "A";
    kernel = mutator.mutate(kernel);
    

    // printer
    IRPrinter printer;
    std::string code = printer.print(kernel);

    std::cout << code;
     
    IRPrinter printer1;
    std::cout << printer1.print(mutator.op1_grad) << "\n";

    IRPrinter printer2;
    std::cout << printer2.print(mutator.op2_grad) << "\n";

    std::cout << "Success!\n";
    return 0;
}
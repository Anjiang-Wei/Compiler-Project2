#include <string>
#include <iostream>

#include "IR.h"
#include "IRMutator.h"
#include "IRVisitor.h"
#include "IRPrinter.h"
#include "JsonPrinter.h"
#include "type.h"

using namespace Boost::Internal;

int main() {
    const int M = 16;
    const int N = 32;
    const int K = 4;
    Type index_type = Type::int_scalar(32);
    Type data_type = Type::float_scalar(32);


    // "A<16, 32>[i, j] =  B<16, 32, 4>[i, k, l] * C<32, 32>[k, j] * D<4, 32>[l, j];"

    // index i
    Expr dom_i = Dom::make(index_type, 0, M);
    Expr i = Index::make(index_type, "i", dom_i, IndexType::Spatial);

    // index j
    Expr dom_j = Dom::make(index_type, 0, N);
    Expr j = Index::make(index_type, "j", dom_j, IndexType::Spatial);

    // index k
    Expr dom_k = Dom::make(index_type, 0, N);
    Expr k = Index::make(index_type, "k", dom_k, IndexType::Reduce);

    // index l
    Expr dom_l = Dom::make(index_type, 0, K);
    Expr l = Index::make(index_type, "l", dom_l, IndexType::Reduce);

    // A
    Expr expr_A = Var::make(data_type, "A", {i, j}, {M, N});

    // B
    Expr expr_B = Var::make(data_type, "B", {i, k, l}, {M, N, K});

    // C
    Expr expr_C = Var::make(data_type, "C", {k, j}, {N, N});

    Expr expr_D = Var::make(data_type, "D", {l, j}, {K, N});

    // main stmt
    Stmt main_stmt = Move::make(
        expr_A,
        Binary::make(data_type, BinaryOpType::Div, 
            Binary::make(data_type, BinaryOpType::Mul, expr_B, expr_C),
            expr_D),
        MoveType::MemToMem
    );

    // loop nest
    // Stmt loop_nest = LoopNest::make({i, j, k}, {main_stmt});

    // kernel
    Group kernel = Kernel::make("simple_gemm", {expr_A, expr_B}, {expr_C}, {main_stmt}, KernelType::CPU);

    // visitor
    IRVisitor visitor;
    kernel.visit_group(&visitor);

    // printer
    IRPrinter printer;
    std::string code = printer.print(kernel);

    std::cout << code;

    // mutator
    IRMutator mutator;
    mutator.grad_to = "B";
    kernel = mutator.mutate(kernel);  
     
    JsonPrinter printer1;
    std::cout << printer1.print(kernel) << "\n";

    // JsonPrinter printer2;
    // std::cout << printer2.print(mutator.op2_grad) << "\n";

    std::cout << "Success!\n";
    return 0;
}
#include<iostream>
#include"transform.h"
using namespace std;
#define A_row 3
#define A_column 5
void Print(matrix M) {
    for(int i=0;i<M.n_rows;i++) {
        cout<<"row "<<i<<": ";
        for(int j=0;j<M.n_cols;j++) {
            cout<<M.value(i,j)<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int a[] = {17,9,3,2,5,4,8,6,7,7,13,5,3,23,6};
    matrix A(A_row,A_column);
    matrix U(A_row,A_row);
    matrix S(A_row,A_column);
    matrix V(A_column,A_column);

    A.insert(a);
    U = identity(U.n_rows);
    V = identity(V.n_rows);
    S = A;

    transform(S,U,V);
    matrix R = U*A*V;
    cout<<"U*A*V="<<endl;
    Print(R);
    cout<<"--------------------"<<endl<<"S="<<endl;
    Print(S);
}
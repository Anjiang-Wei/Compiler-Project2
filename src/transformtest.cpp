#include<iostream>
#include"transform.h"
using namespace std;
#define A_row 4
#define A_column 7
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
    int a[] = {1, 0, 0, 0 ,0, 0, 0, 
               0, 0, 0, 0, 1, 0, 0,
               0, 0, 1, 0, 0, 1, 0, 
               0, 0, 0, 1, 0, 0, 1};
    matrix A(A_row,A_column);
    matrix U(A_row,A_row);
    matrix S(A_row,A_column);
    matrix V(A_column,A_column);

    A.insert(a);

    cout << "A is intialized as" << endl;
    Print(A);

    U = identity(U.n_rows);
    V = identity(V.n_rows);
    S = A;

    transform(S,U,V);
    matrix R = U*A*V;
    cout<<"U*A*V="<<endl;
    Print(R);
    cout<<"--------------------"<<endl<<"S="<<endl;
    Print(S);
    cout<<"--------------------"<<endl<<"U="<<endl;
    Print(U);
    cout<<"--------------------"<<endl<<"V="<<endl;
    Print(V);
}
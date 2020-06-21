#include<cstring>
#include "transform.h"



matrix::matrix(int r,int c) :n_rows(r),n_cols(c) {
        x = new int[r*c];
        memset(x,0,sizeof(int)*r*c);
    }
  
void matrix::insert(int _x[]) {
        for(int i=0;i<n_rows;i++) {
            for(int j=0;j<n_cols;j++)
            x[i*n_cols+j] = _x[i*n_cols+j];
        }
    }

void matrix::operator=(matrix t) {
        insert(t.x);
    }

int& matrix::value(int i,int j) {
        return x[n_cols * i + j];
    }

bool matrix::empty_after(int a,int& row,int& col) {
        for(int i=a;i<n_rows;i++)
        for(int j=a;j<n_cols;j++)
            if(value(i,j)!=0) {
                row = i;
                col = j;
                return false;
            }

        return true;
    }

bool matrix::undiv_in_row(int a,int& col) {
        for(int j=a+1;j<n_cols;j++) {
            if(value(a,j)%value(a,a)!=0) {
                col = j;
                return false;
            }
        }
        return true;
    }
    
bool matrix::undiv_in_col(int a,int& row) {
        for(int i=a+1;i<n_rows;i++) {
            if(value(i,a)%value(a,a)!=0) {
                row = i;
                return false;
            }
        }
        return true;
    }

bool matrix::empty_in_row(int a,int& col) {
        for(int j=a+1;j<n_cols;j++) {
            if(value(a,j)!=0) {
                col = j;
                return false;
            }
        }
        return true;
    }

bool matrix::empty_in_col(int a,int& row) {
        for(int i=a+1;i<n_rows;i++) {
            if(value(i,a)!=0) {
                row = i;
                return false;
            }
        }
        return true;
    }

void matrix::swap(int direction,int a,int b) {
        if(a==b) return;
        if(direction == 0) {    //swap row
            for(int j=0;j<n_cols;j++) {
                int t = value(a,j);
                value(a,j) = value(b,j);
                value(b,j) = t;
            }
        } else {    //swap col
            for(int i=0;i<n_rows;i++) {
                int t = value(i,a);
                value(i,a) = value(i,b);
                value(i,b) = t;
            }
        }
    }

void matrix::alter_row(int row1,int row2,int sigma,int tau,int gama,int alpha) {
        int x,y;
        for(int j=0;j<n_cols;j++) {
            x = value(row1,j);
            y = value(row2,j);
            value(row1,j) = sigma * x + tau * y;
            value(row2,j) = -gama * x + alpha * y;
        }
    }

void matrix::alter_col(int col1,int col2,int sigma,int tau,int gama,int alpha) {
        int x,y;
        for(int i=0;i<n_rows;i++) {
            x = value(i,col1);
            y = value(i,col2);
            value(i,col1) = sigma * x + tau * y;
            value(i,col2) = -gama * x + alpha * y;
        }
    }

matrix matrix::operator*(matrix x) {
        matrix M = matrix(n_rows,x.n_cols);
        for(int i=0;i<M.n_rows;i++)
            for(int j=0;j<M.n_cols;j++) {
                for(int k=0;k<n_cols;k++)
                    M.value(i,j) += value(i,k) * x.value(k,j);
        }
        return M;
}

matrix identity(int m) {
    matrix I = matrix(m,m);
    for(int i=0;i<m;i++) {
        I.value(i,i) = 1;
    }
    return I;
}

void extended_euclidean(int a,int b,int& x,int& y,int& z){
    int prev_r = a;
    int now_r = b;
    int prev_s = 1;
    int now_s = 0;
    int prev_t = 0;
    int now_t = 1;
    while(now_r!=0) {
        int q = prev_r/now_r;
        int next_r = prev_r - q * now_r;
        int next_s = prev_s - q * now_s;
        int next_t = prev_t - q * now_t;
        prev_r = now_r;
        prev_s = now_s;
        prev_t = now_t;
        now_r = next_r;
        now_s = next_s;
        now_t = next_t;
    }
    z = prev_r;
    x = prev_s;
    y = prev_t;
    return;
}

int diagonalize(int a,matrix& S,matrix& U,matrix& V) {
    int row,col;
    while(!S.empty_after(a,row,col)) {
        S.swap(1,a,col);
        V.swap(1,a,col);
        S.swap(0,a,row);
        U.swap(0,a,row);
        
        while(true) {
            int changed = false;
            while(!S.undiv_in_col(a,row)) {
                changed = true;
                int beta,sigma,tau;
                extended_euclidean(S.value(a,a),S.value(row,a),sigma,tau,beta);
                int gama = S.value(row,a)/beta;
                int alpha = S.value(a,a)/beta;
                S.alter_row(a,row,sigma,tau,gama,alpha);
                U.alter_row(a,row,sigma,tau,gama,alpha);
                
            }
            while(!S.empty_in_col(a,row)) {
                changed = true;
                int f = S.value(row,a)/S.value(a,a);
                S.alter_row(a,row,1,0,f,1);
                U.alter_row(a,row,1,0,f,1);
                
            }
            while(!S.undiv_in_row(a,col)) {
                changed = true;
                int beta,sigma,tau;
                extended_euclidean(S.value(a,a),S.value(a,col),sigma,tau,beta);
                int gama = S.value(a,col)/beta;
                int alpha = S.value(a,a)/beta;
                S.alter_col(a,col,sigma,tau,gama,alpha);
                V.alter_col(a,col,sigma,tau,gama,alpha);
                
            }
            while(!S.empty_in_row(a,col)) {
                changed = true;
                int f = S.value(a,col)/S.value(a,a);
                S.alter_col(a,col,1,0,f,1);
                V.alter_col(a,col,1,0,f,1);
            
            }
            if(!changed)
                break;
        }
        a+=1;
    }
    return a;
}

void transform(matrix& S, matrix& U,matrix& V) {
    int a = 0;
    a = diagonalize(a,S,U,V);

    while(1) {
        int R = a-1;
        bool complete = true;
        for(int a=0;a<=R;a++) {
            if(S.value(a,a)<0) {
                for(int i=0;i<S.n_rows;i++)
                    S.value(i,a) = -S.value(i,a);
                for(int i=0;i<V.n_rows;i++)
                    V.value(i,a) = -V.value(i,a);
            }
            if(a<R && S.value(a+1,a+1)%S.value(a,a)!=0) {
                for(int i=0;i<S.n_rows;i++)
                    S.value(i,a) = S.value(i,a) + S.value(i,a+1);
                for(int i=0;i<V.n_rows;i++)
                    V.value(i,a) = V.value(i,a) + V.value(i,a+1);
                a = diagonalize(a,S,U,V);
                complete = false;
                break;
            }
        }
        if(complete==true)
            break;
    }
}



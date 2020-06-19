class matrix {
public:
    int n_rows; //number of rows of the matrix
    
    int n_cols; //number of columns of the matrix
    
    int* x;     //array to store the content of the matrix
    
    matrix(int r,int c);
    
    void insert(int _x[]);  //use array to assign element values to the matrix
    
    void operator=(matrix t); //use another matrix to assign element values to the matrix
    
    int& value(int i,int j);    //return the (row i, column j) element of matrix
    
    bool empty_after(int a,int& row,int& col);  
    //check if there exists non-zero element(i,j) where i>=a or j>=a, 
    //if so, return its row and column as pivot element
    
    bool undiv_in_row(int a,int& col);
    //check if there exists un-divisible element(a,j) where j>a,
    //if so, return its column
    
    bool undiv_in_col(int a,int& row);
    //check if there exists un-divisible element(i,a) where i>a,
    //if so, return its row
    
    bool empty_in_row(int a,int& col);
    //check if there exists non-zero element(a,j) where j>a,
    //if so, return its column
    
    bool empty_in_col(int a,int& row);
    //check if there exists non-zero element(i,a) where i>a,
    //if so, return its row

    void swap(int direction,int a,int b);
    //if direction = 1, swap the a_th and b_th columns
    //if direction = 0, swap the a_th and b_th rows

    void alter_row(int row1,int row2,int sigma,int tau,int gama,int alpha);
    //simutaneously assign row1 := sigma * row1 + tau * row2,
    //                     row2 := -gama * row1 + alpha * row2

    void alter_col(int col1,int col2,int sigma,int tau,int gama,int alpha);
    //simutaneously assign column1 := sigma * column1 + tau * column2,
    //                     column2 := -gama * column1 + alpha * column2


    matrix operator* (matrix x);
};

matrix identity(int m);
// generate a rank m identity matrix

void extended_euclidean(int a,int b,int& x,int& y,int& z);
//given a and b, find x,y,z that satisfy a*x + b*y = z, and z is a,b's max common factor

int diagonalize(int a,matrix& S,matrix& U,matrix& V);

void transform(matrix& S, matrix& U,matrix& V);
// do Smith transform
#include "function.h"
using namespace std;

Matrix::Matrix(int n){
    this->n = n;
    matrix = new long long*[n]; 
    for(int i=0; i<n; i++){
        matrix[i] = new long long[n];
    }
    toZero();
}

Matrix::~Matrix(){}

Matrix::Matrix(const Matrix& ref){
    n = ref.n;
    matrix = new long long*[n]; 
    for(int i=0; i<n; i++){
        matrix[i] = new long long[n];
    }
    matrix = ref.matrix;    
}

Matrix& Matrix::operator=(const Matrix& ref){
    n = ref.n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matrix[i][j] = ref.matrix[i][j];
        }
    }
    return *this;
}

long long& Matrix::operator()(const int& row, const int& column) const{
    return matrix[row][column];
}

void Matrix::toIdentity(){
    for(int i=0; i<n-1; i++){
        matrix[i][i+1] = 1;
    }
    for(int i=0; i<n; i++){
        matrix[n-1][i] = 1;
    }
}

Matrix Matrix::operator*(const Matrix &rhs) const{
    Matrix ans(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                ans(i,j) += ((*this)(i,k)*rhs(k,j)) % mod;
                ans(i,j) %= mod;
            }
        }
    }
    return ans;
}

Matrix Matrix::power(int k) const{
    Matrix ret(n);
    ret = (*this);
    if(k==1) return ret;
    else if(k%2==0){
        ret = power(k/2);
        return ret*ret;
    }
    else{
        ret = power((k-1)/2);
        return ret*ret*(*this);
    }
}

Matrix constructMatrix(int n){
    Matrix ret(n);
    ret.toIdentity();
    return ret;
}

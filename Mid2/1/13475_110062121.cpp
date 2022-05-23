#include "function.h"
using namespace std;

Matrix::Matrix(const Matrix& ref){
    this->n = ref.n;
    matrix = new long long*[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new long long[n];
    matrix = ref.matrix;
}

Matrix::~Matrix(){
}


#include <iostream>
using namespace std;
const int mod = 1000000009;


class Matrix {
private:
  int n;
  long long **matrix;
public:
  // The Default Constructor
  Matrix() {
    n = 0;
    matrix = nullptr;
  }

  // The Destructor
  ~Matrix();

  Matrix(int n){
    this->n = n;
    matrix = new long long*[n];
    for (int i = 0; i < n; i++)
      matrix[i] = new long long[n];
  }

  // Copy contructor
  // Will be trigger when the following condition:
  // Matrix m = ref; -> Call copy contructor to copy from 'ref' to 'm'
  Matrix(const Matrix& ref);

  // TODO: copy assignment,
  // Will be trigger when the following condition:
  // Matrix a;
  // a = ref; -> Call copy assignment to copy from 'ref' to 'a'
  Matrix& operator=(const Matrix& ref)
  {
    if( n != ref.n ) {
        for(int i=0; i<n; i++)
            delete[] matrix[i];
        delete[] matrix;
        n = ref.n;
        matrix = new long long* [n];
        for(int i=0; i<n; i++) {
            matrix[i] = new long long [n];
            for(int j=0; j<n; j++)
                matrix[i][j] = ref.matrix[i][j];
        }
    }
    else {
        for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            matrix[i][j] = ref.matrix[i][j];
    }
    return *this;
  }

  // This operator allow the following code
  // This operator can help you access the data easily
  // 1. cout << m(1, 2) << endl; -> Shorthand of `cout << m.matrix[1, 2] << endl;`
  // 2. m(1, 2) = 100; -> Shorthand of `m.matrix[1, 2] = 100`
  long long& operator()(const int& row, const int& column) const{
    return this->matrix[row][column];
  }

  // Utilities functions
  void toIdentity(){
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j)
          matrix[i][j] = 1;
        else
          matrix[i][j] = 0;
      }
    }
  }

  void toZero() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        matrix[i][j] = 0;
    }
  }

  Matrix operator*(const Matrix& rhs) const{
    int n = this->n;
    Matrix ret(n);
    ret.toZero();
    const Matrix lhs = *this;
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          ret(i, j) = (ret(i, j) + lhs(i, k) * rhs(k, j)) % mod;
    return ret;
  }

  Matrix power(int k) const{
    Matrix cur = (*this);
    Matrix ret(n);
    ret.toIdentity();
    while (k > 0) {
      if (k & 1)
        ret = ret * cur;
      cur = cur * cur;
      k >>= 1;
    }
    return ret;
  }

  friend ostream& operator<<(ostream& os, const Matrix& matrix) {
    for (int i = 0; i < matrix.n; i++) {
      for (int j = 0; j < matrix.n; j++)
        os << matrix(i, j) << ' ';
      os << endl;
    }
    return os;
  }
};

Matrix constructMatrix(int n);


// Author: justin0u0<dancinglinkxalgorithm@gmail.com>
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
  // TODO: The Destructor
  ~Matrix();

  // TODO: The Customize Constructor
  Matrix(int n);
  
  // TODO: Copy contructor
  // Will be trigger when the following condition:
  // Matrix m = ref; -> Call copy contructor to copy from 'ref' to 'm'
  Matrix(const Matrix& ref);

  // TODO: copy assignment,
  // Will be trigger when the following condition:
  // Matrix a;
  // a = ref; -> Call copy assignment to copy from 'ref' to 'a'
  Matrix& operator=(const Matrix& ref);

  // TODO: Overload operator()
  // This operator allow the following code
  // This operator can help you access the data easily
  // 1. cout << m(1, 2) << endl; -> Shorthand of `cout << m.matrix[1, 2] << endl;`
  // 2. m(1, 2) = 100; -> Shorthand of `m.matrix[1, 2] = 100`
  long long& operator()(const int& row, const int& column) const;

  // Utilities functions
  // TODO: Make the matrix identity matrix
  void toIdentity();
  void toZero() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        matrix[i][j] = 0;
    }
  }

  // TODO: Overload operator * 
  Matrix operator*(const Matrix& rhs) const;

  // TODO: Return the matrix power of 'k'
  Matrix power(int k) const;

  friend ostream& operator<<(ostream& os, const Matrix& matrix) {
    for (int i = 0; i < matrix.n; i++) {
      for (int j = 0; j < matrix.n; j++)
        os << matrix(i, j) << ' ';
      os << endl;
    }
    return os;
  }
};

// TODO: Construct a matrix
Matrix constructMatrix(int n);

/*
 * HINT: To solve this problem
 * First, assuming there is an array containing the first F(N, 1) ~ F(N, N)
 * to compute F(N, N + 1), we can construct a matrix that multiply the array(N*1 matrix)
 * from F(N, 1) ~ F(N, N) to F(N, 2), F(N, N + 1),
 * so to compute F(N, N + 2), we can just multiply the array again.
 * 
 * For example, if N = 2, then
 * [ 0, 1 ]   [ 1 ]   [ 1 ]       [ 0, 1 ]   [ 1 ]   [ 2 ]
 * [      ] * [   ] = [   ], then [      ] * [   ] = [   ], ....
 * [ 1, 1 ]   [ 1 ]   [ 2 ]       [ 1, 1 ]   [ 2 ]   [ 3 ]
 */

int main() {
  int n, m;
  cin >> n >> m;
  if (m <= n) {
    cout << 1 << endl;
  } else {
    Matrix base = constructMatrix(n);
    base = base.power(m - n);
    int ans = 0;
    for (int i = 0; i < n; i++)
      ans = (ans + base(n - 1, i)) % mod;
    cout << ans << endl;
  }
  return 0;
}

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

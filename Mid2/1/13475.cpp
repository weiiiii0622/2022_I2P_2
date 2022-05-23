// Author: justin0u0<dancinglinkxalgorithm@gmail.com>
#include <iostream>
#include "function.h"
using namespace std;

Matrix constructMatrix(int n) {
	Matrix ret(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == n - 1 || i + 1 == j)
				ret(i, j) = 1;
			else
				ret(i, j) = 0;
		}
	}
	return ret;
}


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

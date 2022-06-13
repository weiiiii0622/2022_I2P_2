#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF INT_MAX

template<typename T, class Func>
void ForEach(T _begin, T _end, Func _func){
    for(; _begin!=_end; _begin++){
        _func(*_begin);
    }
};

struct Power{
    int exp = 2;
    void operator()(const int &base){
        int basex  = std::pow(base, exp);
    }
};

int main(){
    double A[] = {1,2,3,4,5};
    ForEach(A, A+5, Power());
    for(int i=0; i<5; i++){
        cout << A[i] << ' ';
    }
    cout << '\n';
    return 0;
}
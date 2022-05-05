#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF INT_MAX

class A{
    friend ostream &operator<<(ostream &, A &);
    //friend istream &operator>>(istream &, A &);
    public:
        A(string s):data(s){};
        void getStr(){
            cout << data << '\n';
        }
    private:
        string data;
};

ostream &operator<<(ostream &output, A &s){
    output << s.data << '\n';
    
    return output;
}

int main(){
    string a;
    cin >> a;
    A str(a);
    cout << str;
    str.getStr();
    return 0;
}
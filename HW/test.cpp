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
    string ans = "";
    ans[1] = 'a';
    ans[10] = 'd';
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[10] << "aa\n";
    cout << "size: " << ans.size() << '\n';
    cout << ans << '\n';
    return 0;
}
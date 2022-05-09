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
    string str; cin >> str;
    string ans = "";
    int cnt;
    for(int i=0; i<str.length(); i++){
        char c = str[i++];
        string cnt_s; stringstream ss;
        cnt = 1;
        while(str[i]==c){
            cnt++; i++;
        }
        i--;
        if(cnt>=3){
            ss << cnt; ss >> cnt_s;
            ans += (cnt_s + c);
        }
        else{
            if(cnt==1) ans+=c;
            else if(cnt==2) (ans+=c)+=c;
        }
    }
    cout << ans << '\n';
    return 0;
}
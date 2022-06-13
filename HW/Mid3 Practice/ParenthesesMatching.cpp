#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF INT_MAX

int n, len;
bool ans;
string str;

bool solve(){
    getline(cin, str);
    len = str.length();
    stack<char> s;
    for(int i=0; i<len; i++){
        if(str[i]=='{' || str[i]=='[' || str[i]=='(' || str[i]=='<'){
            s.push(str[i]);
        }
        else{
            if(s.empty()) return false;
            char c = s.top(); s.pop();
            if(c=='{'&&str[i]!='}' || c=='('&&str[i]!=')' || c=='['&&str[i]!=']' || c=='<'&&str[i]!='>'){
                return false;
            }
        }
    }
    return s.empty()?true:false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin.get();
    for(int t=1; t<=n; t++){
        ans = solve();
        cout << "Case " << t << ": " << (ans?"Yes":"No") << '\n';
    }
    return 0;
}
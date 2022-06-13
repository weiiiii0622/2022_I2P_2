#include <bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator()(const string& lhs, const string&rhs) const{
        if(lhs.compare(rhs) < 0) return true;
        else return false;
    }
};

int main(){
    set<string, cmp> s;
    string str;
    while(cin >> str){
        for(auto &c : str){
            c = tolower(c);
        }
        s.insert(str);
    }
    for(auto str : s){
        cout << str << '\n';
    }
    return 0;
}
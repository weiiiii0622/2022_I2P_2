#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF INT_MAX

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int w, m, e; cin >> w >> m >> e;
    set<int> woman, man;
    for(int i=0; i<w; i++){
        int x; cin >> x;
        woman.insert(x);
    }
    for(int i=0; i<m; i++){
        int x; cin >> x;
        man.insert(x);
    }
    int flag, ans=0;
    woman.size()>man.size()?flag=0:flag=1;

    for(int t=0; t<e; t++){
        ans = 0;
        int x; cin >>x;
        if(flag){
            for(auto &v:woman){
                if(man.find(x-v) != man.end()){
                    ans=1;
                    break;
                }
            }
        }
        else{
            for(auto &v:man){
                if(woman.find(x-v) != woman.end()){
                    ans = 1;
                    break;
                }
            }
        }
        cout << (ans?"Yes":"No") << '\n';
    }
    return 0;
}
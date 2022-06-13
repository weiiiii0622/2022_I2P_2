#include <bits/stdc++.h>
using namespace std;

int m, w, e;
//map<int, int> man, woman;
int man[200001];
set<int> s;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> w >> e;
    for(int i=0; i<m; i++){
        cin >> man[i];
    }
    for(int i=0; i<w; i++){
        int temp; cin >> temp;
        for(int i=0; i<m; i++){
            s.insert(man[i]+temp);
        }
    }
    for(int i=0; i<e; i++){
        bool ans = false;
        int event; cin >> event;
        if(s.find(event) != s.end()){
            ans = true;
        }
        cout << (ans==true?"Yes":"No") << '\n';
    }
    return 0;
}
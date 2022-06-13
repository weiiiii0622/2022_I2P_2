#include <bits/stdc++.h>
using namespace std;

int m, w, e;
set<int> man, woman;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> w >> e;
    for(int i=0; i<m; i++){
        int temp; cin >> temp;
        man.insert(temp);
    }
    for(int i=0; i<w; i++){
        int temp; cin >> temp;
        woman.insert(temp);
    }
    int flag;
    if(man.size() > woman.size()){
        flag = 1;
    }
    else{
        flag = 2;
    }

    for(int i=0; i<e; i++){
        bool ans = false;
        int event; cin >> event;
        if(flag == 1){
            for(auto &x: woman){
                if(man.find(event-x) != man.end()){
                    ans = true;
                    break;
                }
            }            
        }
        else{
            for(auto &x: man){
                if(woman.find(event-x) != woman.end()){
                    ans = true;
                    break;
                }
            }
        }
        cout << (ans==true?"Yes":"No") << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF INT_MAX

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string cmd;
    list<int> l;
    queue<int> q[3];
    int in[3] = {0, 0, 0};
    int n; cin >> n;
    while(n--){
        cin >> cmd;
        if(cmd == "ENQUEUE"){
            int x; cin >> x;
            int ctry = x%3;
            q[ctry].push(x);
            if(!in[ctry]) l.push_back(ctry), in[ctry] = 1;
        }
        else{
            if(l.empty()) continue;
            int ctry = l.front();
            cout << q[ctry].front() << '\n'; q[ctry].pop();
            if(q[ctry].empty()) l.pop_front(), in[ctry] = 0;
        }
    }
    return 0;
}
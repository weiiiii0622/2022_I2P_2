#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF INT_MAX

struct State{
    int lv, hp, mhp, dist;
    State(int lv, int hp, int mhp, int dist=0):lv(lv), hp(hp), mhp(mhp), dist(dist) {};
};

bool vis[16][301][401]; // [lv, hp, mhp];
int lv[16][2]; // [dmg, hl]

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l, hp, mhp, mdmg; cin >> l >> hp >> mhp >> mdmg;
    for(int i=0; i<l; i++){
        cin >> lv[i][0] >> lv[i][1];
    }

    queue<State> q;
    q.push(State(0, hp, mhp));
    while(!q.empty()){
        State cur = q.front(); q.pop();
        if(vis[cur.lv][cur.hp][cur.mhp]) continue;
        vis[cur.lv][cur.hp][cur.mhp] = true;

        if(cur.hp-mdmg>0 || cur.mhp-lv[cur.lv][0]<=0){
            q.push(State(cur.lv, cur.hp-mdmg, cur.mhp-lv[cur.lv][0], cur.dist+1));
            if(cur.mhp-lv[cur.lv][0]<=0) break;
        }
        if(cur.hp-mdmg>0 && lv[cur.lv][1]>mdmg){
            q.push(State(cur.lv, min(hp, cur.hp+lv[cur.lv][1])-mdmg, cur.mhp, cur.dist+1)); //  hp <= HP max
        }
        if(cur.hp-mdmg>0 && cur.lv < l-1){ // lv <= LV max
            q.push(State(cur.lv+1, cur.hp-mdmg, cur.mhp, cur.dist+1));
        }
    }

    if(q.empty()){
        cout << "-1\n";
    }
    else{
        cout << q.back().dist << '\n';
    }
    return 0;
}
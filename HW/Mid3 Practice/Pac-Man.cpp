#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF INT_MAX

char board[257][257];
int Dotpos[5][2];
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
int n, m, ans=0;

struct state{
    int PacX, PacY;
    int Dot;
    int cntDot, step;
    state(): Dot(0), step(0), cntDot(0) {};
    bool operator<(const state& rhs) const{
        if(PacX != rhs.PacX) return PacX < rhs.PacX;
        if(PacY != rhs.PacY) return PacY < rhs.PacY;
        if(Dot != rhs.Dot) return Dot < rhs.Dot;
        return 0;
    }
};

int main(){

    int t; cin >> t;
    getchar(); // !!!
    while(t--){
        ans = 0;
        cin >> n >> m;
        state start;
        getchar();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                char c = getchar();
                board[i][j] = c;
                if(c=='o'){
                    start.PacX = i;
                    start.PacY = j;
                }
                else if(c=='.'){
                    Dotpos[start.cntDot][0] = i;
                    Dotpos[start.cntDot][1] = j;
                    start.cntDot++;
                }
            }
            getchar();
        }

        queue<state> q;
        set<state> s; // !!!
        q.push(start);
        s.insert(start); // !!!
        while(!q.empty() && !ans){
            state cur = q.front(); q.pop();
            for(int i=0; i<4; i++){
                state next = cur;
                int newx = next.PacX + dx[i];
                int newy = next.PacY + dy[i];
                if(newx<0||newy<0||newx>=n||newy>=m||board[newx][newy] == '#') continue;
                
                for(int d=0; d<start.cntDot; d++){
                    if(newx == Dotpos[d][0] && newy == Dotpos[d][1] && (next.Dot & (1<<d)) == 0){ // !!!
                        next.cntDot--;
                        next.Dot ^= (1<<d);
                        break;
                    }
                }
                next.PacX = newx;
                next.PacY = newy;
                next.step++;
                if(next.cntDot == 0){ // !!!
                    ans = 1;
                    cout << next.step << '\n';
                    break;
                }
                if(s.find(next) == s.end()){
                    s.insert(next);
                    q.push(next);
                }
            }
        }

    }
    return 0;
}
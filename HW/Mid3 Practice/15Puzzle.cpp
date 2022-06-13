#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF INT_MAX
#define MAX_MOVE 60

const int grow[] = {-1,0,0,0,0,1,1,1,1,2,2,2,2,3,3,3}; // !!!
const int gcol[] = {-1,0,1,2,3,0,1,2,3,0,1,2,3,0,1,2}; // !!!
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

class State{
    public:
        int board[4][4];
        int prevMove;
        int step;
        int ex, ey;
        int h;

        State(int b[4][4]){
            for(int i=0; i<4; i++){
                for(int j=0; j<4; j++){
                    board[i][j] = b[i][j];
                    if(b[i][j] == 0){
                        ex = i, ey = j;
                    }
                }
            }
            step = 0;
            prevMove = -1;
            SetHeuristic();
        }

        State(const State& p){
            for(int i=0; i<4; i++){
                for(int j=0; j<4; j++){
                    board[i][j] = p.board[i][j];
                }
            }
            ex = p.ex, ey = p.ey;
            step = p.step;
            prevMove = p.prevMove;
            h = p.h;
        }

        void SetHeuristic(){
            h = 0;
            for(int i=0; i<4; i++){
                for(int j=0; j<4; j++){
                    if(board[i][j] == 0) continue; //!!!

                    int cur = board[i][j];
                    // Manhattan Distance
                    h += abs(grow[cur] - i) + abs(gcol[cur] - j);

                    // Linear Conflict
                    if(i == grow[cur]){ // !!!
                        for(int k=j; k<4; k++){
                            if(i == grow[board[i][k]] && board[i][k]>0 && cur > board[i][k]){   // !!!
                                h += 2;
                            }
                        }
                    }
                    if(j == gcol[cur]){ // !!!
                        for(int k=i; k<4; k++){
                            if(j == gcol[board[k][j]] && board[k][j]>0 && cur > board[k][j]){   // !!!
                                h += 2;
                            }
                        }
                    }
                }
            }
        }

        void update(int i, int newx, int newy){
            prevMove = i;
            step++;
            swap(board[ex][ey], board[newx][newy]);
            ex = newx;
            ey = newy;
            SetHeuristic();
        }

        bool operator<(const State& rhs) const{
            return step+h > rhs.step+rhs.h;
        }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int bd[4][4];
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin >> bd[i][j];
        }
    }
    State s(bd);
    priority_queue<State> pq;
    pq.push(s);
    while(!pq.empty()){
        State cur = pq.top();
        //cout << cur.h << '\n';
        if(cur.h == 0){
            break;
        }
        pq.pop(); // !!!
        if(cur.h+cur.step > MAX_MOVE) continue; // !!! optional

        for(int i=0; i<4; i++){
            State newState(cur);
            int newx = cur.ex+dx[i];
            int newy = cur.ey+dy[i];
            if(newx<0||newy<0||newx>=4||newy>=4) continue;
            if(i == (cur.prevMove^1)) continue;
            newState.update(i, newx, newy);
            pq.push(newState);
        }
    }

    if(pq.empty()){
        cout << -1 << '\n';
    }
    else{
        cout << pq.top().step << '\n';
    }

    return 0;
}
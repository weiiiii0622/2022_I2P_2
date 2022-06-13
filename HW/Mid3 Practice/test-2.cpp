#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF INT_MAX

char Board[257][257];
int DotX[5], DotY[5];
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
int n, m, findAns;
char c;

struct state{
    int PacManX, PacManY;
    int Dot;
    int cntDot, cntStep;
    state(): Dot(0), cntStep(0), cntDot(0) {}
    bool operator<(const state& rhs) const{
        if(PacManX != rhs.PacManX) return PacManX < rhs.PacManX;
        if(PacManY != rhs.PacManY) return PacManY < rhs.PacManY;
        if(Dot != rhs.Dot) return Dot < rhs.Dot;
        return 0;
    }
};

int main(){

    int t; cin >> t;
    getchar(); // !!!
    while(t--){
        cin>>n>>m;
        c = getchar(); //read new line '\n'
        state start;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                Board[i][j] = getchar();
                if(Board[i][j]=='o') 
                    start.PacManX = i, start.PacManY = j;
                if(Board[i][j]=='.'){
                	DotX[start.cntDot] = i;
                	DotY[start.cntDot] = j;
                    start.cntDot++;
				}
            }
            c = getchar(); //read new line '\n'
        }

        queue<state> Q;
        set<state> S;
        Q.push(start);
        S.insert(start);
        findAns = 0;
        while(Q.size() && findAns==0){
            state now = Q.front(); Q.pop();
            for(int i=0;i<4;i++){
                state next = now;
                next.PacManX = now.PacManX + dx[i];
                next.PacManY = now.PacManY + dy[i];
                if(0 <= next.PacManX && next.PacManX < n && 
                    0 <= next.PacManY && next.PacManY < m &&
                    Board[next.PacManX][next.PacManY]!='#'){
                    //update cntDot
                    for(int k=0;k<start.cntDot;k++){
						if(DotX[k]==next.PacManX && DotY[k]==next.PacManY && (next.Dot & (1<<k))==0){
                        	next.cntDot--;
                        	next.Dot ^= (1<<k); //use binary to indicate which dot was eaten
                            break;
                        }
                    }
                	//update cntStep
                	next.cntStep++;
                	//if find solution
                	if(next.cntDot==0){
                		findAns = 1;
		                cout<<next.cntStep<<"\n";
		                break;
		            }
                	//push to queue if never appeared
                	if(S.find(next)==S.end()){
	                    Q.push(next);
	                    S.insert(next);
					}
                }
            }
        }

    }
}
#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// G[i] is the neighbor towns of town i
vector<int> diamondTowns;
vector<int> G[100005];
int Dist[100005];

struct node {
    int id;
    int dist;
    node(int id, int l) {
        this->id = id;
        this->dist = l;
    }
};

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        diamondTowns.push_back(x);
    }
    fill(Dist, Dist+100005, -1);

    queue<node> Q;

    // [TODO] complete the task!
    for(auto x:diamondTowns){
        Q.push(node(x, 0));
    }

    while(!Q.empty()){
        node nd = Q.front();
        if(Dist[nd.id] == -1){
            Dist[nd.id] = nd.dist;
            for(auto x: G[nd.id]){
                Q.push(node(x, nd.dist+1));
            }
        }
        Q.pop();
    }

    // Output
    for (int i = 1; i <= N; i++) {
        cout << Dist[i] << '\n';
    }
    return 0;
}
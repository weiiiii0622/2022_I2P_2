#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define swap(x,y) {int temp=x; x=y; y=temp;}

int n, q, cnt;
int done;
int tree[3005][3];
int vis[3005];
char ans[3005];

void solve(int a, int b, int dis){
    if(!a) return;
    if(a == b){
        done = 1;
        return;
    }
    if(!vis[tree[a][0]]) {vis[tree[a][0]]=1; solve(tree[a][0], b, dis+1); vis[tree[a][0]]=0;}
    if(done) {ans[dis]='P'; return;}
    if(!vis[tree[a][1]]) {vis[tree[a][1]]=1; solve(tree[a][1], b, dis+1); vis[tree[a][1]]=0;}
    if(done) {ans[dis]='L'; return;}
    if(!vis[tree[a][2]]) {vis[tree[a][2]]=1; solve(tree[a][2], b, dis+1); vis[tree[a][2]]=0;}
    if(done) {ans[dis]='R'; return;}
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        int l, r; scanf("%d %d", &l, &r);
        tree[i][1] = l; tree[i][2] = r;
        tree[r][0] = tree[l][0] = i;
    }
    scanf("%d", &q);
    while(q--){
        done = 0;
        for(int i=0; i<n+3; i++) {ans[i] = '\0'; vis[i]=0;}
        int a, b; scanf("%d %d", &a, &b);
        vis[a] = 1;
        solve(a, b, 0);
        printf("%s\n", ans);
    }
    return 0;
}
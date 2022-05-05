#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define swap(x,y) {int temp=x; x=y; y=temp;}
#define MAXN 200005

int n, ans, root;
int l[MAXN], r[MAXN], pos[MAXN], rt[MAXN];

void dfs(int lx, int rx, int root){
    if(lx <= pos[root] && pos[root] <= rx){
        ans++;
    }
    if(l[root]==0){
        if(r[root]){
            if(pos[r[root]] > pos[root]) dfs(pos[root]+1, rx, r[root]);
            else dfs(lx, pos[root]-1, r[root]);
        }
    }
    else{
        dfs(lx, pos[root]-1, l[root]);
        dfs(pos[root]+1, rx, r[root]);
    }
}

int main(){

    while(scanf("%d", &n)!=EOF){
        ans = 0;
        for(int i=1; i<=n; i++){
            rt[i] = 0;
        }
        for(int i=1; i<=n; i++){
            int a, b; scanf("%d %d", &a, &b);
            l[i] = a; r[i] = b;
            rt[a] = rt[b] = 1;
        }
        for(int i=1; i<=n ;i++) if(!rt[i]) root = i;
        for(int i=1; i<=n; i++){
            int a; scanf("%d", &a);
            pos[a] = i;
        }
        for(int i=1; i<=n; i++){
            if(pos[l[i]] > pos[r[i]]){
                swap(l[i], r[i]);
            }
        }
        dfs(1, n, root);
        printf("%s", ans==n?"YES\n":"NO\n");
    }
    return 0;
}
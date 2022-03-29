#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MXN 200005
#define ll long long
#define swap(x, y) {int t=x; x=y; y=t;}
int n, a, b, rt[MXN], l[MXN], r[MXN], p[MXN], root, ans;

void dfs(int L, int R, int cur){
    if(L <= p[cur] && p[cur] <= R) ans++;
    if(l[cur] == 0){
        if(r[cur]) p[cur]>p[r[cur]]?dfs(L, p[cur]-1, r[cur]):dfs(p[cur]+1, R, r[cur]);
    }
    else{
        dfs(L, p[cur]-1, l[cur]);
        dfs(p[cur]+1, R, r[cur]);
    }
}

int main(){
    while(scanf("%d", &n) != EOF){
        ans = 0;
        for(int i=1; i<=n; i++) rt[i] = 0;
        for(int i=1; i<=n; i++){
            scanf("%d%d",&a,&b);
            l[i] = a, r[i] = b;
            rt[a] = rt[b] = 1;
        }
        for(int i=1; i<=n; i++) if(!rt[i]) root = i;
        for(int i=1; i<=n; i++) scanf("%d",&a), p[a] = i;
        for(int i=1; i<=n; i++){
            if(p[r[i]]<p[l[i]]){
                swap(r[i], l[i]);
            }
        }
        dfs(1,n,root);
        printf("%s\n",ans==n?"YES":"NO");
    }
}
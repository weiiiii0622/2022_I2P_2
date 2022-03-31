#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define ll long long
#define swap(x,y) {int temp=x; x=y; y=temp;}
#define MAX 300005

int ans = INT_MAX;
int l[MAX], r[MAX], num[MAX], pos, L, R;
char expr[MAX];

void cal(int cur){
    if(expr[cur]=='+') num[cur] = num[l[cur]] + num[r[cur]];
    else if(expr[cur]=='-') num[cur] = num[l[cur]] - num[r[cur]];
    else num[cur] = num[l[cur]] * num[r[cur]];
}

int dfs(){
    int cur = pos;
    if(expr[cur]<'0') {
        pos++; l[cur] = dfs();
        pos++; r[cur] = dfs();
        cal(cur);
    }
    else{
        num[cur] = expr[cur]-'0';
    }
    return cur;
}

int main(){
    scanf("%d%s", &pos, expr+1);
    pos = 1; dfs();
    ans = num[1]; pos=1;
    while(l[pos] && expr[l[pos]]<'0'){
        L = l[pos]; l[pos] = r[L]; cal(pos);
        r[L] = pos; cal(L); pos = L;
        ans = ans>num[pos]?num[pos]:ans;
    }
    while(r[pos] && expr[r[pos]]<'0'){
        R = r[pos]; r[pos] = l[R]; cal(pos);
        l[R] = pos; cal(R); pos = R;
        ans = ans>num[pos]?num[pos]:ans;
    }
    printf("%d\n", ans);
    return 0;
}

#include <stdio.h>
#define ll long long

ll len[55];
ll l, r;

void solve(int k, ll i){
    if(i==0) printf("O");
    else if(k!=1 && i<=len[k-1]) solve(k-1, i-1);
    else if((k==1&&i==1)||i==len[k-1]+1) printf("u");
    else if(k!=1 && i<=len[k-1]*2+2) solve(k-1, i-len[k-1]-2);
    else printf("Q");
}

int main(){
    len[1] = 3;
    for(int i=2; i<=50; i++){
        len[i] = len[i-1]*2 + 3;
    }

    int k;
    while(scanf("%d %lld %lld", &k, &l, &r) != EOF){
        for(ll i=l; i<=r; i++){
            solve(k, i);
        }
        printf("\n");
    }
    return 0;
}
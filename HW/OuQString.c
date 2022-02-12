#include <stdio.h>
#define ll long long

ll len[55];
int k, l, r, temp;

void solve(int k){
    if(temp+len[k] < l){
        temp += len[k];
        return;
    }
    else if(temp <= r){
        if(temp >= l && temp <= r) printf("O");
        temp++;
        if(k!=1 && temp <= r) solve(k-1);
        if(temp >= l && temp <= r) printf("u");
        temp++;
        if(k!=1 && temp <= r) solve(k-1);
        if(temp >= l && temp <= r) printf("Q");
        temp++;
    }
    else return;
}

int main(){
    len[1] = 3;
    for(int i=2; i<=50; i++){
        len[i] = 2*len[i-1]+3;
    }
    
    while(scanf("%d %d %d", &k, &l, &r)!=EOF){
        temp = 0;
        solve(k);
        printf("\n");
    }

    return 0;
}
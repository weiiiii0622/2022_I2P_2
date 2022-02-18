#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long

int main(){

    int t;
    scanf("%d", &t);
    while(t--){
        ll ans=0;
        ll A, B;
        scanf("%lld %lld", &A, &B);
        char B_str[11], b_str[12];
        ll b = B+1;
        sprintf(B_str, "%lld", B);
        sprintf(b_str, "%lld", b);
        if(strlen(B_str) == strlen(b_str)) ans=A*(strlen(B_str)-1);
        else ans=A*strlen(B_str);
        printf("%lld\n", ans);
    }
    return 0;
}
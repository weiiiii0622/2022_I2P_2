#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ll long long

ll solve(char* B){
    ll B_ll = atoll(B);
    char A[11];
    sprintf(A, "%lld", B_ll+1);
    if(strlen(B) < strlen(A)){
        return strlen(B);
    }
    else{
        return strlen(B)-1;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        ll A;
        char B[11];
        scanf("%lld %s", &A, B);
        printf("%lld\n", A*solve(B));
    }
    return 0;
}

// ll conc(ll a, ll b){
//     char a_str[11], b_str[11];
//     sprintf(a_str, "%lld", a);
//     sprintf(b_str, "%lld", b);
//     strcat(a_str, b_str);
//     return atoll(a_str);
// }

// int main(){
//     ll A, B, a, b, ans;
//     int t;
//     scanf("%d", &t);
//     while (t--){
//         ans = 0;
//         scanf("%lld %lld", &A, &B);
//         for(a=1; a<=A; a++){
//             for(b=1; b<=B; b++){
//                 if(a*b+a+b == conc(a, b)) ans++;
//             }
//         }
//         printf("%lld\n", ans);
//     }
//     return 0;
// }
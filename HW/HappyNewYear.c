#include <stdio.h>

int main(){
    int n, home, pos[200005], ans;
    scanf("%d", &n);
    scanf("%d", &home);
    int max=home, min=home;
    for(int i=0; i<n; i++){
        scanf("%d", &pos[i]);
    }
    for(int i=0; i<n; i++){
        if(pos[i]>home){
            if(pos[i]>max){
                max = pos[i];
            }
        }
        else{
            if(pos[i]<min){
                min = pos[i];
            }
        }
    }
    ans = (max-home)*2 + (home-min)*2;
    printf("%d\n", ans);
    return 0;
}
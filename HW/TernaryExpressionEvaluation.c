#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define swap(x,y) {int temp=x; x=y; y=temp;}
#define MAX 3005

int cnt=1, pos;
char op[MAX]; //index = 2,4,6,8,10,...
int val[MAX]; //index = 1,3,5,7,9,....
char num[MAX];

int dfs(int v){
    int a = num[val[pos/2+1]]-'0'; pos++;
    //printf("pos = %d v = %d a = %d op = %c\n", pos, v, a, op[pos/2]);
    if(op[pos/2]=='?'){
        pos++; 
        a = dfs(a);
        pos++; int b = num[val[pos/2+1]]-'0'; pos++;
        //printf("pos = %d op=? a = %d b = %d\n", pos, a, b);
        return v?a:b;
    }
    else{
        pos++; int b = num[val[pos/2+1]]-'0'; pos++;
        //printf("pos = %d op=: a = %d b = %d\n", pos, a, b);
        return v?a:b;
    }
}

int main(){
    while(scanf("%d", &val[cnt/2+1]) != EOF){
        cnt++;
        scanf("%c", &op[cnt/2]);
        if(op[cnt/2]=='\n') break;
        cnt++;
    }
    cnt/=2;
    int t; scanf("%d", &t);
    while(t--){
        memset(num, '\0', sizeof(char)*MAX);
        pos=3;
        scanf("%s", num+1);
        //printf("%s\n", num+1);
        printf("%d\n", dfs(num[val[1]]-'0'));
    }
    return 0;
}
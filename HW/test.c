#include<stdio.h>

int l[3005],r[3005],t,o,b;                                     //l: true跳到哪, r: false跳到哪 
char c,s[3005];
int dfs(){
    int a;
    scanf("%d%c",&a,&c);                                       //c 有三種 '?' ':' '\n'  
    if(c=='?') l[a] = dfs(), r[a] = dfs();
    return a;
}
int main(){
    o = dfs();                                                 //原點 
    scanf("%d",&t);
    while(t--){
        scanf("%s",s+1), b = o;
        while(l[b]+r[b]) b = (s[b]=='1') ? l[b] : r[b];        //l+r!=0 還沒走到底 
        printf("%c\n",s[b]);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char value[4] = "0000";
char expr[30];
int pos;

void add(int pos){
    if(value[pos]=='1'){
        value[pos] = '0';
        add(pos-1);
    }
    else{
        value[pos] = '1';
    }
    return;
}

int solve(){
    char c = expr[pos];
    if(c=='|' || c=='&'){
        pos++; int a = solve();
        pos++; int b = solve();
        return c=='|'?a|b:a&b;
    }
    else{
        return value[c-'A']-'0';
    }
}

int main(){
    scanf("%s", expr);
    for(int i=0; i<16; i++){
        pos = 0;
        if(i) add(3);
        printf("%c %c %c %c ", value[0], value[1], value[2], value[3]);
        printf("%d\n", solve());
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, M, n, m, ans, size;
char board[9][9];

int check(int x, int y, char c){
    if(c == 'Q'){
        for(int i=1; i<=x; i++){
            if(board[x-i][y]!='0') return 0;
            if(y-i>=0 && board[x-i][y-i]!='0') return 0;
            if(y+i<size && board[x-i][y+i]!='0') return 0;
        }
    }
    else{
        for(int i=1; i<=x; i++){
            if(board[x-i][y]!='0') return 0;
            if(y-i>=0 && board[x-i][y-i]=='Q') return 0;
            if(y+i<size && board[x-i][y+i]=='Q') return 0;
        }        
    }

    return 1;
}

void solve(int x){
    if(x == size) {
        ans++;
        return;
    }
    if(n<N){
        for(int i=0; i<size; i++){
            if(check(x, i, 'Q')){
                n++;
                board[x][i] = 'Q';
                solve(x+1);
                n--;
                board[x][i] = '0';
            }
        }
    }
    if(m<M){
        for(int i=0; i<size; i++){
            if(check(x, i, 'R')){
                m++;
                board[x][i] = 'R';
                solve(x+1);
                m--;
                board[x][i] = '0';
            }    
        }      
    }
}

int main(){

    while(scanf("%d %d", &N, &M) != EOF){
        ans = 0, n = 0, m = 0, size = N+M; 
        memset(board, '0', 9*9*sizeof(char));
        solve(0);
        printf("%d\n", ans);
    }
    
    return 0;
}
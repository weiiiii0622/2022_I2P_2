#include <stdio.h>
#include <string.h>

int n, done=0;
char board[101][101];
char str[11] = "ICPCASIASG\0";
int dir[8][2] = {{1,2}, {2,1}, {-1,2}, {2,-1}, {1,-2}, {-2,1}, {-1,-2}, {-2,-1}};

int check(int x, int y, int target){
    if(x>=0 && x<n && y>=0 && y<n && board[x][y]==str[target]){
        return 1;
    }
    else{
        return 0;
    }
}

void solve(int x, int y, int target){
    if(target == 10){
        done = 1;
        return;
    }
    for(int i=0; i<8; i++){
        if(check(x+dir[i][0], y+dir[i][1], target) && !done){
            printf("Get %c at %d %d\n", str[target], x+dir[i][0], y+dir[i][1]);
            solve(x+dir[i][0], y+dir[i][1], target+1);
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf(" %c", &board[i][j]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == 'I' && !done){
                solve(i, j, 1);
            }
        }
    }
    if(done){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    return 0;
}
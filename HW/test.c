#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define swap(x,y) {int temp=x; x=y; y=temp;}

int dir[8][2] = {{1,2}, {2,1}, {-1,2}, {2,-1}, {1,-2}, {-2,1}, {-1,-2}, {-2,-1}};
char board[100][100];
char str[12] = "ICPCASIASG\0";
int done=0;
int n;

int check(int x, int y, int target){
    if(x>=0&&x<n&&y>=0&&y<n&&board[x][y]==str[target]) return 1;
    return 0;
}

void solve(int x, int y, int target){
    if(target==10){
        done = 1;
        return;
    }
    for(int i=0; i<8; i++){
        if(check(x+dir[i][0], y+dir[i][1], target) && !done){
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
    printf("%s\n", done?"YES":"NO");
    return 0;
}
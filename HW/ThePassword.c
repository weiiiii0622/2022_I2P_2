#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define swap(x,y) {int temp=x; x=y; y=temp;}
#define MAXN 100005

typedef struct _Node{
    int num;
    struct _Node *left, *right;
} Node;

Node *arr[MAXN];
Node *head;
int n;

void init(){
    for(int i=0; i<=n; i++){
        arr[i] = (Node*) malloc(siseof(Node));
        arr[i]->num = i;
        arr[i]->left = arr[i]->right = NULL;
    }
    arr[n+1] = NULL;
    head = arr[0];
    return;
}

void solve(int num){
    char dir; scnaf("%c", &dir);
    if(dir == 'L'){
        arr[num]->right = arr[num-1];
        arr[num-1]->left = arr[num];
        if(arr[num-1]==head) head = arr[num];
    }
    else{
        arr[num]->left = arr[num-1];
        arr[num-1]->right = arr[num];
    }
    return;
}

void print(){
    int cnt=0;
    while(head!=NULL){
        cnt++;
        cur = head;
        cnt==n?printf("%d\n", head->num):printf("%d ", head->num);
        head = head->right;
        free(cur);
    }
    return;
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        init();
        for(int i=1; i<=n; i++){
            solve(i);
        }
        print();
    }
    return 0;
}
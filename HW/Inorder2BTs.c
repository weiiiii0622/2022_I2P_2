#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define MXN 15

typedef struct _Node{
    int data;
    struct _ *left, *right;
} Node;

typedef struct _List{
    Node *root;
    struct _List *next;
} List;

int n;
List *lst[MXN], *rst[MXN], *rt;
List *lst_bck[MXN], *rst_bck[MXN], *rt_bck;

void init(){
    for(int i=1; i<=n; i++){
        lst_bck[i] = lst[i] = NULL;
    }
    rt_bck = rt = NULL;
    return;
}

Node* construct_lst(int L, int R){
    if(L>=R) return NULL;
    for(int i=L; i<R; i++){
        
    }
}

int main(){

    scanf("%d", &n);
    init();
    for(int i=1; i<=n; i++){
        List *new_lst = (List*) malloc(sizeof(List));
        new_lst->root = construct_lst(1, i);
        if(lst_bck[i]==NULL) lst_bck[i] = lst[i] = new_lst;
        else {lst_bck[i]->next = new_lst; lst_bck[i] = new_lst;}
    }


    return 0;
}
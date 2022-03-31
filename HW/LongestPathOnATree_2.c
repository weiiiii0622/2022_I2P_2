#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define swap(x,y) {int temp=x; x=y; y=temp;}

typedef struct _Node{
    int num;
    struct _Node *next; // linkedlist of its children
} Node;

int n;
int max_dis;
int x;
Node *tree[20005];
Node *bck[20005]; // O(1) add children
int vis[20005]; // avoid circle

void add_children(int u, int v){
    Node *new = (Node*) malloc(sizeof(Node));
    new->num = v; new->next = NULL;
    bck[u]->next = new;
    bck[u] = bck[u]->next;
    return;
}

void freeTree(){
    for(int i=1; i<=n; i++){
        Node *cur = tree[i]->next, *temp;
        while(cur!=NULL){
            temp = cur;
            cur = cur->next;
            free(temp);
        }
        free(tree[i]);
    }
    return;
}

void init(){
    for(int i=1; i<=n; i++){
        tree[i] = (Node*) malloc(sizeof(Node));
        tree[i]->num = i;
        tree[i]->next = NULL;
        bck[i] = tree[i];
        vis[i] = 0;
    }
    int u, v;
    for(int i=0; i<n-1; i++){
        scanf("%d %d", &u, &v);
        add_children(u, v);
        add_children(v, u);
    }
    max_dis = 0;
    return;
}

void solve(int i, int dis){
    if(vis[i]) return;
    Node *cur = tree[i]->next;
    if(dis>max_dis){
        max_dis = dis;
        x = tree[i]->num;
    }
    vis[i] = 1;
    while(cur!=NULL){
        solve(cur->num, dis+1);
        cur = cur->next;
    }
    return;
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        init();
        solve(1, 0);
        for(int i=1; i<=n; i++) vis[i] = 0;
        solve(x, 0);
        printf("%d\n", max_dis);
        freeTree();
    }
    return 0;
}
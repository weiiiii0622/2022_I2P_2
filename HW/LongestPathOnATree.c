#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define swap(x,y) {int temp=x; x=y; y=temp;}

typedef struct _Node{
    int num;
    int d;
    int p;
    struct _Node *next; // linkedlist of its children
} Node;

int n;
Node *tree[20005];
Node *bck[20005]; // O(1) add children
int vis[20005]; // avoid circle

void add_children(int u, int v){
    Node *new = (Node*) malloc(sizeof(Node));
    new->d = new->p = 0; new->num = v; new->next = NULL;
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
        tree[i]->p = tree[i]->d = 0;
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
    return;
}

void solve(int i){
    if(vis[i]) return;
    vis[i] = 1;
    Node *child = tree[i]->next;
    int p_max=-1, p_sec=-1, d_max=-1;
    while(child!=NULL){
        if(vis[child->num]) {child = child->next; continue;} // avoid circle
        solve(child->num); //dfs
        Node *cur = tree[child->num]; // access current child
        // get p_max and p_second_max
        if(cur->d > d_max) d_max = cur->d;
        if(cur->p > p_max) {if(p_max>p_sec) {p_sec = p_max;} p_max = cur->p;}
        else p_sec = (cur->p)>p_sec?cur->p:p_sec;
        child = child->next;
    }
    tree[i]->p = p_max+1;
    tree[i]->d = d_max>(p_max+p_sec+2)?d_max:(p_max+p_sec+2);
    return;
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        init();
        int max=0;
        // handle disconnected graph
        for(int i=1; i<=n; i++){
            if(!vis[i]) solve(i);
            max = tree[i]->d>max?tree[i]->d:max;
        }
        printf("%d\n", max);
        freeTree();
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long

typedef struct _Node{
    char c;
    struct _Node *neighbor[2];
} Node;

int n, q;
Node *frt[100000 + 9];
Node *bck[100000 + 9];

void link(Node *cur, Node* new){
    cur->neighbor[cur->neighbor[0]==NULL?0:1] = new;
    return;
}

void print(Node *cur ,Node* prev){
    if(cur==NULL){
        printf("\n");
        return;
    }
    printf("%c" ,cur->c);
    int flag=0;
    for(int i=0; i<=1; i++){
        if(cur->neighbor[i] != prev){
            print(cur->neighbor[i], cur);
            free(cur);
            flag = 1;
            break;
        }
    }
    if(!flag) printf("\n");
    return;
}

void init(){
    scanf("%d", &n);
    int size;
    for(int i=1; i<=n; i++){
        frt[i] = bck[i] = NULL;
        scanf("%d ", &size);
        if(size){
            size--;
            frt[i] = (Node*) malloc(sizeof(Node));
            scanf(" %c", &(frt[i]->c));
            link(frt[i], NULL);
            link(frt[i], NULL);
            Node *prev = frt[i];
            while(size--){
                Node *new = (Node*) malloc(sizeof(Node));
                scanf(" %c", &(new->c));
                link(prev, new);
                link(new, prev);
                link(new, NULL);
                prev = new;
            }
            bck[i] = prev;
        }
    }
    return;
}

//order: to + cur
void merge(int cur, int to){
    if(frt[cur] == NULL || frt[to] == NULL) return;
    link(bck[to], frt[cur]);
    link(frt[cur], bck[to]);
    bck[to] = bck[cur];
    frt[cur] = bck[cur] = NULL;
    return;
}

void swap(int a, int b){
    if(frt[a]==NULL && frt[b]==NULL) return;
    if(frt[a]==NULL){
        frt[a] = frt[b]; bck[a] = bck[b];
        frt[b] = bck[b] = NULL;
    }
    else if(frt[b]==NULL){
        frt[b] = frt[a]; bck[b] = bck[a];
        frt[a] = bck[a] = NULL;
    }
    else{
        Node *temp = frt[a]; frt[a] = frt[b]; frt[b] = temp;
        temp = bck[a]; bck[a] = bck[b]; bck[b] = temp;
    }
    return;
}

void reverse(int cur){
    Node *temp = frt[cur];
    frt[cur] = bck[cur];
    bck[cur] = temp;
    return;
}

int main(){
    init();
    scanf("%d", &q);
    int type, a, b;
    while(q--){
        scanf("%d", &type);
        switch(type){
            case 1:
                scanf("%d %d", &a, &b);
                if(frt[a]!=NULL){
                    merge(b, a);
                    swap(a, b);
                }
                break;
            case 2:
                scanf("%d %d", &a, &b);
                merge(a, b);
                if(frt[b]==NULL)swap(a,b);
                break;
            case 3:
                scanf("%d %d", &a, &b);
                swap(a, b);
                break;
            case 4:
                scanf("%d", &a);
                reverse(a);
                break;
        }
    }
    for(int i=1; i<=n; i++){
        print(frt[i], NULL);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define swap(x,y) {int temp=x; x=y; y=temp;}

typedef struct _node{
    int data;
    struct _node *next;
} Node;

int n, m, a, k;
Node* head;

void init(int n){
    Node *temp;
    temp = (Node*) malloc(sizeof(Node));
    temp->data = 1;
    head = temp;
    for(int i=2; i<=n; i++){
        Node* new = (Node*) malloc(sizeof(Node));
        new->data = i;
        temp->next = new;
        temp = temp->next;
    }
}

void move(int a, int k){
    int cnt=0;
    Node *cur = head, *prev;
    Node *pos;

    while(cur != NULL){
        cnt++; if(cnt==a) break;
        prev = cur;
        cur = cur->next;
    }
    if(cur==head) head = head->next;
    else prev->next = cur->next;

    pos = cur->next; cnt = 0;
    while(pos->next != NULL){
        cnt++; if(cnt==k) break;
        pos = pos->next;
    }
    cur->next = pos->next;
    pos->next = cur;
    return;
}

void print(int n){
    Node* cur = head;
    printf("%d", cur->data);
    cur = cur->next;
    while(cur!=NULL){
        printf(" %d", cur->data);
        cur = cur->next;
    }
    printf("\n");
    return;
}

void delete(int n){
    Node *temp;
    while(head!=NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
    return;
}

int main(){
    scanf("%d %d", &n, &m);
    init(n);
    print(n);
    while(m--){
        scanf("%d %d", &a, &k);
        move(a, k);
        print(n);
    }
    delete(n);
    return 0;
}
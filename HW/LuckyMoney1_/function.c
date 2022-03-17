#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Node* createList(int n){
    Node *hd = (Node*) malloc(sizeof(Node));
    hd->prev = NULL; hd->next = NULL; hd->number = 1;
    Node *cur = hd;
    for(int i=2; i<=n; i++){
        Node *new = (Node*) malloc(sizeof(Node));
        new->prev = cur; new->next = NULL; new->number = i;
        cur->next = new;
        cur = cur->next;
    }
    return hd;
}

void solve(int n, int m){
    Node *cur = head;
    for(int i=1; i<=n; i++){
        if(i!=n) printf("%d ", cur->number);
        else printf("%d\n", cur->number);
        cur = cur->next;
    }
    while(m--){
        int a, k; scanf("%d %d", &a, &k); k = a+k>n?n:a+k;
        cur = head;
        if(a!=n){
            cur = head;
            Node *target, *pos;
            for(int i=1; i<=n; i++){
                if(i==a) target = cur;
                else if(i==k) {pos = cur; break;}
                cur = cur->next;
            }
            if(target==head){
                head = target->next;
            }
            target->next->prev = target->prev;
            if(target->prev!=NULL) target->prev->next = target->next;
            target->next = pos->next; target->prev = pos;
            if(pos->next!=NULL) pos->next->prev = target;
            pos->next = target;
        }

        cur = head;
        for(int i=1; i<=n; i++){
            if(i!=n) printf("%d ", cur->number);
            else printf("%d\n", cur->number);
            cur = cur->next;
        }
    }
    return;
}
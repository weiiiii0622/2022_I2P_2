#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Node* createList(int n){
    Node *temp;
    temp = (Node*) malloc(sizeof(Node));
    temp->number = 1; temp->next = NULL; temp->prev = NULL;
    head = temp;
    for(int i=2; i<=n; i++){
        Node* new = (Node*) malloc(sizeof(Node));
        new->number = i; new->next = NULL; new->prev = temp;
        temp->next = new;
        temp = temp->next;
    }
    return head;
}

void solve(int n, int m){
    Node* temp = head;
    printf("%d", temp->number);
    temp = temp->next;
    while(temp!=NULL){
        printf(" %d", temp->number);
        temp = temp->next;
    }
    printf("\n");

    int a, k;
    while(m--){
        scanf("%d %d", &a, &k);
        if(a!=n){
        
            int cnt=0;
            Node *cur = head;
            Node *pos;

            while(cur != NULL){
                cnt++; if(cnt==a) break;
                cur = cur->next;
            }
            if(cur==head){
                cur->next->prev = NULL;
                head = head->next;
            }
            else{
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
            }
            pos = cur->next; cnt = 0;
            while(pos->next != NULL){
                cnt++; if(cnt==k) break;
                pos = pos->next;
            }
            cur->prev = pos;
            cur->next = pos->next;
            if(pos->next != NULL) pos->next->prev = cur;
            pos->next = cur;
        }
        temp = head;
        printf("%d", temp->number);
        temp = temp->next;
        while(temp!=NULL){
            printf(" %d", temp->number);
            temp = temp->next;
        }
        printf("\n");
    }
    return;
}
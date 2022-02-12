#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Node* createList(){
    Node *hd = NULL;
    Node *cur = hd;

    while(1){
        int data;
        scanf("%d", &data);
        if(data>-1){
            Node* new = (Node*) malloc(sizeof(Node));
            new->data = data;
            if(hd==NULL){
                hd = new;
                cur = new;
            }
            else{
                cur->next = new;
                cur = cur->next;
            }
        }
        else break;
    }
    cur->next = NULL;
    return hd;
}

void deleteNode(Node ** nd, int data){
    int count = 0;
    Node *before = NULL;
    Node *cur = *nd;
    
    while(cur!=NULL){
        count++;
        if(count == data){
            if(before!=NULL) before->next = cur->next;
            else *nd = (*nd)->next;
            free(cur);
            break;
        }
        before = cur;
        cur = cur->next;
    }
    return;
}
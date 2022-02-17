#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void deleteNode(Node ** nd, int data){
    int count=0;
    Node *cur=*nd;
    Node *before=NULL;
    while(cur != NULL){
        count++;
        if(count==data){
            if(before!=NULL) before->next = cur->next;
            else cur = cur->next;
            free(cur);
            break;
        }
        before = cur;
        cur = cur->next;
    }
    return;
}

Node* createList(){
    Node *hd=NULL;
    Node *cur;
    int data;
    while (scanf("%d", &data) != EOF){
        if(data==-1) break;
        Node *new = (Node*)malloc(sizeof(Node));
        new->data = data;
        new->next = NULL;
        if(hd==NULL){
            hd = new;
            cur = hd;
        }
        else{
            cur->next = new;
            cur = cur->next;
        }
    }
    return hd;
}
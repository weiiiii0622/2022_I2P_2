#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Node* ReadOneList(){
    Node *cur = (Node*) malloc(sizeof(Node));
    cur->next = NULL;
    scanf("%d: ", &(cur->size));
    cur->data = (int*) malloc(sizeof(int)*(cur->size));
    for(int i=0; i<(cur->size); i++){
        scanf("%d", &(cur->data)[i]);
    }
    return cur;
}
void PrintList(Node *hd){
    Node *cur = hd->next;
    Node *temp;
    while(cur != NULL){
        temp = cur;
        for(int i=0; i<(cur->size); i++){
            i==(cur->size)-1?printf("%d\n", (cur->data)[i]):printf("%d ", (cur->data)[i]);
        }
        cur = cur->next;
        free(temp->data);
        free(temp);
    }
    return;
}



void Merge(Node *hd, int a, int b){
    int flag=0, count=0;
    Node *cur = hd->next, *before = hd;
    Node *from, *to;
    while(cur!=NULL){
        count++;
        if(count==a){
            from = cur;
            before->next = cur->next;
            flag++;
        }
        else if(count==b){
            to = cur;
            flag++;
        }
        if(flag==2) break;
        before = cur;
        cur = cur->next;
    }
    int newsize = from->size+to->size;
    int *arr = (int*) malloc(sizeof(int)*newsize);
    for(int i=0; i<to->size; i++){
        arr[i] = to->data[i];
    }
    for(int i=0; i<from->size; i++){
        arr[i+to->size] = from->data[i];
    }
    free(from->data);
    free(from);
    free(to->data);
    to->size = newsize;
    to->data = arr;
    return;
}


void Cut(Node* hd, int target, int cnt){
    int count=0;
    Node *cur = hd->next;
    while(cur != NULL){
        count++;
        if(count==target){
            break;
        }
        cur = cur->next;
    }
    int newsize = (cur->size) - cnt;
    int *arr = (int*) malloc(sizeof(int)*cnt);
    for(int i=0; i<cnt; i++){
        arr[i] = cur->data[i];
    }
    Node *new = (Node*) malloc(sizeof(Node));
    new->size = newsize;
    new->data = (int*) malloc(sizeof(int)*newsize);
    new->next = cur->next;
    for(int i=0; i<newsize; i++){
        new->data[i] = cur->data[i+cnt];
    }
    free(cur->data);
    cur->size = cnt;
    cur->data = arr;
    cur->next = new;
    return;
}
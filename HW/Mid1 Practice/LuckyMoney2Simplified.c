#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Node* createList(int N){
    Node *new = (Node*) malloc(sizeof(Node)*N);
    scanf("%d", &new[0].age);
    new[0].prev = &new[N-1]; new[0].next = &new[1];
    for(int i=1; i<N-1; i++){
        scanf("%d", &new[i].age);
        new[i].prev = &new[i-1]; new[i].next = &new[i+1];
    }
    scanf("%d", &new[N-1].age);
    new[N-1].prev = &new[N-2]; new[N-1].next = &new[0];
    return new;
}

Node* solve(int N, int M){
    while(M--){
        int a, b; scanf("%d %d", &a, &b);
        Node *cur = &head[a-1];
        Node *target = &head[a-1];
        for(int i=0; i<((b-1)%(N-1))+1; i++){
            target = target->next;
        }
        if(target->next == cur) continue;
        cur->prev->next = cur->next; cur->next->prev = cur->prev;
        target->next->prev = cur; cur->next = target->next;
        cur->prev = target; target->next = cur;
    }
    return &head[0];
}
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int age;
    struct _Node* prev;
    struct _Node* next;
}Node;

Node* head;

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
        int a, k; scanf("%d %d", &a, &k);
        Node *cur = &head[a-1];
        Node *target = &head[a-1];
        for(int i=0; i<((k-1)%(N-1))+1; i++){
            target = target->next;
        }
        if(target->next == cur) continue;
        cur->prev->next = cur->next; cur->next->prev = cur->prev;
        target->next->prev = cur; cur->next = target->next;
        cur->prev = target; target->next = cur;
    }
    return &head[0];
}

int main(){

    int N, M;

    scanf("%d%d", &N, &M);
    head = createList(N);
    Node *p = solve(N, M);
    for(int i = 0; i < N; i++){
        printf("%d ", p -> age);
        p = p -> next;
    }
    printf("\n");
    return 0;
}
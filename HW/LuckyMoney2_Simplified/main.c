#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Node* head;

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

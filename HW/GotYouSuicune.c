#include <stdio.h>
#include <stdlib.h>
#define MAXN 100005

typedef struct node {
    struct node* next;
    int val;
} Node;

void createLinkedList(Node **head, int N, int *arr){
    *head = (Node*) malloc(sizeof(Node));
    (*head)->next = (*head); (*head)->val = arr[1];
    Node *cur = *head;
    for(int i=2; i<=N; i++){
        Node* new = (Node*) malloc(sizeof(Node));
        new->next = *head; new->val = arr[i];
        cur->next = new;
        cur = cur->next;
    }
    return;
}
void swapTwoSegment(Node **head, int N, int a, int b, int len){
    if(a>b){int temp=a; a=b; b=temp;}
    if((a+len-1) >= b || b+len-N-1 >= a) return;
    Node *prev_a, *cur_a, *tail_a, *prev_b, *cur_b, *tail_b, *temp = *head;
    if(a==1){
        int size = N>(b+len-1)?N:b+len-1;
        for(int i=1; i<=size; i++){
            if(i==N) {prev_a = temp; cur_a = prev_a->next;}
            else if(i==a+len-1) tail_a = temp;
            if(i==b-1){prev_b = temp; cur_b = prev_b->next;}
            else if(i==b+len-1) tail_b = temp;
            temp = temp->next;
        }        
    }
    else{
        for(int i=1; i<=b+len-1; i++){
            if(i==a-1) {prev_a = temp; cur_a = prev_a->next;}
            else if(i==a+len-1) tail_a = temp;
            if(i==b-1){prev_b = temp; cur_b = prev_b->next;}
            else if(i==b+len-1) tail_b = temp;
            temp = temp->next;
        }
    }
    //printf("prev_a:%d / a:%d / tail_a: %d / tail_a_next: %d\n", prev_a->val, cur_a->val, tail_a->val, tail_a->next->val);
    //printf("prev_b:%d / b:%d / tail_b: %d / tail_b_next: %d\n", prev_b->val, cur_b->val, tail_b->val, tail_b->next->val);
    // printf("head prev: %d\n", (*head)->val);
    prev_a->next = cur_b;
    prev_b->next = cur_a;
    temp = tail_a->next;
    tail_a->next = tail_b->next;
    tail_b->next = temp;
    if(cur_a== *head) *head = cur_b;
    else if(b+len-1>N) {
        Node *temp = cur_a;
        for(int i=0; i<(N-b+1); i++){
           temp = temp->next; 
        }
        *head = temp;
    }
    // printf("head now: %d\n", (*head)->val);
    //printf("prev_a->next: %d / tail_a_next: %d\n", prev_a->next->val, tail_a->next->val);
    //printf("prev_b->next: %d / tail_b_next: %d\n", prev_b->next->val, tail_b->next->val);
    return;
}

int arr[MAXN];

int main() {
    int N;
    scanf("%d", &N);
    for(int i=1;i<=N;i++)
        scanf("%d", &arr[i]);

    Node *head = NULL;
    createLinkedList(&head, N, arr);

    int Q;
    scanf("%d", &Q);
    for(int i=1;i<=Q;i++) {
        int a,b,len;
        scanf("%d %d %d", &a, &b, &len);
        swapTwoSegment(&head, N, a, b, len);
    }

    for(int i=1;i<=N;i++) {
        if(i > 1)    printf(" ");
        printf("%d", head->val);
        head = head->next;
    }
    printf("\n");
    
    return 0;
}
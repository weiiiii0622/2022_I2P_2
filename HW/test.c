#include<stdio.h>
#include<stdlib.h>

typedef struct _Node{
    int size;
    int* data;
    struct _Node* next;
} Node;

Node* ReadOneList(){
    Node *new = (Node*) malloc(sizeof(Node));
    scanf("%d:", &(new->size));
    new->data = (int*) malloc(sizeof(int)*(new->size));
    for(int i=0; i<(new->size); i++){
        scanf("%d", &(new->data[i]));
    }
    new->next = NULL;
    return new;
}

void PrintList(Node* hd){
    Node* temp;
    while(hd!=NULL){
        temp = hd;
        for(int i=0; i<(hd->size); i++){
            if(i!=(hd->size-1)) printf("%d ", hd->data[i]);
            else printf("%d\n", hd->data[i]);
        }
        hd = hd->next;
        free(temp->data);
        free(temp);
    }
    return;
}
void Merge(Node* hd, int x, int y){
    int cnt = 0, size_x, size_y, new_size;
    int *new;
    Node *cur = hd->next, *before = hd;
    Node *Node_x, *Node_y;
    while(cur!=NULL){
        cnt++;
        if(cnt==x){
            before->next = cur->next;
            Node_x = cur;
        }
        else if(cnt==y) Node_y=cur;
        before = cur;
        cur = cur->next;
    }
    // printf("Prev_x: %d\n", Prev_x->data[0]);
    // printf("Node_x: %d\n", Node_x->data[0]);
    // printf("Prev_y: %d\n", Prev_y->data[0]);
    // printf("Node_y: %d\n", Node_y->data[0]);
    size_x = Node_x->size; size_y = Node_y->size; new_size = size_x+size_y;
    new = (int*) malloc(sizeof(int)*new_size);
    for(int i=0; i<size_y; i++){
        new[i] = Node_y->data[i];
    }
    for(int i=0; i<size_x; i++){
        new[i+size_y] = Node_x->data[i];
    }
    
    free(Node_y->data);
    Node_y->size = new_size;
    Node_y->data = new;
    free(Node_x->data);
    free(Node_x);
    return;
}
void Cut(Node *hd, int x, int i){
    Node *New, *Node_x;
    Node *cur = hd->next;
    int *new_data;
    int cnt = 0, x_size, new_size;
    while(cur!=NULL){
        cnt++;
        if(cnt==x){
            Node_x=cur;
            break;
        }
        cur = cur->next;
    }
    x_size = i; new_size = Node_x->size-i;
    New = (Node*) malloc(sizeof(Node));
    New->data = (int*) malloc(sizeof(int)*new_size);
    new_data = (int*) malloc(sizeof(int)*x_size);
    for(int k=0; k<x_size; k++){
        new_data[k] = Node_x->data[k];
    }
    for(int k=0; k<new_size; k++){
        New->data[k] = Node_x->data[k+x_size];
    }
    free(Node_x->data);
    New->size = new_size;
    New->next = Node_x->next;
    Node_x->next = New;
    Node_x->size = x_size;
    Node_x->data = new_data;
    return;
}

int main(){
    Node* dummy_head;
    Node* tail;

    dummy_head = (Node*) malloc( sizeof(Node) );
    dummy_head->data = NULL;
    dummy_head->size = -1;

    tail = dummy_head;

    int N, M;
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        tail->next = ReadOneList();
        tail = tail->next;   
    }
    char act[10];
    int x, y;
    for(int i=0; i<M; i++){
        scanf("%s %d %d", act, &x, &y);
        if( act[0] == 'M' ){
            Merge(dummy_head, x, y);
        }
        else{
            Cut(dummy_head, x, y);
        }
    }
    PrintList(dummy_head);
    return 0;
}

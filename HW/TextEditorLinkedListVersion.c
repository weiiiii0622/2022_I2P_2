#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node{
    char data;
    struct _Node *next;
    struct _Node *prev;
} Node;

void print(Node **hd){
    Node *cur = (*hd)->next;
    Node *temp = cur;
    while(cur != NULL){
        printf("%c", cur->data);
        temp = cur;
        cur = cur->next;
        free(temp);
    }
    printf("\n");
    return;
}

void add(Node** cur, char c){
    Node *new = (Node*) malloc(sizeof(Node));
    new->data = c;
    new->prev = *cur;
    new->next = (*cur)->next;
    if((*cur)->next != NULL) (*cur)->next->prev = new;
    (*cur)->next = new;
    *cur = (*cur)->next;
    return;
}
void backspace(Node** cur){
    if((*cur)->prev == NULL) return;
    if((*cur)->next == NULL){
        Node *temp = *cur;
        (*cur)->prev->next = NULL;
        *cur = (*cur)->prev;
        free(temp);
    }
    else{
        Node *temp = *cur;
        (*cur)->next->prev = (*cur)->prev;
        (*cur)->prev->next = (*cur)->next;
        *cur = (*cur)->prev;
        free(temp);
    }
    return;
}
void right(Node **cur){
    if((*cur)->next != NULL){
        *cur = (*cur)->next;
    }
    return;
}
void left(Node **cur){
    if((*cur)->prev!= NULL){
        *cur = (*cur)->prev;
    }
    return;
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        Node *hd = (Node*) malloc(sizeof(Node));
        hd->next = NULL;
        hd->prev = NULL;
        Node *cur=hd;
        int n;
        scanf("%d\n", &n);
        while(n--){
            char c;
            c = getchar();
            switch (c){
            case 'B':
                backspace(&cur);
                break;
            case 'L':
                left(&cur);
                break;
            case 'R':
                right(&cur);
                break;
            default:
                add(&cur, c);
                break;
            }
        }
        print(&hd);
    }
    return 0;
}
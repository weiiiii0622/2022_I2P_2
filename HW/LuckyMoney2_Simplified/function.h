#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

typedef struct _Node{
    int age;
    struct _Node* prev;
    struct _Node* next;
}Node;

extern Node* head;
Node* createList(int N);
Node* solve(int N, int M);

#endif

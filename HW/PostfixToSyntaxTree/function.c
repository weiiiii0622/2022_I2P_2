#include "function.h"

Node* createNode(char c){
    Node *new = (Node*) malloc(sizeof(Node));
    new->data = c;
    new->left = new->right = NULL;
    return new;
}

void constructTree(Node** head){
    char c = s2[idx];
    *head = createNode(c);
    if(c=='|' || c=='&'){
        idx++;
        constructTree(&((*head)->right));
        idx++;
        constructTree(&((*head)->left));
    }
    return;
}

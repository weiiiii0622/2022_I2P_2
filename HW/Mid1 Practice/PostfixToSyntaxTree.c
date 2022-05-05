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
    if(c=='|'||c=='&'){
        idx++; constructTree(&((*head)->right));
        idx++; constructTree(&((*head)->left));
    }
    return;
}

void printInfix(Node *root){
    if(root==NULL) return;
    if(root->data>='A'&&root->data<='D'){
        printf("%c", root->data);
    }
    else{
        printInfix(root->left);
        printf("%c", root->data);
        if(root->right->data == '|' || root->right->data == '&'){
            printf("(");
        }
        printInfix(root->right);
        if(root->right == '|' || root->right == '&'){
            printf(")");
        }       
    }
    return;
}
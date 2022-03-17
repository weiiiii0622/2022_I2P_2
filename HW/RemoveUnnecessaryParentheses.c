#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node{
    char data;
    struct _Node *left, *right;
} Node;

char expr[256];
int pos;

Node *makeNode(char);
Node *EXPR();
Node *FACTOR();
void printTree(Node*);
void freeTree(Node*);

int main(){

    scanf("%s", expr);
    pos = strlen(expr)-1;
    Node *root = EXPR();
    printTree(root);
    //printf("\n");
    freeTree(root);

    return 0;
}

Node* makeNode(char c){
    Node* new = (Node*) malloc(sizeof(Node));
    new->data = c;
    new->left = new->right = NULL;
    return new;
}

Node* EXPR(){
    Node *node, *right;
    if(pos>=0){
        right = FACTOR();
        if(pos>0){
            char c = expr[pos];
            if(c=='|' || c=='&'){
                pos--;
                node = makeNode(c);
                node->right = right;
                node->left = EXPR();
            }
            else{
                node = right;
            }
        }
        else{
            node = right;
        }
    }
    return node;
}

Node *FACTOR(){
    Node *node;
    if(pos>=0){
        char c = expr[pos--];
        if(c>='A' && c<='D'){
            node = makeNode(c);
        }
        else if(c==')'){
            node = EXPR();
            if(expr[pos--] != '('){
                freeTree(node);
            }
        }
    }
    return node;
}

void printTree(Node *root){
    if(root!=NULL){
        int flag = 0;
        if(root->data>='A' && root->data<='D'){
            printf("%c", root->data);
        }
        else{
            printTree(root->left);
            printf("%c", root->data);
            if(root->right->data=='&' || root->right->data=='|'){
                printf("(");
                flag = 1; 
            }
            printTree(root->right);
            if(flag) printf(")");
        }
        return;
    }
}

void freeTree(Node *root){
    if(root!=NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
    return;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "function.h"

typedef struct treeNode {
    char data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

char s1[100] , s2[100] ;

int idx ;


void printInfix(Node *root){
    if (root != NULL) {
        printInfix(root->left);

        printf("%c", root->data);

        if((root->data == '|' || root->data == '&') && (root->right->left != NULL && root->right->right != NULL))
            printf("(");

        printInfix(root->right);

        if((root->data == '|' || root->data == '&') && (root->right->left != NULL && root->right->right != NULL))
            printf(")");
    }
}

void freeTree(Node *root)
{
    if (root!=NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

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


int main(void)
{
    int n;
    int i , j ;
    scanf("%d", &n);// the number of test cases

    while(n>0)
    {
        scanf("%s" ,s1) ;
        idx = 0 ;
        for(i = 0 ; i < strlen(s1) ; i++){
            s2[i] = s1[strlen(s1)-1-i] ;
        }
        Node *root=NULL;
        constructTree(&root);// you have to implement this function
        printInfix(root);//output function
        printf("\n");
        freeTree(root);
        n--;
    }
    
    return 0;
}

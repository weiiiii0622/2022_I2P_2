#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void printInfix(Node *root){
    if(root != NULL){
        if(root->data>='A' && root->data<='D'){
            printf("%c", root->data);
        }
        else{
            int flag = 0;
            printInfix(root->left);
            printf("%c", root->data);
            if(root->right->data == '&' || root->right->data == '|'){
                printf("(");
                flag = 1;
            }
            printInfix(root->right);
            if(flag) printf(")");
        }
    }
    return;
}
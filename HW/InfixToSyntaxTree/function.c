#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"

BTNode* EXPR(){
    BTNode *node, *right;
    if(pos>=0){
        right = FACTOR();
        if(pos>0){
            char c = expr[pos];
            if(c=='|' || c=='&'){
                node = makeNode(c);
                node->right = right;
                pos--;
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
BTNode* FACTOR(){
    BTNode *node;
    if(pos>=0){
        char c = expr[pos--];
        if(c>='A'&&c<='D'){
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
BTNode* makeNode(char c){
    BTNode *node = (BTNode*) malloc(sizeof(BTNode));

    for(int i=0; i<NUMSYM; i++){
        if(c==sym[i]){
            node->data = i;
        }
    }
    node->left = node->right = NULL;
    return node;
}

/* print a tree by pre-order. */
void printPrefix(BTNode *root){
    if (root != NULL) {
        printf("%c",sym[root->data]);
        printPrefix(root->left);
        printPrefix(root->right);
    }
}

/* clean a tree.*/
void freeTree(BTNode *root){
    if (root!=NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}


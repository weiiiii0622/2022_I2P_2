#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define swap(x,y) {int temp=x; x=y; y=temp;}

typedef struct _Node{
    int data;
    struct _Node *left, *right;
} Node;

char str[3005];

Node* makeNode(int d){
    Node *new = (Node*) malloc(sizeof(Node));
    new->data = d;
    new->left = new->right = NULL;
    return new;
}

Node* constructTree(){
    int d; char c; scanf("%d%c", &d, &c);
    Node *root = makeNode(d);
    if(c=='?'){
        root->left = constructTree();
        root->right = constructTree();
    }
    return root;
}

char solve(Node *root){
    char val = str[root->data - 1];
    if(root->right==NULL && root->left==NULL){
        return val;
    }
    return val=='1'?solve(root->left):solve(root->right);
}

int main(){
    Node *root = constructTree();
    int t; scanf("%d", &t);
    while(t--){
        scanf("%s", str);
        printf("%c\n", solve(root));
    }
    return 0;
}
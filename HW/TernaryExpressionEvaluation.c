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

Node* createNode(int num){
    Node *new = (Node*)malloc(sizeof(Node));
    new->left = new->right = NULL;
    new->data = num;
    return new;
}

Node* constuctTree(){
    int d; char c; scanf("%d%c", &d, &c);
    Node *new = createNode(d);
    if(c=='?'){
        new->left = constuctTree();
        new->right = constuctTree();
    }
    return new;
}

char solve(Node *root){
    char val = str[root->data - 1];
    if(root->left == NULL &&  root->right == NULL){
        return val;
    }
    return val=='1'?solve(root->left):solve(root->right);
}

int main(){
    Node *root = constuctTree();
    int t; scanf("%d", &t);
    while(t--){
        scanf("%s", str);
        printf("%c\n", solve(root));
    }
    return 0;
}
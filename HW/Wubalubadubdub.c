#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define ll long long
#define swap(x,y) {int temp=x; x=y; y=temp;}

typedef struct _Node{
    ll data;
    struct _Node *left, *right;
} Node;

int cnt ,pos;
ll data[200005];
Node* root;

Node* createNode(ll data){
    Node *new = (Node*) malloc(sizeof(Node));
    new->data = data;
    new->right = new->left = NULL;
    return new;
}

Node* buildTree(ll min, ll max){
    if(pos<0) return NULL;

    ll cur_data = data[pos];
    if(cur_data < min || cur_data > max) return NULL;
    Node *root = createNode(cur_data);
    pos--;
    root->right = buildTree(cur_data+1, max);
    root->left = buildTree(min, cur_data-1);

    return root;
}

void printPreOrder(Node *root){
    if(root==NULL) return;
    printf(" %lld", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
    free(root);
    return;
}

int main(){
    while(scanf("%lld", &data[cnt]) != EOF){
        cnt++;
    }
    pos = cnt-1;
    root = buildTree(LLONG_MIN, LLONG_MAX);
    printf("%lld", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
    printf("\n");
    free(root);
    return 0;
}
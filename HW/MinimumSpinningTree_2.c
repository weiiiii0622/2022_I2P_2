#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define swap(x,y) {int temp=x; x=y; y=temp;}

typedef struct _Node{
    char data;
    int val;
    struct _Node *left, *right;
} Node;

int n, ans;

void evaluate(Node* root){
    char op = root->data;
    if(op=='+') root->val = root->left->val + root->right->val;
    else if(op=='-') root->val = root->left->val - root->right->val;
    else if(op=='*') root->val = root->left->val * root->right->val;
}

Node* constructTree(){
    Node *new = (Node*) malloc(sizeof(Node));
    char c; scanf(" %c", &c);
    new->data = c;
    new->left = new->right = NULL;
    if(c=='+'||c=='-'||c=='*'){
        new->left = constructTree();
        new->right = constructTree();
        evaluate(new);
    }
    else{
        new->val = c-'0';
    }
    return new;
}

void RightSpin(Node *root){
    Node *newroot = root->left;
    root->left = newroot->right;
    newroot->right = root;
    evaluate(root);
    evaluate(newroot);
    ans = ans>newroot->val?newroot->val:ans;
    return;
}

void LeftSpin(Node *root){
    Node *newroot = root->right;
    root->right = newroot->left;
    newroot->left = root;
    evaluate(root);
    evaluate(newroot);
    ans = ans>newroot->val?newroot->val:ans;
    return;
}

void solve(Node* root){
    Node *nxt;
    while(root->left->data=='+'||root->left->data=='-'||root->left->data=='*'){
        nxt = root->left;
        RightSpin(root);
        root = nxt;
    }
    while(root->right->data=='+'||root->right->data=='-'||root->right->data=='*'){
        nxt = root->right;
        LeftSpin(root);
        root = nxt;
    }
    return;
}

void printTree(Node *root){
    if(root==NULL) return;
    printTree(root->left);
    printf("%c", root->data);
    printTree(root->right);
}

void debug(Node *root){
    printTree(root);
    printf("\n%d\n", ans);
}

int main(){
    scanf("%d", &n);
    Node *root = constructTree();
    ans = root->val;
    solve(root);
    printf("%d\n", ans);
    //debug(root);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define swap(x,y) {int temp=x; x=y; y=temp;}

typedef struct _Node{
    int val;
    char data;
    struct _Node *left, *right;
}Node;

int n, ans;

Node* makeNode(char c){
    Node* new = (Node*) malloc(sizeof(Node));
    new->data = c;
    new->left = new->right = NULL;
    return new;
}

void eval(Node *root){
    char op = root->data;
    if(op=='+') root->val = root->left->val + root->right->val;
    if(op=='-') root->val = root->left->val - root->right->val;
    if(op=='*') root->val = root->left->val * root->right->val;
    return;
}

Node* constructTree(){
    char c; scanf(" %c", &c);
    Node *root = makeNode(c);
    if(c=='+'||c=='-'||c=='*'){
        root->left = constructTree();
        root->right = constructTree();
        eval(root);
    }
    else{
        root->val = c-'0';
    }
    return root;
}

void rightSpin(Node *root){
    Node *newroot = root->left;
    root->left = newroot->right;
    newroot->right = root;
    eval(root);
    eval(newroot);
    if(newroot->val < ans) ans = newroot->val;
    return;
}

void leftSpin(Node *root){
    Node *newroot = root->right;
    root->right = newroot->left;
    newroot->left = root;
    eval(root);
    eval(newroot);
    if(newroot->val < ans) ans = newroot->val;
    return;
}

void solve(Node *root){
    Node *nxt;
    while(root->left->data=='+'||root->left->data=='-'||root->left->data=='*'){
        nxt = root->left;
        rightSpin(root);
        root = nxt;
    }
    while(root->right->data=='+'||root->right->data=='-'||root->right->data=='*'){
        nxt = root->right;
        leftSpin(root);
        root = nxt;
    }
    return;
}

void infix(Node *root){
    if(root==NULL) return;
    if(root->data>='0'&&root->data<='9'){
        printf("%c", root->data);
    }
    else{
        infix(root->left);
        printf("%c", root->data);
        if(root->right->data=='+'||root->right->data=='-'||root->right->data=='*'){
            printf("(");
        }
        infix(root->right);
        if(root->right->data=='+'||root->right->data=='-'||root->right->data=='*'){
            printf(")");
        }               
    }
    return;
}



int main(){
    scanf("%d", &n);
    Node *root = constructTree();
    //infix(root);
    ans = root->val;
    solve(root);
    printf("%d\n", ans);
    return 0;
}
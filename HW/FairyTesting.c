#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define swap(x,y) {int temp=x; x=y; y=temp;}
#define MAXN 100005

typedef struct node{
    int value; // This is the value of the subtree, not the ID number
    int tokentype;
    struct node *leftchild;
    struct node *rightchild;
    struct node *parent; //pointing to the parent node
}Node;

Node *root;
Node* variable[MAXN]; 
char expr[MAXN*8];
int n, m;
int pos, len;

Node* createNode(int type, Node* parent){
    Node* new = (Node*) malloc(sizeof(Node));
    new->value = 0;
    new->tokentype = type;
    new->parent = parent;
    new->leftchild = new->rightchild = NULL;
    return new;
}

int str_to_int(){
    int res = 0;
    while(expr[pos] != ']'){
        res *= 10;
        res += expr[pos++]-'0';
    }
    return res;
}

Node* buildTree(Node *root){
    if(pos >= len) return NULL;
    Node *cur;
    char c = expr[pos++];
    if(c=='|' || c=='&'){
        cur =  createNode(c=='|'?-1:-2, root);
        Node *l = buildTree(cur);
        Node *r = buildTree(cur);
        cur->leftchild = l; cur->rightchild = r;
    }
    else if(c=='['){
        int num = str_to_int(); pos++;
        cur = createNode(num, root);
        variable[num] = cur;
    }
    return cur;
}

void solve(Node *cur){
    cur->value ^= 1;
    if(cur->parent == NULL) return;
    if(cur->parent->tokentype == -1){  // '|'
        if(cur->parent->value ^ (cur->parent->leftchild->value | cur->parent->rightchild->value)){
            solve(cur->parent);
        }
    }
    else if(cur->parent->tokentype == -2){  // '&'
        if(cur->parent->value ^ (cur->parent->leftchild->value & cur->parent->rightchild->value)){
            solve(cur->parent);
        }
    }
    return;
}

void printTree(Node *root){
    if(root==NULL) return; 
    printTree(root->leftchild);
    if(root->tokentype == -1) printf("%c ", '|');
    else if(root->tokentype == -2) printf("%c ", '&');
    else printf("%d ", root->tokentype);
    printTree(root->rightchild);
    return;
}

void freeTree(Node *root){
    if(root == NULL) return;
    freeTree(root->leftchild);
    freeTree(root->rightchild);
    free(root);
    return;
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        pos=0;
        scanf("%d %d", &n, &m);
        scanf("%s", expr);
        len = strlen(expr);
        root = buildTree(NULL);
        for(int i=0; i<m; i++){
            int target; scanf("%d", &target);
            solve(variable[target]);
            printf("%d\n", root->value);
        }
        //printTree(root); printf("\n");
        freeTree(root);
    }
    return 0;
}
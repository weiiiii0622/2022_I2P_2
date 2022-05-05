#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define swap(x,y) {int temp=x; x=y; y=temp;}

typedef struct _Node{
    int data;
    struct _Node *left, *right;
}Node;

typedef struct _List{
    Node *root;
    struct _List *next;
}List;

int n, cnt;

Node* makeNode(int data){
    Node *new = (Node*) malloc(sizeof(Node));
    new->data = data;
    new->left = new->right = NULL;
    return new;
}

void addTree(Node *root, List **trees_bck){
    List *new = (List*) malloc(sizeof(List));
    new->root = root;
    new->next = NULL;
    (*trees_bck)->next = new;
    (*trees_bck) = (*trees_bck)->next;
    return;
}

List* constructTree(int l, int r){
    List *trees = (List*) malloc(sizeof(List));
    List *trees_bck = trees;

    if(l>r){
        List *new = (List*) malloc(sizeof(List));
        new->root = NULL;
        new->next = NULL;
        trees->next = new;
        return trees;
    }

    for(int i=l; i<=r; i++){
        List *lst = constructTree(l, i-1);
        List *rst = constructTree(i+1, r);

        lst = lst->next;
        while(lst!=NULL){
            List *cur = rst->next;
            while(cur!=NULL){
                Node *root = makeNode(i);
                root->left = lst->root;
                root->right = cur->root;
                addTree(root, &trees_bck);
                cur = cur->next;
            }
            lst = lst->next;
        }
    }
    return trees;
}

void printPreorder(Node *root){
    if(root==NULL) return;
    cnt++;
    if(cnt==n) {printf("%d\n", root->data); return;}
    else printf("%d ", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}

int main(){
    scanf("%d", &n);
    List *trees = constructTree(1, n);
    trees = trees->next;
    while(trees!=NULL){
        cnt = 0;
        printPreorder(trees->root);
        trees = trees->next;
    }
    return 0;
}
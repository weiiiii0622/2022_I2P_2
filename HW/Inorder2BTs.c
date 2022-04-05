#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define MXN 15

typedef struct _Node{
    int data;
    struct _Node *left, *right;
} Node;

typedef struct _List{
    Node *root;
    struct _List *next;
} List;

int n;
int cnt;

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

void printList(List *tree){
    List *cur = tree;
    while(cur!=NULL){
        if(cur->root!=NULL) printf("%d ", cur->root->data);
        cur = cur->next;
    }
    printf(" END\n");
    return;
}

List* construct(int L, int R){
    List *trees = (List*) malloc(sizeof(List)); //DummyNode
    List *trees_bck = trees; // O(1) add root

    if(L>R){
        List *new = (List*) malloc(sizeof(List)); // Add a NODE with data=NULL
        new->next = NULL;
        new->root = NULL;
        trees->next = new;
        trees->root = NULL;
        return trees;
    }
    for(int i=L; i<=R; i++){
        List *Lst = construct(L, i-1);
        List *Rst = construct(i+1, R);

        Lst = Lst->next; //Skip DummyNode
        while(Lst!=NULL){

            List *cur = Rst->next;
            while(cur!=NULL){
                Node *root = makeNode(i);
                root->left = Lst->root;
                root->right = cur->root;
                addTree(root, &trees_bck);
                cur = cur->next;
            }

            Lst = Lst->next;
        }
    }
    return trees;
}

void preorder(Node *root){
    if(root==NULL) return;
    cnt++;
    if(cnt==n) {
        printf("%d\n", root->data);
        return;
    }
    else printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
    return;
}

int main(){

    scanf("%d", &n);
    List* trees = construct(1, n);
    List* temp;
    trees = trees->next;
    while(trees!=NULL){
        cnt = 0;
        temp = trees;
        preorder(trees->root);
        trees = trees->next;
        free(temp);
    }
    return 0;
}
#include "function.h"
using namespace std;

// Array_BST
Array_BST::Array_BST():BST(){
    for(int i=0; i<1025; i++){
        array[i] = 0;
    }
};

void Array_BST::insert(const int &data){
    if(Height==0){
        array[1] = data;
        Height = 1;
    }else{
        int idx = 1, h = 1;
        while(array[idx] != 0){
            if(array[idx] == data) return;
            else if(array[idx] > data){
                idx = idx*2;
            }
            else if(array[idx] < data){
                idx = idx*2 + 1;
            }
            h++;
        }
        array[idx] = data;
        if(h > Height) Height = h;
    }
    return;
}

bool Array_BST::search(const int &data) const{
    int idx = 1;
    while(array[idx] != 0){
        if(array[idx] == data) return true;
        else if(array[idx] > data){
            idx = 2*idx;
        }
        else if(array[idx] < data){
            idx = 2*idx + 1;
        }
    }
    return false;
}

//List_BST
List_BST::List_BST():BST(){};

ListNode* List_BST::createLeaf(int key) const{
    ListNode* new_node = new ListNode(key);
    return new_node;
}

void List_BST::deleteTree(ListNode *root){
    if(root==NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    return;
}

void List_BST::insert(const int &data){
    if(Height==0){
        root = createLeaf(data);
        Height = 1;
    }
    else{
        ListNode *cur = root, *parent;
        int flag; //0:left 1:right
        int h=1;
        while(cur != NULL){
            parent = cur;
            if(cur->key == data) return;
            else if(cur->key > data){
                flag = 0;
                cur = cur->left;
            }
            else if(cur->key < data){
                flag = 1;
                cur = cur->right;
            }
            h++;
        }
        cur = new ListNode(data);
        flag==0 ? parent->left=cur : parent->right=cur;
        if(h > Height) Height = h;
    }
    return;
}

bool List_BST::search(const int &data) const{
    ListNode *cur = root;
    while(cur != NULL){
        if(cur->key == data) return true;
        else if(cur->key > data){
            cur = cur->left;
        }
        else if(cur->key < data){
            cur = cur->right;
        }
    }
    return false;
}
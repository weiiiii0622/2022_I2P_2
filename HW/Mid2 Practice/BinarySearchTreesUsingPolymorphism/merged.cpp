#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

class BST{
public:
    BST():Height(0){}
    virtual ~BST() {}
    virtual void insert(const int &) = 0;
    virtual bool search(const int &) const = 0;
    virtual void print() const = 0;
    int height() const { return Height; }// An empty tree has height of 0. A tree with only root node has height of 1.

protected:
    int Height;
};

class Array_BST : public BST{
public:
    Array_BST();
    virtual ~Array_BST() {}
    virtual void insert(const int &) override; //root node is stored at index 1.
    virtual bool search(const int &) const override;
    virtual void print() const override{
        int k = pow(2, height());
        for (int i = 1; i <= k-1; i++) {
            if (array[i] != 0)
                cout << array[i] << " ";
        }
    }

private:
    int array[1025];
};

class ListNode{
    friend class List_BST; //make List_BST a friend

public:
    ListNode(const int &info):key( info ),left( NULL ),right( NULL ) //constructor
    {
    }//end ListNode constructor

private:
    int key;
    ListNode *left;
    ListNode *right;
};//end class ListNode

class List_BST : public BST{
public:
    List_BST();
    virtual ~List_BST()
    {
        deleteTree(root);
    }
    virtual void insert(const int &) override;
    virtual bool search(const int &) const override;
    virtual void print() const override{
        int i;
        for(i = 1; i <= Height; i++){
            printGivenLevel(root, i);
        }
    }

private:
    ListNode *root;
    // private member functions
    ListNode* createLeaf(int key) const; //new a ListNode and return its address
    /* clean a tree.*/
    void deleteTree(ListNode *root);

    void printGivenLevel(ListNode* Ptr, int level) const {
        if (Ptr == NULL)
            return;
        if (level == 1)
            cout << Ptr->key << " ";
        else if (level > 1)
        {
            printGivenLevel(Ptr->left, level-1);
            printGivenLevel(Ptr->right, level-1);
        }
    }
};

void BSTManipulator(BST& bstobj1,BST& bstobj2, char cmd ){
    int n;
    if (cmd == 'I') {
        cin >> n;
        bstobj1.insert(n);
        bstobj2.insert(n);
    }else if (cmd == 'S'){
        cin >> n;
        if (bstobj1.search(n)) {
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }

        if (bstobj2.search(n)) {
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }

    }else if (cmd == 'H'){
        cout << bstobj1.height() << endl;;
        cout << bstobj2.height() << endl;;

    }else if (cmd == 'P'){
        bstobj1.print();
        cout << endl;
        bstobj2.print();
        cout << endl;
    }
}

// function.cpp

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
            cout << "idx: " <<idx << '\n';
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

int main(){
    Array_BST A_bst;
    List_BST B_bst;
    char cmd;

    while (cin >> cmd)
        BSTManipulator(A_bst, B_bst, cmd);

    return 0;
}

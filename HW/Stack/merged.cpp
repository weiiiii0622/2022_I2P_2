#include<iostream>
#include<string.h>
using namespace std;

class ListNode
{
    friend class List_stack; //make List_stack a friend
    public:
        ListNode( const int &info ) //constructor
        : data( info ), nextPtr( NULL ), prevPtr( NULL )
        {
        } //end ListNode constructor

    private:
        int data; //data
        ListNode *nextPtr; // next node in list
        ListNode *prevPtr;
}; //end class ListNode

class List_stack {
    public:
        List_stack();
        ~List_stack();
        void push(const int &);
        void pop();
        void print();
    private:
        ListNode *head;
        ListNode *tail;
};

int cnt;

List_stack::List_stack(){
    this->head = this->tail = NULL;
    cnt = 0;
}
List_stack::~List_stack(){}

void List_stack::push(const int& num){
    ListNode *node = new ListNode(num);
    if(cnt==0){
        this->head = node;
        this->tail = node;
    }else{
        this->tail->nextPtr = node;
        node->prevPtr = tail;
        this->tail = node;
    }
    cnt++;
    // cout << "head:" << (this->head==NULL?-1:this->head->data) <<'\n';
    // cout << "tail:" << (this->tail==NULL?-1:this->tail->data) <<'\n';
    return;
}

void List_stack::pop(){
    if(cnt==0) return;
    if(cnt==1) {
        delete this->tail;
        this->head = this->tail = NULL;
        cnt = 0;
    }
    else{
        ListNode *temp = this->tail;
        this->tail = this->tail->prevPtr;
        this->tail->nextPtr = NULL;
        delete temp;
        cnt--;
    }
    // cout << "head:" << (this->head==NULL?-1:this->head->data) <<'\n';
    // cout << "tail:" << (this->tail==NULL?-1:this->tail->data) <<'\n';
    return;
}

void List_stack::print(){
    if(cnt==0) {return;}
    ListNode *temp = this->tail;
    cout << temp->data; temp = temp->prevPtr;
    while(temp != NULL){
        cout << ' ' << temp->data;
        temp = temp->prevPtr;
    }
    cout << "\n";
    return;
}

int main(){
    List_stack L_stack;
    char command[10];
    int n;
    while(cin>>command){

        if(strcmp(command,"pop")==0){
            L_stack.pop();
        }else if(strcmp(command,"push")==0){
            cin >> n;
            L_stack.push(n);
        }else if(strcmp(command, "print") == 0){
            L_stack.print();
            cout << endl;
        }
    }
    return 0;
}
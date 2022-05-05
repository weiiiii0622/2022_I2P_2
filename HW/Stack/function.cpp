#include<iostream>
#include<string.h>
#include "function.h"
using namespace std;

List_stack::List_stack(){
	head = tail = NULL;
}
List_stack::~List_stack(){}

void List_stack::push(const int& num){
	ListNode *node = new ListNode(num);
	node->prevPtr = head;
	head = node;
	return;
}

void List_stack::pop(){
	ListNode *temp = head;
	if(temp == NULL) return;
	head = head->prevPtr;
	delete temp;
}

void List_stack::print(){
	ListNode *temp = head;
	while(temp != NULL){
		cout << temp->data;
		temp = temp->prevPtr;
		if(temp) cout << ' ';
	}
}
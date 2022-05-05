#include "function.h"
using namespace std;

Str::Str(char* str){
    if(str[0] != '\0'){
        int i=0;
        tail = head = new Char(str[i++]);
        while(str[i]!='\0'){
            tail = tail->next = new Char(str[i]);
            i++;
        }
    }
}

Str::Str(const Str &str){
    tail = head = new Char(str.head->text);
    Char *cur = str.head->next;
    while(cur){
        tail = tail->next = new Char(cur->text);
        cur = cur->next;
    }
}

Str& Str::strInsert(const Str &str){
    Str *temp = new Str(str);
    tail->next = temp->head;
    tail = temp->tail;
    return *this;
}
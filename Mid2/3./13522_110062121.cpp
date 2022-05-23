#include "function.h"
using namespace std;

Darray::~Darray(){
    delete [] data;
}

void Darray::resize(void){
    int* new_data = new int[capacity*2];
    for(int i=0; i<size; i++){
        new_data[i] = data[i];
    }
    delete [] data;
    capacity *= 2;
    data = new_data;
    return;
}

int& Darray::operator[](int idx){
    return data[idx];
}

void Darray::pushback(int x){
    if(size>=capacity){
        resize();
    }
    data[size++] = x;
    return;
}

void Darray::popback(void){
    if(size>0) size--;
    return;
}

void Darray::clear(void){
    size = 0;
    return;
}

int Darray::length(void){
    return size;
}
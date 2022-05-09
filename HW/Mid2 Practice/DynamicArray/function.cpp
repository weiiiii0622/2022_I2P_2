#include "function.h"
using namespace std;

int& Darray::operator[](int idx){
    if(idx < 0 || idx >= size){
        return data[0];
    }
    return data[idx];
}

void Darray::pushback(int x){
    if(size==capacity){
        resize();
    }
    data[size++] = x;
    return;
}

void Darray::clear(void){
    size = 0;
    return;
}

int Darray::length(void){
    return size;
}

void Darray::resize(void){
    int* new_data = new int[capacity*2];
    for(int i=0; i<size; i++){
        new_data[i] = data[i];
    }
    delete []data;
    capacity *= 2;
    data = new_data;
    return;
}

Darray::~Darray(){
    delete []data;
}
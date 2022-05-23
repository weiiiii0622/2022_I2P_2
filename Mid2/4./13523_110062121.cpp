#include "function.h"
using namespace std;


void INT::operator+=(INT& tar){
    INT cpy;
    int size_cur = data.length();
    int size_tar = tar.data.length();
    int max_size = size_cur>size_tar?size_cur:size_tar;
    int d_cur, d_tar;
    int sum=0, carry=0;
    //cout << "dif: " << max_size - size_cur + 1 << '\n';
    if(data.length() >= size_cur){
        for(int i=0; i<=max_size-size_cur; i++){
            data.pushback(0);
        }
    }
    //cout << "real_len: " << data.length() << '\n';
    int new_len = max_size;
    // cout << "size_cur:: " << size_cur << '\n';
    // cout << "size_tar:: " << size_tar << '\n';
    // cout << "new_len:: " << new_len << '\n';
    //int ans_arr[max_size+5];
    //int ans_ptr = 0;
    //cout << "nl: " << new_len << '\n';
    while(size_cur>0 && size_tar>0){
        d_cur = data[size_cur-1];
        d_tar = tar.data[size_tar-1];
        
        sum = (d_cur + d_tar + carry)%10;
        carry = (d_cur + d_tar + carry)/10;
        //ans_arr[ans_ptr++] = sum;
        //cout << sum << ' ' << carry << '\n';
        data[new_len--] = sum; //tar.data.popback();
        //data.popback();
        size_cur--; size_tar--;
    }
    // cout << "size_cur:: " << size_cur << '\n';
    // cout << "size_tar:: " << size_tar << '\n';
    // cout << "new_len:: " << new_len << '\n';
    while(size_cur>0){
        d_cur = data[size_cur-1];
        sum = (d_cur+carry)%10;
        carry = (d_cur+carry)/10;
        //ans_arr[ans_ptr++] = sum;

        data[new_len--] = sum;
        //data.popback();
        size_cur--;
    }
    while(size_tar>0){
        d_tar = tar.data[size_tar-1];
        sum = (d_tar+carry)%10;
        carry = (d_tar+carry)/10;
        //cout << " Hi_tar sum: " << sum << '\n';
        //ans_arr[ans_ptr++] = sum;

        //tar.data.popback();
        data[new_len--] = sum;
        //data.popback();
        size_tar--;
    }
    //if(carry==1) ans_arr[ans_ptr++] = 1;
    if(carry==1) data[new_len--] = 1;
    else data[new_len--] = 0;

    //int ans_len = cpy.data.length();
    // data.clear();
    // for(int i=ans_ptr-1; i>=0; i--){
    //     data.pushback(ans_arr[i]);
    // }
    //cpy.data.~Darray();
    return;
}

std::istream& operator>>(std::istream &input, INT &tar){
    string str;
    input >> str;
    int len = str.length();
    for(int i=0; i<len; i++){
        tar.data.pushback(str[i]-'0');
    }
    return input;
}

std::ostream& operator<<(std::ostream &output, INT &tar){
    int len = tar.data.length();
    for(int i=0; i<len; i++){
        //cout << "cur: " << tar.data[i] << '\n';
        if(i==0 && tar.data[i]==0) continue;
        output << tar.data[i];
    }
    return output;
}











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
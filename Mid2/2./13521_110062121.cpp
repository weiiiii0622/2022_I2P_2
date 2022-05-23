#include<iostream>
#include<string>
#include<sstream>
#include "function.h"
using namespace std;

void Number_Codec::encode()
{
    string ans, temp;
    stringstream ss;
    int len = code_str.length();
    for(int i=0; i<len; i++){
        int res = code_str[i]-'a'+1;
        ss << res; ss>>temp;
        ans+=temp;
        ss.clear(); ss.str(string());
    }
    code_str = ans;
}

void Two_Number_Codec::encode()
{
    string ans, temp;
    stringstream ss;
    int len = code_str.length();
    for(int i=0; i<len; i++){
        int res = code_str[i]-'a'+1;
        if(res>=1&&res<=9) ss << 0;
        ss << res; ss>>temp;
        ans+=temp;
        ss.clear(); ss.str(string());
    }
    code_str = ans;
}

void The_Rail_Fence_Cipher_Codec::encode()
{
    int len = code_str.length();
    stringstream ss;
    string ans;

    if(len%2==0){
        for(int i=0; i<len/2; i++){
            ss<<code_str[i];
            ss<<code_str[i+len/2];
        }
    }
    else{
        for(int i=0; i<(len+1)/2; i++){
            ss<<code_str[i];
            if(i!=((len+1)/2)-1) ss<<code_str[i+(len+1)/2];
        }
    }
    ss >> ans;
    code_str = ans;
}
#include<iostream>
#include"function.h"

using namespace std;

int main(){
    string input_string, Codec_Type;
    cin >> input_string >> Codec_Type;

    if(Codec_Type == "Number"){
        Number_Codec text(input_string);
        text.encode();
        text.show();
    }

    if(Codec_Type == "Two_Number"){
        Two_Number_Codec text(input_string);
        text.encode();
        text.show();
    }

    if(Codec_Type == "The_Rail_Fence_Cipher"){
        The_Rail_Fence_Cipher_Codec text(input_string);
        text.encode();
        text.show();
    }
}



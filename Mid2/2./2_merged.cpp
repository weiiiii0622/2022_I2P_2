#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Codec {
public:
    virtual void encode() = 0;
    virtual ~Codec() { } // Do nothing
    virtual void show() = 0;
};

class Number_Codec: public Codec {
public:
    Number_Codec(std::string s): code_str{s} { }
    void encode();
    void show(){
        std::cout << code_str << "\n";
    }
private:
    std::string code_str;
};

class Two_Number_Codec: public Codec
{
public:
    Two_Number_Codec(std::string s): code_str{s} { }
    void encode();
    void show(){
        std::cout << code_str << "\n";
    }
private:
    std::string code_str;
};

class The_Rail_Fence_Cipher_Codec: public Codec
{
public:
    The_Rail_Fence_Cipher_Codec(std::string s): code_str{s} { }
    void encode();
    void show(){
        std::cout << code_str << "\n";
    }
private:
    std::string code_str;
};

void Number_Codec::encode()
{
    string ans, temp;
    stringstream ss;
    int len = code_str.length();
    for(int i; i<len; i++){
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
    for(int i; i<len; i++){
        int res = code_str[i]-'a'+1;
        ss << res; ss>>temp;
        ans+=temp;
        ss.clear(); ss.str(string());
    }
    code_str = ans;
}

void The_Rail_Fence_Cipher_Codec::encode()
{
       string ans, temp;
    stringstream ss;
    int len = code_str.length();
    for(int i; i<len; i++){
        int res = code_str[i]-'a'+1;
        ss << res; ss>>temp;
        ans+=temp;
        ss.clear(); ss.str(string());
    }
    code_str = ans;
}

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




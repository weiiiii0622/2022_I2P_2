#ifndef _FUNC_H
#define _FUNC_H
#include <iostream>

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

#endif

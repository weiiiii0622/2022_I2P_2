#include<iostream>
#include"function.h"
using namespace std;

#include<iostream>
#include"function.h"
using namespace std;

String_Calculator::String_Calculator(const string str): s(str){}

String_Calculator& String_Calculator::Add(const string str){
	s += str;
	return *this;
}

String_Calculator& String_Calculator::Subtract(const string str){
	int pos = s.find(str);
	if(pos==-1){
		s = "error";
	}
	else{
		string s1 = s.substr(0, pos);
		string s2 = s.substr(pos+str.length(), s.length()-(pos+str.length())+1);
		s = s1+s2;
	}
	return *this;
}

String_Calculator& String_Calculator::DividedBy(const string str){
	int ans = 0;
	int i = s.find(str);
	while(i!=-1){
		ans++;
		i++;
		i = s.find(str, i);
	}
	s = to_string(ans);
	return *this;
}

void String_Calculator::output() const{
	cout << s << '\n';
}
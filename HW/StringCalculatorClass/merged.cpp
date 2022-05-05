#include<iostream>
using namespace std;

class String_Calculator {
    public:
        String_Calculator(){};
        String_Calculator(const string);
        String_Calculator& Add(const string);
        String_Calculator& Subtract(const string);
        String_Calculator& DividedBy(const string);
        void output() const;

    private:
        string s = "";
}; //end class String_Calculator

String_Calculator::String_Calculator(const string str) : s(str){}

String_Calculator& String_Calculator::Add(const string str){
    this->s += str;
    cout << "ADD "<<str << ' ' << this->s << '\n';
    return (*this);
}

String_Calculator& String_Calculator::Subtract(const string str){
    int sp = this->s.find(str);
    int len = str.length();
    if(sp == -1) {this->s = "error"; return (*this);}
    cout << "sp: " << sp << " len: " << len <<'\n';
    string s1(this->s, 0, sp);
    string s2(this->s, sp+len, this->s.length()-(sp+len)+1);
    this->s = s1+s2;
    cout << "SUB " << this->s << '\n';
    return (*this);
}

String_Calculator& String_Calculator::DividedBy(const string str){
    int ans = 0;
    int i = 0;
    while(i!=-1 ){
        i = this->s.find(str, i);
        if(i!=-1){
            i++;
            ans++;
        }
    }
    this->s = to_string(ans);
    cout << "DIV " << this->s << '\n';
    return (*this);
}

void String_Calculator::output() const{
    cout << s << '\n';
}

int main(){
    int n;
    string x, y;
    cin >> n;
    while(n--){
        cin >> x >> y;
        String_Calculator a(x), ans;
        ans = a.Subtract(y).Add(y).DividedBy(y);
        ans.output();
    }
}
#include <iostream>
using namespace std;
#define maxsize 1000

class INT {
    public:
        INT() {}
        INT operator=(INT);
        INT operator+(INT);
        friend std::istream &operator>>(std::istream &, INT &);
        friend std::ostream &operator<<(std::ostream &, INT);
    protected:
        char data[maxsize + 1];
        int len;
};


INT INT::operator=(INT cpy){
    len = cpy.len;
    for(int i=0; i<len; i++){
        data[i] = cpy.data[i];
    }
    return *this;
}

INT INT::operator+(INT t){
    int l, carry=0;
    char a[1001]; memset(a, '\0', sizeof(char)*1001);
    for(int i=0; i<len; i++){a[i] = data[len-1-i];}
    char b[1001]; memset(b, '\0', sizeof(char)*1001);
    for(int i=0; i<t.len; i++){b[i] = t.data[t.len-1-i];}
    int ans[1001]; for(int i=0; i<1000; i++) ans[i] = 0;
    
    for(l=0; ; l++){
        int a_val=0, b_val=0;
        if(!(a[l]=='\0')){
            a_val = a[l]-'0';
        }
        if(!(b[l]=='\0')){
            b_val = b[l]-'0';
        }
        if(a[l]=='\0'&&b[l]=='\0'){
            if(carry==1){
                ans[l] = carry;
                len = l+1;
            }
            else{
                len = l;
            }
            break;
        }
        ans[l] = (a_val + b_val + carry)%10;
        carry = (a_val + b_val + carry)/10;
    }
    for(int i=0; i<len; i++){
        data[i] = ans[len-1-i] + '0';
    }
    data[len] = '\0';
    return *this;
}

std::istream &operator>>(std::istream &input, INT &s){
    input >> s.data;
    s.len = strlen(s.data);
    return input;
}

std::ostream &operator<<(std::ostream &output, INT s){
    for(int i=0; i<s.len; i++){
        output << s.data[i];
    }
    return output;
}

int main() {
    INT a, b, c;
    cin >> a >> b;
    c = a + b;
    cout << c << endl;
    return 0;
}

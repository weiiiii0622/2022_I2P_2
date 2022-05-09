#include "function.h"
#include <sstream>
using namespace std;

void RleCodec::encode()
{
    // Your code here
    string ans;
    stringstream ss;
    string cnt_s;
    int cnt;
    int len = code_str.length();
    for(int i=0; i<len; i++){
        char c = code_str[i++];
        cnt = 1;
        while(code_str[i]==c){
            i++; cnt++;
        }
        i--;
        if(cnt>=3){
            ss << cnt; ss >> cnt_s;
            ans += (cnt_s+c);
            ss.clear(); ss.str(string());
        }
        else if(cnt==2){
            (ans+=c)+=c;
        }
        else if(cnt==1){
            ans+=c;
        }
    }
    code_str = ans;
    encoded = true;
}

void RleCodec::decode()
{
    std::stringstream os;
    std::string int_str;
    for (auto c : code_str) {
        if (std::isdigit(c)) {
            int_str.push_back(c);
        } else {
            int cnt = 0;
            std::stringstream is{int_str};
            is >> cnt;
            if (cnt==0) {
                os << c;
            } else {
                for (int i=0; i<cnt; ++i)
                    os << c;
            }
            int_str.clear();
        }
    }

    code_str = os.str();
    encoded = false;

}
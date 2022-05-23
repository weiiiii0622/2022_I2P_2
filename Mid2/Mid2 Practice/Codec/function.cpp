#include "function.h"
#include <algorithm>
#include <sstream>
using namespace std;

class ReverseCodec : public BaseCodec {
    public:
        ReverseCodec(){};
        virtual ~ReverseCodec(){};
        virtual string encode(const std::string& str){
            string r_str = str;
            reverse(r_str.begin(), r_str.end());
            return r_str;
        };
};

class CompressCodec : public BaseCodec {
    public:
        CompressCodec(){};
        virtual ~CompressCodec(){};
        virtual string encode(const std::string& str){
            string ans = "";
            int cnt; 
            stringstream ss; // will TLE if put in for loop !!!
            for(int i=0; i<str.length(); i++){
                char c = str[i++];
                string cnt_s;
                cnt = 1;
                while(str[i]==c){
                    cnt++; i++;
                }
                i--; // return one char back
                if(cnt>=3){
                    ss << cnt; ss >> cnt_s; 
                    ans += (cnt_s + c);
                    ss.clear(); ss.str(string()); // Clear ss

                    // without stringstream method
                    // cnt_s = "";
                	// while(cnt)cnt_s = char('0'+cnt%10) + cnt_s, cnt/=10;
                	// ans = ans + cnt_s + c;
                }
                else{
                    if(cnt==1) ans+=c;
                    else if(cnt==2) (ans+=c)+=c;
                }
            }
            return ans;
        };
};

class DelayCodec : public BaseCodec {
    public:
        string prev_str = "None";
        DelayCodec(){};
        virtual ~DelayCodec(){};
        virtual string encode(const std::string &str){
            string prev = prev_str;
            prev_str = str;
            return prev;
        };
};

BaseCodec* getCodec(const string &name){
    if(name=="Reverse"){
        return new ReverseCodec;
    }
    if(name=="Compress"){
        return new CompressCodec;
    }
    if(name=="Delay"){
        return new DelayCodec;
    }
}
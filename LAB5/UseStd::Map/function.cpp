#include<cassert>
#include<iostream>
#include<map>
#include<ostream>
#include<string>
#include<set>
#include"function.h"

using namespace std;

namespace oj{
    void insert(map<int,String> &ma, int key, const string &str){
        map<int,String>::iterator itr = ma.find(key);
        if(itr != ma.end()){
            itr->second.str = str+itr->second.str;
        }
        else{
            String s = String(str);
            ma.insert({key, s});
        }
        return;
    }

    void output(const map<int,String> &ma, int begin, int end){
        for(auto &i: ma){
            if(i.first>=begin && i.first<=end)
                cout << i.second << ' ';
        }
        return;
    }

    void erase(map<int,String> &ma, int begin, int end){
        set<int> keys;
        for(auto &x : ma){
            if(x.first>=begin && x.first<=end){
                keys.insert(x.first);
            }
        }
        for(auto &x : keys){
            ma.erase(x);
        }
        return;    
    }

    std::ostream& operator<<(std::ostream &output ,const std::map<int,String> &ma){
        for(auto &itr : ma){
            output << itr.second << ' ';
        }
        return output;
    }
}


#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>

using namespace std;

struct cmp{
    bool operator()(const int& lhs, const int& rhs) const{
        return lhs < rhs;
    }
};

int getKey(vector<int> v){
    int size = v.size(); int key = 0;
    for(int i=0; i<size; i++){
        key += v[i]*(size-i);
    }
    return key;
}

void read(vector<int> &v){
    int num;
    while(cin >> num){
        if(num == 0) return;
        v.push_back(num);
    }
}

void print(vector<int> v){
    for(auto x: v){
        cout << x << ' ';
    }
    cout << '\n';
    return;
}

int main(){
    set< pair<int, vector<int>> > s;
    string cmd;
    while(cin >> cmd){
        if(cmd == "insert"){
            vector<int> v;

            read(v);

            int key = getKey(v);
            auto itr = s.begin();
            bool find = false;
            for(;itr!=s.end(); itr++){
                if(itr->first == key){
                    find = true; break;
                }
            }

            if(find){
                cout << "exist\n";
                s.erase(itr);
                reverse(v.begin(), v.end());
                s.insert(make_pair(key, v));
            }
            else{
                s.insert(make_pair(key, v));
            }
        }
        else if(cmd == "range_out"){
            vector<int> v1, v2;
            read(v1); read(v2);
            int key1 = getKey(v1);
            int key2 = getKey(v2);

            for(auto x: s){
                if(x.first >= key1 && x.first <= key2){
                    print(x.second);
                }
            }
        }
        else if(cmd == "output"){
            for(auto x: s){
                print(x.second);
            }
        }
    }
    return 0;
}
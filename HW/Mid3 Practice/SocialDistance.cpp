#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF INT_MAX

struct Seg{
    int l, r;
    Seg(int l, int r): l(l), r(r){};
};

struct Cmp{
    bool operator()(const Seg &lhs, const Seg &rhs) const{
        int l_len = (lhs.r - lhs.l)/2;
        int r_len = (rhs.r - rhs.l)/2;
        if(l_len == r_len){
            return lhs.l<rhs.l;
        }
        else{
            return l_len>r_len;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, s; cin >> n >> m >> s;
    int D = n+1; // !!!
    set<Seg, Cmp> c;
    int student[m+1][2];
    set<int> pos;

    pos.insert(0); // !!!
    pos.insert(n+1); // !!!
    c.insert(Seg(0, n+1)); // !!!

    for(int i=0; i<2*m; i++){
        string cmd;
        int x;
        cin >> cmd >> x;
        if(cmd=="i"){
            auto best = c.begin();
            int l = (*best).l;
            int r = (*best).r;
            int mid = (r+l)/2; // !!!
            if(l!=0){ // !!!
                D = min(mid-l, D);
            }
            if(r!=n+1){
                D = min(r-mid, D);
            }
            c.erase(best); // !!!
            c.insert(Seg(l, mid));
            c.insert(Seg(mid, r));
            pos.insert(mid);
            student[x][1] = mid;
        }
        else{
            int mid = student[x][1];
            int l = *(--pos.find(mid));
            int r = *(++pos.find(mid));
            c.erase(c.find(Seg(l, mid)));
            c.erase(c.find(Seg(mid, r)));
            c.insert(Seg(l, r));
            student[x][1] = -1;
            pos.erase(mid);
        }
    }

    if(D>=s){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

    if(D==n+1){
        cout << "INF\n";
    }
    else{
        cout << D << '\n';
    }
    
    return 0;
}
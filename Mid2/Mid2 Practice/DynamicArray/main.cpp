#include <iostream>
#include <cstdlib>
#include <string>
#include "function.h"
using namespace std;

class randGen {
private:
    unsigned int z1, z2, z3, z4;
public:
    randGen(int seed) {
        z1 = seed;
        z2 = seed << 10;
        z3 = seed << 20;
        z4 = seed << 30;
    };
    unsigned int next() {
        unsigned int b;
        b  = ((z1 << 6) ^ z1) >> 13;
        z1 = ((z1 & 4294967294U) << 18) ^ b;
        b  = ((z2 << 2) ^ z2) >> 27; 
        z2 = ((z2 & 4294967288U) << 2) ^ b;
        b  = ((z3 << 13) ^ z3) >> 21;
        z3 = ((z3 & 4294967280U) << 7) ^ b;
        b  = ((z4 << 3) ^ z4) >> 12;
        z4 = ((z4 & 4294967168U) << 13) ^ b;
        return (z1 ^ z2 ^ z3 ^ z4);
    }
};
const int mul = 9487;
const int mod = 99999989;
typedef long long ll;
class rollingHash {
    public:
    rollingHash() {
        hash = 0;
    }
    void push(int x) {
        hash = ((hash * mul) % mod + x) % mod;
    }
    ll getHash() {
        return hash;
    }
    private:
        ll hash;
};

int main() {
    int seed;
    cin >> seed;
    randGen rand(seed);
    rollingHash hash;
    // check single array
    {
        Darray arr;
        int t = 1000000;
        int check_len = rand.next() % t;
        for (int i = 0; i < t; i++) {
            int tmp = rand.next();
            arr.pushback(tmp);
            if (check_len == i) {
                int len = arr.length();
                hash.push(len);
            }
        }
        for (int i = 0; i < t / 2; i++) {
            int tmp = rand.next();
            int ind = rand.next() % arr.length();
            arr[ind] = tmp;
        }
        for (int i = 0; i < t; i++) {
            int ind = rand.next() % t;
            int out = arr[ind];
            hash.push(out);
            hash.push(ind);
        }
        arr.clear();
        int t2 = rand.next() % (t / 3);
        for (int i = 0; i < t2; i++) {
            int tmp = rand.next();
            arr.pushback(tmp);
        }
        for (int i = 0; i < t2 / 2; i++) {
            int ind = rand.next() % t2;
            int out = arr[ind];
            hash.push(out);
            hash.push(ind);
        }
    }
    // test multiple arr
    for (int x = 0; x < 4; x++) {
        Darray arr[100];
        int t = 1000000;
        int check_len = rand.next() % t;
        for (int i = 0; i < t; i++) {
            int ind = rand.next() % 100;
            int tmp = rand.next();
            arr[ind].pushback(tmp);
        }
        for (int i = 0; i < 100; i++) {
            hash.push(arr[i].length());
        }
        for (int i = 0; i < t / 10; i++) {
            int ind = rand.next() % 100;
            int ind2 = rand.next() % arr[ind].length();
            int tmp = rand.next();
            arr[ind][ind2] = tmp;
        }
        for (int i = 0; i < t; i++) {
            int ind = rand.next() % 100;
            int ind2 = rand.next() % arr[ind].length();
            hash.push(arr[ind][ind2]);
            hash.push(ind);
            hash.push(ind2);
        }
        for (int i = 0; i < 50; i++) {
            int ind = rand.next() % 100;
            arr[ind].clear();
            hash.push(arr[ind].length());
            hash.push(ind);
        }
        int t2 = t / 3;
        for (int i = 0; i < t2; i++) {
            int ind = rand.next() % 100;
            int tmp = rand.next();
            arr[ind].pushback(tmp);
        }
        for (int i = 0; i < 100; i++) {
            hash.push(arr[i].length());
            hash.push(arr[i].length());
        }
        for (int i = 0; i < t; i++) {
            int ind = rand.next() % 100;
            int ind2 = rand.next() % arr[ind].length();
            hash.push(arr[ind][ind2]);
            hash.push(ind);
            hash.push(ind2);
        }
    }
    cout << hash.getHash() << " AC\n";
    return 0;
}

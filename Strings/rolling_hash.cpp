# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B"
# include <bits/stdc++.h>
using namespace std;

//https://qiita.com/keymoon/items/11fac5627672a6d6a9f6

// char が 0-127 であることを利用していることに注意
struct rolling_hash {
    using ull = unsigned long long;

    const ull MASK30 = (1UL << 30) - 1;
    const ull MASK31 = (1UL << 31) - 1;
    const ull MOD = (1UL << 61) - 1;
    const ull MASK61 = MOD;
    const ull POSITIVIZER = MOD * ((1UL << 3) - 1);

    string s;
    int n;
    const ull bs = 23948798;

    vector<ull> base_pow;
    vector<ull> prefix_hash;

    rolling_hash(string _s){
        s = _s;
        n = int(s.size());
        base_pow.resize(n + 1);
        base_pow[0] = 1;
        for(int i = 0;i < n;i++){
            base_pow[i + 1] = calcmod(mul(base_pow[i], bs));
        }
        

        prefix_hash.resize(n + 1, 0LL);
        for(int i = 0;i < n;i++){
            prefix_hash[i + 1] = calcmod(mul(prefix_hash[i], bs) + s[i]);
            
        }
    }

    ull slice(int begin, int length){
        return calcmod(prefix_hash[begin + length] + POSITIVIZER - mul(prefix_hash[begin], base_pow[length]));
    }

    //a * b % mod (2^{61} - 1)
    ull mul(ull a, ull b){
        ull au = a >> 31;
        ull ad = a & MASK31;
        ull bu = b >> 31;
        ull bd = b & MASK31;
        ull mid = ad * bu + au * bd;
        ull midu = mid >> 30;
        ull midd = mid & MASK30;
        return calcmod(au * bu * 2 + midu + (midd << 31) + ad * bd);
    }

    // mod(2^{61} - 1)
    ull calcmod(ull x){
        ull xu = x >> 61;
        ull xd = x & MASK61;
        ull res = xu + xd;
        if (res >= MOD) res -= MOD;
        return res;
    }
};

int main(){
    string s, t;
    cin >> s >> t;
    string st = s + t;
    rolling_hash rh(st);

    for(int i = 0;i < (int)s.size() - (int)t.size() + 1;i++){
        if(rh.slice(i, (int)t.size()) == rh.slice((int)s.size(), (int)t.size())){
            cout << i << endl;
        }
    }
}
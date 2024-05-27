#include <bits/stdc++.h>
using namespace std;

# include "modint.cpp"

using mint = modint<998244353>;
//using mint = modint<1000000007>;

constexpr int max_combination = 1010101;

mint fact[max_combination], inv_fact[max_combination];

void combination_init(){
    fact[0] = 1, inv_fact[0] = 1;
    for(int i = 1;i < max_combination;i++){
        fact[i] = fact[i - 1];
        fact[i] *= i;
        inv_fact[i] = inv_fact[i - 1];
        inv_fact[i] /= i;
    }
}

mint nCr(int n, int r){
    if(fact[0].a == 0)combination_init();

    if(r < 0 || r > n)return 0;

    mint ret = fact[n];
    ret *= inv_fact[r];
    ret *= inv_fact[n - r];

    return ret;
}


// n個から, (a, b)個の組を作る時の場合の数
mint sub(int n, int a, int b) {
    if(a + b > n)return 0;
    return nCr(n, a) * nCr(n - a, b);
};

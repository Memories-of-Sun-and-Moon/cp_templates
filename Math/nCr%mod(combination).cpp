#include <bits/stdc++.h>
using namespace std;

# include "modint.cpp"

using modi = modint<998244353>;
//using modi = modint<1000000007>;

constexpr int max_combination = 1010101;

modi fact[max_combination];

void combination_init(){
    fact[0] = 1;
    for(int i = 1;i < max_combination;i++){
        fact[i] = fact[i - 1];
        fact[i] *= i;
    }
}

modi nCr(int n, int r){
    if(fact[0].a == 0)combination_init();

    if(r < 0 || r > n)return 0;

    modi ret = fact[n];
    ret /= fact[r];
    ret /= fact[n - r];

    return ret;
}

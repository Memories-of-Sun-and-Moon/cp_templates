#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include "./../../template/template.hpp"
#include "./../../math/factor.hpp"

using namespace mmrz;

void mmrz::solve(){
    int t;
    cin >> t;
    while(t--){
        ll a;
        cin >> a;
        vector<ll> ret = factor(a);
        int k = len(ret);
        cout << k;
        rep(i, k){
            cout << " " << ret[i];
        }
        cout << '\n';
    }
}

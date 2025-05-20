#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include "./../../template/template.hpp"
#include "./../../math/is_prime.hpp"

using namespace mmrz;

void mmrz::solve(){
    int t;
    cin >> t;
    while(t--){
        ll a;
        cin >> a;
        cout << (is_prime(a) ? "Yes" : "No") << '\n';
    }
}

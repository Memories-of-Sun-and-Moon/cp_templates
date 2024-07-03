#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include "./../../template/template.hpp"
#include "./../../string/manachar.hpp"

using namespace mmrz;

void mmrz::solve(){
    string s;
    cin >> s;
    vector<int> r = manachar(s);
    vector<int> ans(2*len(s)-1);
    rep(i, 2*len(s)-1){
        if(i%2){
            ans[i] = r[i]*2;
        }else{
            ans[i] = r[i]*2-1;
        }
    }
    rep(i, 2*len(s)-1){
        cout << ans[i] << " \n"[i == 2*len(s)-2];
    }
}

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DPL/1/DPL_1_D"

#include "./../../../template/template.hpp"
#include "./../../../z_other/longest_increasing_subsequences.hpp"

void mmrz::solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a)cin >> x;
    cout << longest_increasing_subsequences<true, int>(a) << '\n';
}

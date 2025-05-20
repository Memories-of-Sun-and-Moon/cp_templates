# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"

#include "./../../../template/template.hpp"
#include "./../../../graph/dinic.hpp"

using namespace mmrz;

void mmrz::solve(){
    int n, m;
    cin >> n >> m;
    dinic<int> f(n);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        f.add_edge(a, b, c);
    }
    cout << f.calc(0, n-1) << '\n';
}

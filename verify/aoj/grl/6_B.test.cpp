#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"

#include "./../../../template/template.hpp"
#include "./../../../graph/primal_dual.hpp"

using namespace mmrz;

void mmrz::solve(){
    int v, e, f;
    cin >> v >> e >> f;
    primal_dual<int> mcf(v);
    rep(i, e){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        mcf.add_edge(a, b, c, d);
    }
    cout << mcf.min_cost_flow(0, v-1, f).second << endl;
}

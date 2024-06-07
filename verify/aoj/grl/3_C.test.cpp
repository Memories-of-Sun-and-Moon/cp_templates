#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"

#include "./../../../template/template.hpp"
#include "./../../../graph/strongly_connected_components.hpp"

using namespace mmrz;

void mmrz::solve(){
	int n, m;
	cin >> n >> m;
	scc_graph g(n);
	while(m--){
		int a, b;
		cin >> a >> b;
		g.add_edge(a, b);
	}
	auto scc = g.scc();
	vector<int> cmp(n);
	rep(i, len(scc)){
		for(auto e : scc[i]){
			cmp[e] = i;
		}
	}
	int q;
	cin >> q;
	while(q--){
		int a, b;
		cin >> a >> b;
		cout << (cmp[a] == cmp[b] ? 1 : 0) << '\n';
	}
}

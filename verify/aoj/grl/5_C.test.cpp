#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include "./../../../template/template.hpp"
#include "./../../../graph/lowest_common_ancestor.hpp"

using namespace mmrz;

void mmrz::solve(){
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	rep(i, n){
		int k;
		cin >> k;
		while(k--){
			int c;
			cin >> c;
			g[i].pb(c);
			g[c].pb(i);
		}
	}

	lowest_common_ancestor lca(g, 0);

	int q;
	cin >> q;
	while(q--){
		int u, v;
		cin >> u >> v;
		cout << lca.get(u, v) << '\n';
	}
}

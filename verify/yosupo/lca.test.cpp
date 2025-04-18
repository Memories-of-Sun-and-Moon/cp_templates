#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "./../../template/template.hpp"
#include "./../../graph/lowest_common_ancestor.hpp"

void mmrz::solve(){
	int n, q;
	cin >> n >> q;
	vector<vector<int>> g(n);
	for(int i = 1;i < n;i++){
		int p;
		cin >> p;
		g[i].eb(p);
		g[p].eb(i);
	}

	lowest_common_ancestor lca(g, 0);

	while(q--){
		int u, v;
		cin >> u >> v;
		cout << lca.get(u, v) << '\n';
	}
}

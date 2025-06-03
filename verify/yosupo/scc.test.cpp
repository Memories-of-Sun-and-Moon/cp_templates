# define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "./../../template/template.hpp"
#include "./../../graph/strongly_connected_components.hpp"

void mmrz::solve(){
	int n, m;
	cin >> n >> m;
	scc_graph g(n);
	while(m--){
		int u, v;
		cin >> u >> v;
		g.add_edge(u, v);
	}
	vector<vector<int>> vs = g.scc();
	cout << len(vs) << '\n';
	for(auto &v : vs){
		cout << len(v);
		for(auto &x : v)cout << " " << x;
		cout << '\n';
	}
}

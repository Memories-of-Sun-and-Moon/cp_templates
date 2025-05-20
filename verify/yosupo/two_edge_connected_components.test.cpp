#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include "./../../template/template.hpp"
#include "./../../graph/two_edge_connected_components.hpp"

void mmrz::solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	while(m--){
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}

	auto [groups, comp, tree] = two_edge_connected_components(g);

	cout << len(groups) << '\n';
	for(auto v : groups){
		cout << len(v);
		for(auto c : v){
			cout << " " << c;
		}
		cout << '\n';
	}
}

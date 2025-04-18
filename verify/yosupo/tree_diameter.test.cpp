#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "./../../template/template.hpp"
#include "./../../graph/tree_diameter.hpp"

using namespace mmrz;

void mmrz::solve(){
	int n;
	cin >> n;
	vector<vector<pair<int, ll>>> g(n);
	rep(i, n-1){
		int a, b, c;
		cin >> a >> b >> c;
		g[a].eb(b, c);
		g[b].eb(a, c);
	}

	auto [diameter, path] = tree_diameter(g);

	cout << diameter << " " << len(path) << '\n';
	rep(i, len(path))cout << path[i] << " \n"[i == len(path)-1];
}

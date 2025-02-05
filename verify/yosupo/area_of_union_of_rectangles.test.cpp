#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"

#include "./../../template/template.hpp"
#include "./../../data_structure/area_of_union_of_rectangles.hpp"

void mmrz::solve(){
	int n;
	cin >> n;
	vector<tuple<int, int, int, int>> rectangles(n);
	for(auto &[l, d, r, u] : rectangles)cin >> l >> d >> r >> u;

	cout << area_of_union_rectangles<int>(rectangles).solve<ll>() << '\n';
}

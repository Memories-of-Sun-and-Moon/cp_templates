#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "./../../template/template.hpp"
#include "./../../data_structure/sparse_table.hpp"

using namespace mmrz;

void mmrz::solve(){
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(auto &x : a)cin >> x;
	sparse_table<int> table(a, [](int l, int r){return min(l, r);});
	while(q--){
		int l, r;
		cin >> l >> r;
		cout << table.fold(l, r) << '\n';
	}
}

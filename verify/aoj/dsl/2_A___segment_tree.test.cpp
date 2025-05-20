# define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include "./../../../template/template.hpp"
#include "./../../../data_structure/segment_tree.hpp"

void mmrz::solve(){
	int n, q;
	cin >> n >> q;
	auto combine = [](int a, int b){return min(a, b); };
	segment_tree<int> seg(n, combine, inf<int>());
	while(q--){
		int com, x, y;
		cin >> com >> x >> y;
		if(com)cout << seg.fold(x, y + 1) << '\n';
		else seg.set(x, y);
	}
}

# define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include "./../../../template/template.hpp"
#include "./../../../data_structure/segment_tree_0-indexed.hpp"

void mmrz::solve(){
	int n, q;
	cin >> n >> q;
	auto combine = [](ll a, ll b){return a+b; };
	segment_tree<ll> seg(n, combine, 0);
	while(q--){
		int com, x, y;
		cin >> com >> x >> y;
		x--;
		if(com)cout << seg.fold(x, y) << endl;
		else seg.set(x, seg[x]+y);
	}
}

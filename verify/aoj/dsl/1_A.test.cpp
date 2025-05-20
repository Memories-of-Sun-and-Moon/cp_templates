#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"

#include "./../../../template/template.hpp"
#include "./../../../data_structure/union_find.hpp"

void mmrz::solve(){
	int n, q;
	int com, x, y;
	cin >> n >> q;
	union_find uf(n);
	while(q--){
		cin >> com >> x >> y;
		if(com == 0)uf.unite(x, y);
		else cout << uf.is_same(x, y) << '\n';
	}
}

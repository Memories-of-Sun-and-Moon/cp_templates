#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include "./../../../template/template.hpp"
#include "./../../../data_structure/lazy_segment_tree.hpp"

using S = int;
using F = int;

S op(S a, S b){ return min(a, b); }
S e(){ return inf<int>(); }
S mapping(F f, S x){ return (f == -1 ? x : f); }
F composition(F f, F g){ return (f == -1 ? g : f); }
F id(){ return -1; }

void mmrz::solve(){
	int n, q;
	cin >> n >> q;

	lazy_segment_tree<S, op, e, F, mapping, composition, id> seg(n);

	while(q--){
		int op;
		cin >> op;
		if(op == 0){
			int s, t, x;
			cin >> s >> t >> x;
			t++;
			seg.apply(s, t, x);
		}else{
			int s, t;
			cin >> s >> t;
			t++;
			cout << seg.fold(s, t) << '\n';
		}
	}
}

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"

#include "./../../../template/template.hpp"
#include "./../../../data_structure/lazy_segment_tree.hpp"

using S = ll;
using F = ll;

S op(S a, S b){ return min(a, b); }
S e(){ return hinf<ll>(); }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

void mmrz::solve(){
	int n, q;
	cin >> n >> q;

	vector<ll> _v(n, 0LL);
	lazy_segment_tree<S, op, e, F, mapping, composition, id> seg(_v);

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
			cout << seg.fold(s, t) << endl;
		}
	}
}

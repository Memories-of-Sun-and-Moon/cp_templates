#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I"

#include "./../../../template/template.hpp"
#include "./../../../data_structure/lazy_segment_tree.hpp"

struct S{
	ll val;
	int size;
};
using F = ll;
constexpr F ID = -10000;

S op(S a, S b){ return {a.val+b.val, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){
	if(f != ID)x.val = f*x.size;
	return x;
}
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }

void mmrz::solve(){
	int n, q;
	cin >> n >> q;

	vector<S> _v(n, {0, 1});
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
			cout << seg.fold(s, t).val << '\n';
		}
	}
}

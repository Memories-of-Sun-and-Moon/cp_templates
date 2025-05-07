#define PROBLEM "https://yukicoder.me/problems/no/3078"

#include "./../../template/template.hpp"
#include "./../../data_structure/merge_sort_tree.hpp"

void mmrz::solve(){
	int n, q;
	cin >> n >> q;
	vector<ll> a(n);
	for(auto &x : a)cin >> x;
	merge_sort_tree<ll> mst(a);
	while(q--){
		int l, r;
		ll x;
		cin >> l >> r >> x;
		l--;
		ll cl = mst.count_less(l, r, x);
		ll sl = mst.sum_less(l, r, x);
		ll cr = mst.count_leq(l, r, x);
		ll sr = mst.sum_leq(l, r, x);
		cout << (sr-cr*x) + (cl*x-sl) << '\n';
	}
}

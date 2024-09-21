#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include "./../../template/template.hpp"
#include "./../../data_structure/mo.hpp"

using namespace mmrz;

void mmrz::solve(){
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(auto &x : a)cin >> x;
	if(q == 0){
		return;
	}
	if(n == 0){
		while(q--){
			int l, r, x;
			cin >> l >> r >> x;
			cout << 0 << endl;
		}
		return;
	}
	vector<pair<int, int>> lr(q);
	vector<int> x(q);
	rep(i, q){
		cin >> lr[i].first >> lr[i].second >> x[i];
	}

	{
		vector<int> v;
		for(auto &e : a)v.pb(e);
		for(auto &e : x)v.pb(e);
		sort(all(v));
		UNIQUE(v);
		map<int, int> cmp;
		rep(i, len(v))cmp[v[i]] = i;
		for(auto &e : a)e = cmp[e];
		for(auto &e : x)e = cmp[e];
	}

	Mo mo(lr);

	vector<int> cnt(n+q);

	auto add = [&](int idx) -> void {
		cnt[a[idx]]++;
	};

	auto erase = [&](int idx) -> void {
		cnt[a[idx]]--;
	};

	vector<int> ans(q);
	auto f = [&](int query_id) -> void {
		ans[query_id] = cnt[x[query_id]];
	};

	mo.calc(add, erase, f);

	rep(i, q){
		cout << ans[i] << '\n';
	}
}

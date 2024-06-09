#define PROBLEM "https://yukicoder.me/problems/no/274"

#include "./../../template/template.hpp"
#include "./../../graph/two_sat.hpp"

void mmrz::solve(){
	int n, m;
	cin >> n >> m;
	two_sat ts(n);
	vector<int> l(n), r(n);
	rep(i, n){
		cin >> l[i] >> r[i];
		r[i]++;
	}

	auto is_overlap = [&](int l1, int r1, int l2, int r2) -> bool {
		return not (r1 <= l2 || r2 <= l1);
	};

	rep(i, n){
		rep(j, n){
			if(i == j)continue;
			bool f1 = is_overlap(l[i], r[i], l[j], r[j]);
			bool f2 = is_overlap(l[i], r[i], m-r[j], m-l[j]);
			if(not f1 && not f2)continue;
			if(f1 && f2){
				cout << "NO" << endl;
				return;
			}
			if(f1){
				ts.add_if(i, true, j, false);
				ts.add_if(i, false, j, true);
			}
			if(f2){
				ts.add_if(i, true, j, true);
				ts.add_if(i, false, j, false);
			}
		}
	}
	auto ret = ts.solve();
	cout << (len(ret) ? "YES" : "NO") << endl;
}

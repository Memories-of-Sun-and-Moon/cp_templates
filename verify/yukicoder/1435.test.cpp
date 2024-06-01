#define PROBLEM "https://yukicoder.me/problems/no/1435"

#include "./../../template/template.hpp"
#include "./../../data_structure/segment_tree.hpp"

using namespace mmrz;

struct s{
	int m1, m2, mx;
	s(int _m1, int _m2, int _mx) : m1(_m1), m2(_m2), mx(_mx) {}
};

void mmrz::solve(){
	int n;
	cin >> n;
	segment_tree<s> seg(n, [](s l, s r) -> s {
		int m1 = min(l.m1, r.m1);
		int m2 = min({max(l.m1, r.m1), l.m2, r.m2});
		int mx = max(l.mx, r.mx);
		return s{m1, m2, mx};
	}, s{hinf<int>(), hinf<int>(), -1});

	rep(i, n){
		int a;
		cin >> a;
		seg.set(i, s{a, hinf<int>(), a});
	}

	ll ans = 0;
	auto check = [&](const s x) -> bool {
		return (x.m1 + x.m2 >= x.mx);
	};

	rep(l, n){
		int r = seg.max_right(check, l);
		ans += max<int>(0, r-l-1);
	}

	rep(r, n){
		int l = seg.max_right(check, r+1);
		ans += max<int>(0, (r + 1) - l - 1);
	}

	cout << ans << endl;

}

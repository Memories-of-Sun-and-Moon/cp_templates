#define PROBLEM "https://yukicoder.me/problems/no/3154"

#include "./../../template/template.hpp"
#include "./../../geometry/util.hpp"

using namespace mmrz;

void mmrz::solve(){
	int n;
	cin >> n;
	polygon ps(n);
	rep(i, n){
		cin >> ps[i].x >> ps[i].y;
	}
	auto qs = convex_hull(ps, false);
	cout << (len(qs) == n ? "Yes\n" : "No\n");
}

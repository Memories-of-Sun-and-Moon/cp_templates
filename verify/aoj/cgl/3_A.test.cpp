#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_3_A"

#include "./../../../template/template.hpp"
#include "./../../../geometry/util.hpp"

using namespace mmrz;

void mmrz::solve(){
	int n;
	cin >> n;
	vector<point> poly(n);
	for(auto &p : poly) cin >> p;

	cout << fixed << setprecision(1) << area(poly) << '\n';
}

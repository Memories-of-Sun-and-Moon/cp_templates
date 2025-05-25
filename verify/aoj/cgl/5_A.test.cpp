#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_5_A"
#define ERROR "1e-6"

#include "./../../../template/template.hpp"
#include "./../../../geometry/util.hpp"

using namespace mmrz;

void mmrz::solve(){
	int n;
	cin >> n;
	vector<point> ps(n);
	for(auto &p : ps)cin >> p;
	sort(ps.begin(), ps.end());
	cout << closest_pair(ps) << '\n';
}

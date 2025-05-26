#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_7_F"
#define ERROR "1e-6"

#include "./../../../template/template.hpp"
#include "./../../../geometry/util.hpp"

using namespace mmrz;

void mmrz::solve(){
	point p;
	cin >> p;
	circle c;
	cin >> c;
	auto [p1, p2] = tangent(c, p);
	if(p1.x > p2.x)swap(p1, p2);
	else if(fabs(p1.x - p2.x) < EPS && p1.y > p2.y)swap(p1, p2);
	cout << p1 << '\n' << p2 << '\n';
}

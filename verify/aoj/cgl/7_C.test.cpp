#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_7_C"
#define ERROR "1e-6"

#include "./../../../template/template.hpp"
#include "./../../../geometry/util.hpp"

using namespace mmrz;

void mmrz::solve(){
	point p;
	cin >> p;
	circle c;
	cin >> c;
	auto [a, b] = tangent(c, p);
	if(sgn(a.x-b.x) != -1)swap(a, b);
	if(sgn(a.y-b.y) != -1)swap(a, b);
	cout << a << '\n' << b << '\n';
}

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_7_B"
#define ERROR "1e-6"

#include "./../../../template/template.hpp"
#include "./../../../geometry/util.hpp"

using namespace mmrz;

void mmrz::solve(){
	point p1, p2, p3;
	cin >> p1 >> p2 >> p3;
	cout << incircle_of_a_triangle(p1, p2, p3) << '\n';
}

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_7_A"

#include "./../../../template/template.hpp"
#include "./../../../geometry/util.hpp"

using namespace mmrz;

void mmrz::solve(){
	circle a, b;
	cin >> a >> b;
	cout << intersect(a, b) << '\n';
}

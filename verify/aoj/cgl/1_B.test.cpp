#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B"
#define ERROR "1e-8"

#include "./../../../template/template.hpp"
#include "./../../../geometry/util.hpp"

using namespace mmrz;

void mmrz::solve(){
	line l;
	int q;
	cin >> l >> q;
	while(q--){
		point p;
		cin >> p;
		cout << reflect(l, p) << endl;
	}
}

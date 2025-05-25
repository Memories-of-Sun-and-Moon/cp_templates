#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_2_C"
#define ERROR "1e-8"

#include "./../../../template/template.hpp"
#include "./../../../geometry/util.hpp"

using namespace mmrz;

void mmrz::solve(){
	int q;
	cin >> q;
	while(q--){
		segment s1, s2;
		cin >> s1 >> s2;
		cout << get_crosspoint(s1, s2)[0] << '\n';
	}
}

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_2_B"

#include "./../../../template/template.hpp"
#include "./../../../geometry/util.hpp"

using namespace mmrz;

void mmrz::solve(){
	segment s1, s2;
	int q;
	cin >> q;
	while(q--){
		cin >> s1; 
		cin >> s2; 

		cout << intersect(s1, s2) << '\n';
	}
}

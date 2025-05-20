#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B"

#include "./../../../template/template.hpp"
#include "./../../../string/rolling_hash.hpp"

void mmrz::solve(){
	string s, t;
	cin >> s >> t;
	string st = s + t;
	rolling_hash rh(st);

	for(int i = 0;i < (int)s.size() - (int)t.size() + 1;i++){
		if(rh.slice(i, (int)t.size()) == rh.slice((int)s.size(), (int)t.size())){
			cout << i << '\n';
		}
	}
}

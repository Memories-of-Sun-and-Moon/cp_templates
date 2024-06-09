#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "./../../template/template.hpp"
#include "./../../string/suffix_array.hpp"

void mmrz::solve(){
	string s;
	cin >> s;
	suffix_array sa(s, false);
	reps(i, len(s)){
		cout << sa.sa[i] << " \n"[i == len(s)];
	}
}

#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include "./../../template/template.hpp"
#include "./../../string/suffix_array.hpp"

void mmrz::solve(){
	string s;
	cin >> s;
	suffix_array sa(s, true);
	ll ans = len(s)*(len(s)+1)/2;
	ans -= accumulate(all(sa.lcp), 0LL);
	cout << ans << '\n';
}

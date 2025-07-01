#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1642"

#include "./../../../template/template.hpp"
#include "./../../../math/factor.hpp"
#include "./../../../math/enumerate_divisors.hpp"

using namespace mmrz;

bool SOLVE(){
	ll n;
	cin >> n;
	if(n == 0)return 1;
	ll ans = 2+n;
	auto fs = enumerate_divisors(n);
	for(int i = 0;i < len(fs) && fs[i] <= n/fs[i] && fs[i]*fs[i] <= n/fs[i];i++){
		for(int j = i;j < len(fs) && fs[j] <= n/fs[j] && fs[i]*fs[j] <= n/fs[j];j++){
			if(n%(fs[i]*fs[j]))continue;
			chmin(ans, fs[i]+fs[j]+n/(fs[i]*fs[j]));
		}
	}
	cout << ans << '\n';
	return 0;
}

void mmrz::solve(){
	while(!SOLVE());
}

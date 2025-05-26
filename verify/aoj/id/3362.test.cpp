#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3362"

#include "./../../../template/template.hpp"
#include "./../../../math/extgcd.hpp"

using namespace mmrz;

bool SOLVE(){
	ll a, b;
	cin >> a >> b;
	if(a == 0 && b == 0)return 1;
	{
		int g = gcd(a, b);
		a /= g;
		b /= g;
	}
	ll x, y;
	extgcd(-a, b, y, x);

	if(a < 2*x){
		x = a-x;
		y = b-y;
	}

	cout << x << ' ' << y << '\n';
	return 0;
}

void mmrz::solve(){
	while(!SOLVE());
}

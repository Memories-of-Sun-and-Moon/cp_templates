#define PROBLEM "https://yukicoder.me/problems/no/3044"

#include "./../../template/template.hpp"
#include "./../../math/matrix.hpp"
#include "./../../math/modint.hpp"

using namespace mmrz;

using mint = modint<998244353>;

void SOLVE(){
	int n, t;
	int k, l;
	cin >> n >> t >> k >> l;

	matrix<mint> mat(t);

	mint a = mint(k-1)/mint(6);
	mint b = mint(l-k)/mint(6);
	mint c = mint(7-l)/mint(6);

	mat[0][0] = a;
	mat[0][1] = b;
	mat[0][t-1] = c;
	rep(i, t-1)mat[i+1][i] = 1;

	mat = matrix_power(mat, n-1);

	matrix<mint> iv(t, 1);
	auto f = [&](int x){
		return t-x-1;
	};
	iv[f(0)][0] = 1;
	rep(i, t){
		if(i+1 < t)iv[f(i+1)][0] += iv[f(i)][0]*a;
		if(i+2 < t)iv[f(i+2)][0] += iv[f(i)][0]*b;
	}
	
	matrix<mint> ans = mat*iv;
	cout << ans[f(0)][0] << '\n';
}

void mmrz::solve(){
	int t = 1;
	//cin >> t;
	while(t--)SOLVE();
}

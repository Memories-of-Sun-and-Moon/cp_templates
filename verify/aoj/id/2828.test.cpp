#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/sources/JAG/Prelim/2828"
#include "./../../../template/template.hpp"
#include "./../../../graph/hungarian.hpp"

using namespace mmrz;

void mmrz::solve(){
	int n;
	while(cin >> n && n){
		vector<vector<int>> mat(n, vector<int>(3));
		rep(i, n){
			rep(j, 3)cin >> mat[i][j];
			sort(all(mat[i]));
		}
		vector a(n, vector(n, 0LL));
		rep(i, n)rep(j, n){
			if(i == j)continue;
			bool flg = true;
			rep(k, 3)if(mat[i][k] <= mat[j][k])flg = false;
			if(not flg)continue;

			a[i][j] = mat[j][0]*mat[j][1]*mat[j][2];
		}

		vector<int> h = hungarian<false, ll>(a);

		ll ans = 0;
		rep(i, n){
			ans += mat[i][0]*mat[i][1]*mat[i][2];
		}
		rep(i, n){
			ans -= a[i][h[i]];
		}

		cout << ans << '\n';

	}
}

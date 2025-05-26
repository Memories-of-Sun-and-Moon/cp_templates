#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3205"

#include "./../../../template/template.hpp"
#include "./../../../graph/two_sat.hpp"

using namespace std;

bool SOLVE(){
	int n, m;
	cin >> n >> m;
	if(n == 0 && m == 0)return 1;

	vector<int> a(m), b(m);
	rep(i, m)cin >> a[i] >> b[i];

	// 閉区間
	auto f = [&](int left, int right) -> bool {
		two_sat ts(n);
		for(int i = left;i < right;i++){
			int I = abs(a[i]) - 1;
			bool F1 = (a[i] > 0);
			int J = abs(b[i]) - 1;
			bool F2 = (b[i] > 0);
			ts.add_clause(I, F1, J, F2);
		}
		auto ret = ts.solve();

		return not ret.empty();
	};

	int ans = 1;
	for(int left = 0;left < m;left++){
		if(left+ans > m)break;
		// ok_th
		if(not f(left, left+ans))continue;
		int ok = left+ans-1, ng = m;
		while(ng-ok > 1){
			int mid = (ok+ng)/2;
			(f(left, mid+1) ? ok : ng) = mid;
		}
		chmax(ans, ng-left);
	}
	
	cout << ans << '\n';
	return 0;
}

void mmrz::solve(){
	while(!SOLVE());
}

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3363"

#include "./../../../template/template.hpp"
#include "./../../../data_structure/segment_tree_2d.hpp"

// TLE SOLUTION

bool SOLVE(){
	int h, w;
	cin >> h >> w;
	if(h == 0 && w == 0)return 1;
	vector<vector<int>> f(h, vector<int>(w));
	rep(i, h)rep(j, w)cin >> f[i][j];
	segment_tree_2d<int> seg(h+w, h+w, [](int l, int r){return max(l, r);}, 0);
	rep(i, h)rep(j, w){
		int R = w + (i-j), C = (i+j);
		seg.set(R, C, f[i][j]);
	}
	vector<int> ans(h+w-1);
	rep(i, h)rep(j, w){
		int R = w + (i-j), C = (i+j);
		int ok = 0, ng = h+w-1;
		while(ng-ok > 1){
			int mid = (ok+ng)/2;
			(seg.fold(max(R-mid, 0), max(C-mid, 0), min(R+mid+1, h+w),  min(C+mid+1, h+w)) <= f[i][j] ? ok : ng) = mid;
		}
		ans[ok]++;
	}
	for(int i = h+w-3;i >= 1;i--){
		ans[i] += ans[i+1];
	}
	reps(i, h+w-2){
		cout << ans[i] << " \n"[i == h+w-2];
	}
	return 0;
}

void mmrz::solve(){
	while(!SOLVE());
}

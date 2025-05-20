#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B"

#include "./../../../template/template.hpp"
#include "./../../../data_structure/segment_tree_2d.hpp"

void mmrz::solve(){
    int n;
	cin >> n;
	const int  RC = 1050;
	segment_tree_2d<int> seg(RC, RC, [](auto l, auto r){return l+r;}, 0);
	while(n--){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		seg.set(y1, x1, seg.get(y1, x1)+1);
		seg.set(y1, x2, seg.get(y1, x2)-1);
		seg.set(y2, x1, seg.get(y2, x1)-1);
		seg.set(y2, x2, seg.get(y2, x2)+1);
	}
	int ans = 0;
	for(int i = 0;i < RC;i++)for(int j = 0;j < RC;j++)ans = max(ans, seg.fold(0, 0, i+1, j+1));
	cout << ans << '\n';
}

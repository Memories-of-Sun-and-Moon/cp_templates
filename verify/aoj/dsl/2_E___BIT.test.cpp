# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B"

#include "./../../../template/template.hpp"
#include "./../../../data_structure/binary_indexed_tree.hpp"

void mmrz::solve(){
	int n, q;
	cin >> n >> q;
	binary_indexed_tree<int> BIT(n);
	while(q--){
		int com;
		cin >> com;
		if(com == 0){
			int s, t, x;
			cin >> s >> t >> x;
			BIT.add(s, x);
			if(t+1 <= n)BIT.add(t+1, -x);
		}else{
			int t;
			cin >> t;
			cout << BIT.sum(t) << endl;
		}
	}
}

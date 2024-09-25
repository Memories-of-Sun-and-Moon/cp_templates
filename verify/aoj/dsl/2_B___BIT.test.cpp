# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B"

#include "./../../../template/template.hpp"
#include "./../../../data_structure/binary_indexed_tree.hpp"

void mmrz::solve(){
	int n, q;
	cin >> n >> q;
	binary_indexed_tree<int> BIT(n);
	while(q--){
		int com, x, y;
		cin >> com >> x >> y;
		if(com == 0){
			BIT.add(x, y);
		}else{
			cout << BIT.sum(y) - (x != 1 ? BIT.sum(x - 1) : 0) << endl;
		}
	}
}

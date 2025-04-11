#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include "./../../template/template.hpp"
#include "./../../data_structure/binary_trie.hpp"

using namespace mmrz;

void mmrz::solve(){
	int q;
	cin >> q;
	binary_trie<int, 29> trie;
	while(q--){
		int op, x;
		cin >> op >> x;
		if(op == 0){
			if(trie.count(x) == 0)trie.add(x);
		}else if(op == 1){
			if(trie.count(x) != 0)trie.erase(x);
		}else{
			cout << trie.min_element(x).first << '\n';
		}
	}
}

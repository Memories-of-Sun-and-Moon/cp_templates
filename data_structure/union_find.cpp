# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"
# include "bits/stdc++.h"
using namespace std;

struct union_find {
	vector<int> v;

	union_find(size_t size) : v(size, -1) {}

	int root(int x){
		return (v[x] < 0 ? x : v[x] = root(v[x]));
	}

	bool is_root(int x){
		return root(x) == x;
	}

	void unite(int x, int y){
		x = root(x);
		y = root(y);
		if(x != y){
			if(v[x] > v[y])swap(x, y);
			v[x] += v[y];
			v[y] = x;
		}
	}

	bool same(int x,int y){
		return root(x) == root(y);
	}

	int get_size(int x){
		x = root(x);
		return -v[x];
	}
};

int n, q;
int com, x, y;

int main(){
	cin >> n >> q;
	union_find uf(n);
	while(q--){
		cin >> com >> x >> y;
		if(com == 0)uf.unite(x, y);
		else cout << uf.same(x, y) << endl;
	}
}

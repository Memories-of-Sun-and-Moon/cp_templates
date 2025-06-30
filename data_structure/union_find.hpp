
#include<cassert>
#include<vector>

struct union_find {
	std::vector<int> v;
	int g_size;
	int n;

	union_find(size_t size) : v(size, -1), g_size(size), n(size) {}

	int root(int x){
		assert(x < n);
		return (v[x] < 0 ? x : v[x] = root(v[x]));
	}

	bool is_root(int x){
		assert(x < n);
		return root(x) == x;
	}

	bool unite(int x, int y){
		assert(x < n && y < n);
		x = root(x);
		y = root(y);
		if(x != y){
			if(v[x] > v[y])std::swap(x, y);
			v[x] += v[y];
			v[y] = x;
			g_size--;
			return true;
		}
		return false;
	}

	bool is_same(int x,int y){
		assert(x < n && y < n);
		return root(x) == root(y);
	}

	int get_size(int x){
		assert(x < n);
		x = root(x);
		return -v[x];
	}

	int groups_size(){
		return g_size;
	}

	std::vector<std::vector<int>> groups(){
		std::vector<std::vector<int>> member(n);
		for(int i = 0;i < n;i++){
			member[root(i)].push_back(i);
		}

		std::vector<std::vector<int>> ret;
		for(int i = 0;i < n;i++){
			if(member[i].empty())continue;
			ret.push_back(member[i]);
		}
		return ret;
	}
};

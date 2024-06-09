
struct union_find {
	vector<int> v;
	int g_size;

	union_find(size_t size) : v(size, -1), g_size(size) {}

	int root(int x){
		return (v[x] < 0 ? x : v[x] = root(v[x]));
	}

	bool is_root(int x){
		return root(x) == x;
	}

	bool unite(int x, int y){
		x = root(x);
		y = root(y);
		if(x != y){
			if(v[x] > v[y])swap(x, y);
			v[x] += v[y];
			v[y] = x;
			g_size--;
			return true;
		}
		return false;
	}

	bool is_same(int x,int y){
		return root(x) == root(y);
	}

	int get_size(int x){
		x = root(x);
		return -v[x];
	}

	int groups_size(){
		return g_size;
	}
};

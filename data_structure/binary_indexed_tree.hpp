
template<typename T>struct binary_indexed_tree {
	int n;
	vector<T> BIT;
	binary_indexed_tree(int n_) : n(n_ + 1), BIT(n, 0) {}

	void add(int i, T x){
		for(int idx = i;idx < n;idx += (idx & -idx)){
			BIT[idx] += x;
		}
	}

	T sum(int i) {
		T ret = 0;
		for(int idx = i;idx > 0;idx -= (idx & -idx)){
			ret += BIT[idx];
		}
		return ret;
	}
};

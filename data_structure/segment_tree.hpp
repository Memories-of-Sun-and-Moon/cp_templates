
template<typename T>struct segment_tree {
	using F = function<T(T, T)>;

	int offset;
	int n;
	vector<T> node;
	F combine;
	T identify;

	segment_tree(int _n, F _combine, T _identify) : segment_tree(vector<T>(_n, _identify), _combine, _identify) {}

	segment_tree(const vector<T> &v, F _combine, T _identify) : n((int)v.size()), combine(_combine), identify(_identify) {
		n = (int)v.size();
		offset = 1;
		while(offset < n)offset <<= 1;

		node.resize(2*offset, identify);

		for(int i = 0;i < n;i++)node[i + offset] = v[i];
		for(int i = offset - 1;i >= 1;i--)node[i] = combine(node[2 * i + 0], node[2 * i + 1]);
	}

	T operator[](int x) {return node[x + offset]; }

	void set(int x, T val){
		assert(0 <= x && x < n);
		x += offset;

		node[x] = val;
		while(x >>= 1){;
			node[x] = combine(node[2 * x + 0], node[2 * x + 1]);
		}
	}

	T fold(int l, int r){
		assert(0 <= l && l <= r && r <= n);
		if(l == r)return identify;

		T L = identify, R = identify;
		for(l += offset, r += offset; l < r;l >>= 1, r >>= 1){
			if(l&1)L = combine(L, node[l++]);
			if(r&1)R = combine(node[r--], R);
		}
		return combine(L, R);
	}

	T all_fold() { return node[1]; };

	int max_right(const function<bool(T)> f, int l = 0){
		assert(0 <= l && l <= n);
		assert(f(identify));

		if(l == n)return n;
		
		l += offset;
		T sum = identify;
		do{
			while(l%2 == 0)l >>= 1;
			if(not f(combine(sum, node[l]))){
				while(l < offset){
					l <<= 1;
					if(f(combine(sum, node[l]))){
						sum = combine(sum, node[l]);
						l++;
					}
				}
				return l - offset;
			}
			sum = combine(sum, node[l]);
			l++;
		}while((l&-l) != l);
		return n;
	}

	int min_left(const function<bool(T)> f, int r = -1){
		if(r == 0)return 0;
		if(r == -1)r = n;
		r += offset;
		T sum = identify;
		do{
			r--;
			while(r > 1 && (r % 2))r >>= 1;
			if(not f(combine(node[r], sum))){
				while(r < offset){
					r = r*2 + 1;
					if(f(combine(node[r], sum))){
						sum = combine(node[r], sum);
						r--;
					}
				}
				return r+1 - offset;
			}
			sum = combine(node[r], sum);
		}while((r&-r) != r);
		return 0;
	}
};

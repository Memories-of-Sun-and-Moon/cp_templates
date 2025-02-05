
template<class S, auto op, auto e, class F, auto mapping, auto composition, auto id>
struct lazy_segment_tree {
private:
	int n;
	int log;
	int size;
	vector<S> node;
	vector<F> lazy;

	void update(int k) { node[k] = op(node[2 * k], node[2 * k + 1]); }
	void all_apply(int k, F f) {
		node[k] = mapping(f, node[k]);
		if(k < size) lazy[k] = composition(f, lazy[k]);
	}
	void push(int k) {
		all_apply(2*k + 0, lazy[k]);
		all_apply(2*k + 1, lazy[k]);
		lazy[k] = id();
	}
public:
	lazy_segment_tree() : lazy_segment_tree(0) {}

	lazy_segment_tree(int _n) : lazy_segment_tree(vector<S>(_n, e())) {}

	lazy_segment_tree(const vector<S> &v) : n((int)v.size()) {
		size = 1;
		while(size < n) size <<= 1;

		log = __builtin_ctz(size);

		node.resize(2*size, e());
		lazy.resize(size, id());

		for(int i = 0;i < n;i++)node[i + size] = v[i];
		for(int i = size-1;i >= 1;i--)node[i] = op(node[2*i + 0], node[2*i + 1]);
	}

	void set(int x, S val) {
		assert(0 <= x && x < n);
		x += size;

		for(int i = log;i >= 1;i--)push(x >> i);
		node[x] = val;
		for(int i = 1;i <= log;i++)update(x >> i);
	}

	S operator[](int x) {
		assert(0 <= x && x < n);
		x += size;

		for(int i = log;i >= 1;i--)push(x >> i);
		return node[x];
	}

	S fold(int l, int r) {
		assert(0 <= l && l <= r && r <= n);
		if(l == r)return e();

		l += size;
		r += size;

		for(int i = log;i >= 1;i--) {
			if(((l >> i) << i) != l)push(l >> i);
			if(((r >> i) << i) != r)push((r-1) >> i);
		}

		S L = e(), R = e();
		for(;l < r;l >>= 1, r >>= 1){
			if(l&1)L = op(L, node[l++]);
			if(r&1)R = op(node[--r], R);
		}
		return op(L, R);
	}

	S all_fold() { return node[1]; };

	void apply(int x, F f) {
		assert(0 <= x && x < n);

		x += size;
		for(int i = log;i >= 1;i--)push(x >> i);
		node[x] = mapping(f, node[x]);
		for(int i = 1;i <= log;i++)update(x >> i);
	}

	void apply(int l, int r, F f) {
		assert(0 <= l && l <= r && r <= n);
		if(l == r)return;

		l += size;
		r += size;

		for(int i = log;i >= 1;i--) {
			if(((l >> i) << i) != l)push(l >> i);
			if(((r >> i) << i) != r)push((r-1) >> i);
		}

		{
			int l2 = l, r2 = r;
			while (l < r) {
				if (l & 1) all_apply(l++, f);
				if (r & 1) all_apply(--r, f);
				l >>= 1;
				r >>= 1;
			}
			l = l2;
			r = r2;
		}

		for (int i = 1; i <= log; i++) {
			if (((l >> i) << i) != l) update(l >> i);
			if (((r >> i) << i) != r) update((r - 1) >> i);
		}
	}

	template<bool (*g)(S)> int max_right(int l) {
		return max_right(l, [](S x){ return g(x); });
	}
	template<class G> int max_right(int l, G g) {
		assert(0 <= l && l <= n);
		assert(g(e()));

		if(l == n)return n;

		l += size;
		for(int i = log;i >= 1;i--)push(l >> i);

		S sum = e();
		do {
			while(l%2 == 0)l >>= 1;
			if(not g(op(sum, node[l]))) {
				while(l < size) {
					push(l);
					l <<= 1;
					if(g(op(sum, node[l]))) {
						sum = op(sum, node[l]);
						l++;
					}
				}
				return l-size;
			}
			sum = op(sum, node[l]);
			l++;
		}while((l&-l) != l);
		return n;
	}

	template <bool (*g)(S)> int min_left(int r) {
		return min_left(r, [](S x) { return g(x); });
	}
	template<class G> int min_left(int r, G g) {
		assert(0 <= r && r <= n);
		assert(g(e()));

		if(r == 0)return 0;

		r += size;
		for(int i = log;i >= 1;i--)push((r-1) >> i);

		S sum = e();
		do {
			r--;
			while(r > 1 && (r%2))r >>= 1;
			if(not g(op(node[r], sum))) {
				while(r < size) {
					push(r);
					r = r*2 + 1;
					if(g(op(node[r], sum))) {
						sum = op(node[r], sum);
						r--;
					}
				}
				return r+1-size;
			}
			sum = op(node[r], sum);
		}while((r&-r) != r);
		return 0;
	}
};

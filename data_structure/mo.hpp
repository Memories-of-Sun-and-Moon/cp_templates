class Mo {
	std::vector<std::pair<int, int>> lr;
public:
	Mo() = default;
	Mo(const std::vector<std::pair<int, int>> &_lr) : lr(_lr) {}

	template<typename AL, typename AR, typename EL, typename ER, typename F>
	void calc(const AL &add_left, const AR &add_right, const EL &erase_left, const ER& erase_right, const F &f, int _n = -1, int _B = -1){
		int n = (_n == -1 ? ranges::max(lr, {}, &std::pair<int, int>::second).second : _n);
		int q = (int)lr.size();
		int B = (_B == -1 ? max(1, n/int(sqrt(q))) : _B);

		std::vector<int> index(q);
		iota(index.begin(), index.end(), 0);
		sort(index.begin(), index.end(), [&](int i, int j){
			const auto &[l_i, r_i] = lr[i];
			const auto &[l_j, r_j] = lr[j];
			const int B_i = l_i / B, B_j = l_j / B;
			if(B_i != B_j){
				return B_i < B_j;
			}
			if(B_i & 1){
				return r_j < r_i;
			}else{
				return r_i < r_j;
			}
		});

		int l = 0, r = 0;
		for(int idx : index){
			const auto &[L, R] = lr[idx];

			while(L < l)add_left(--l);
			while(r < R)add_right(r++);
			
			while(l < L)erase_left(l++);
			while(R < r)erase_right(--r);

			f(idx);
		}
	}

	template<typename A, typename E, typename F>
	void calc(const A &add, const E &erase, const F &f){
		calc(add, add, erase, erase, f);
	}
};

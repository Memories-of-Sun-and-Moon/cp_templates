
// argmin(i,l,r) : argmin_{j\in[l,r)} A[i][j]
template<typename F>
vector<int> monotone_minima(int n, int m, const F &argmin){
	vector<int> ret(n);

	//submatrix [u, d) * [l, r)
	queue<tuple<int, int, int, int>> q;
	q.push({0, n, 0, m});

	while(not q.empty()){
		auto [u, d, l, r] = q.front();
		q.pop();

		if(u == d)continue;
		int mid = (u+d) >> 1;
		ret[mid] = argmin(mid, l, r);
		q.push({u, mid, l, ret[mid]+1});
		q.push({mid+1, d, ret[mid], r});
	}

	return ret;
}

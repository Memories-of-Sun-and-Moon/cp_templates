
#pragma once

#include<queue>
#include<tuple>
#include<vector>

// argmin(i,l,r) : argmin_{j\in[l,r)} A[i][j]
template<typename F>
std::vector<int> monotone_minima(int n, int m, const F &argmin){
	std::vector<int> ret(n);

	//submatrix [u, d) * [l, r)
	std::queue<std::tuple<int, int, int, int>> q;
	q.emplace(0, n, 0, m);

	while(not q.empty()){
		auto [u, d, l, r] = q.front();
		q.pop();

		if(u == d)continue;
		int mid = (u+d) >> 1;
		ret[mid] = argmin(mid, l, r);
		q.emplace(u, mid, l, ret[mid]+1);
		q.emplace(mid+1, d, ret[mid], r);
	}

	return ret;
}

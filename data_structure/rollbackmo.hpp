#pragma once

#include<algorithm>
#include<cmath>
#include<ranges>
#include<utility>
#include<vector>

class RollbackMo {
	std::vector<std::pair<int, int>> lr;
public:
	RollbackMo() = default;
	RollbackMo(const std::vector<std::pair<int, int>> &_lr) : lr(_lr) {}

	template<typename AL, typename AR, typename RST, typename SNP, typename RB, typename F>
	void calc(const AL &add_left, const AR &add_right, const RST &reset, const SNP &snapshot, const RB &rollback, const F &f,  int _n = -1, int _B = -1){
		int n = (_n == -1 ? std::ranges::max(lr, {}, &std::pair<int, int>::second).second : _n);
		int q = (int)lr.size();
		int B = (_B == -1 ? std::max(1, n/int(sqrt(q))) : _B);

		auto naive = [&](int idx) -> void {
			snapshot();
			const auto &[l, r] = lr[idx];
			for(int i = l;i < r;i++)add_right(l, i);
			f(idx);
			rollback();
		};

		std::vector<std::vector<int>> index((n+B-1)/B);
		index.reserve(q);
		for(int i = 0;i < q;i++){
			auto &[l, r] = lr[i];
			if(l/B == r/B)naive(i);
			else index[l/B].emplace_back(i);
		}

		for(auto &v : index){
			if(v.empty())continue;
			sort(v.begin(), v.end(), [&](int i, int j){
				const auto &[l_i, r_i] = lr[i];
				const auto &[l_j, r_j] = lr[j];
				return r_i < r_j;
			});
			int LMAX = 0;
			for(auto &idx : v){
				auto &[l, r] = lr[idx];
				LMAX = std::max(LMAX, l);
			}
			reset();
			int l = LMAX, r = LMAX;
			for(auto &idx : v){
				auto &[L, R] = lr[idx];
				while(r < R)add_right(l, r++);
				snapshot();
				while(L < l)add_left(--l, r);
				f(idx);
				rollback();
				l = LMAX;
			}
		}
	}
};

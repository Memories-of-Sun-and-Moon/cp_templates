
#pragma once

#include<algorithm>
#include<vector>

template<typename T>
struct merge_sort_tree {
	int n;
	std::vector<std::vector<T>> x, cs;
	merge_sort_tree(const std::vector<T> &v) : n(std::ssize(v)) {
		x.resize(n*2);
		cs.resize(n*2);
		for(int i = 0;i < n;i++)x[n+i] = {v[i]}, cs[n+i] = {0, v[i]};
		for(int i = n-1;i > 0;i--){
			std::merge(x[i*2].begin(), x[i*2].end(), x[i*2 + 1].begin(), x[i*2 + 1].end(), std::back_inserter(x[i]));
			cs[i].resize(std::ssize(x[i]) + 1);
			for(int j = 0;j < std::ssize(x[i]);j++){
				cs[i][j+1] += cs[i][j] + x[i][j];
			}
		}
	}
	int count_less(int l, int r, T q) {
		l += n, r += n;
		int ret = 0;
		while(l < r) {
			if(l & 1){
				ret += std::lower_bound(x[l].begin(), x[l].end(), q) - x[l].begin();
				l++;
			}
			if(r & 1){
				r--;
				ret += std::lower_bound(x[r].begin(), x[r].end(), q) - x[r].begin();
			}
			l >>= 1, r >>= 1;
		}
		return ret;
	}

	int count_leq(int l, int r, T q) {
		l += n, r += n;
		int ret = 0;
		while(l < r) {
			if(l & 1){
				ret += x[l].end() - std::lower_bound(x[l].begin(), x[l].end(), q);
				l++;
			}
			if(r & 1){
				r--;
				ret += x[r].end() - std::lower_bound(x[r].begin(), x[r].end(), q);
			}
			l >>= 1, r >>= 1;
		}
		return ret;
	}

	T sum_less(int l, int r, T q) {
		l += n, r += n;
		T ret = 0;
		while(l < r) {
			if(l & 1){
				ret += cs[l][std::lower_bound(x[l].begin(), x[l].end(), q) - x[l].begin()];
				l++;
			}
			if(r & 1){
				r--;
				ret += cs[r][std::lower_bound(x[r].begin(), x[r].end(), q) - x[r].begin()];
			}
			l >>= 1, r >>= 1;
		}
		return ret;
	}

	T sum_leq(int l, int r, T q) {
		l += n, r += n;
		T ret = 0;
		while(l < r) {
			if(l & 1){
				ret += cs[l].back() - cs[l][std::lower_bound(x[l].begin(), x[l].end(), q) - x[l].begin()];
				l++;
			}
			if(r & 1){
				r--;
				ret += cs[r].back() - cs[r][std::lower_bound(x[r].begin(), x[r].end(), q) - x[r].begin()];
			}
			l >>= 1, r >>= 1;
		}
		return ret;
	}
};

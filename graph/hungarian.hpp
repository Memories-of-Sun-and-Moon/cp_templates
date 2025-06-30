
#pragma once

#include<limits>
#include<numeric>
#include<vector>

template<bool is_min, typename T>
std::vector<int> hungarian(std::vector<std::vector<T>> a) {
	T infty = std::numeric_limits<T>::max()/T(2);
	int n = (int)a.size();
	
	if(not is_min){
		for(int i = 0;i < n;i++){
			for(int j = 0; j < n;j++){
				a[i][j] = -a[i][j];
			}
		}
	}

	std::vector<int> p(n);
	std::iota(p.begin(), p.end(), 0);

	std::vector<T> h = {0};
	h.reserve(n);
	for(int i = 1;i < n;i++){
		h.push_back(0);
		std::vector<T> d(i+1, infty);
		std::vector<int> pre(i+1, -1);
		std::vector<bool> used(i+1, false);

		d[i] = 0;
		pre[i] = i;

		for(int _ = 0;_ <= i;_++){
			T min_d = infty;
			int v = -1;
			for(int j = 0;j <= i;j++){
				if(not used[j] && min_d > d[j]-h[j]){
					min_d = d[j]-h[j];
					v = j;
				}
			}
				
			used[v] = true;

			for(int j = 0;j <= i;j++){
				if(not used[j] || j == i){
					T nd = d[v] - a[v][p[v]] + a[j][p[v]];
					if(d[j] > nd){
						d[j] = nd;
						pre[j] = v;
					}
				}
			}
		}

		int cur = i;
		while(pre[cur] != i){
			std::swap(p[cur], p[pre[cur]]);
			cur = pre[cur];
		}
		h = d;
	}
	return p;
}

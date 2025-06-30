
#include<numeric>
#include<vector>

template <typename T> struct suffix_array {
	T s;
	std::vector<int> sa;
	std::vector<int> rank;
	std::vector<int> lcp;

	suffix_array(const T &str, bool gen_lcp = true) : s(str) {
		int n = (int)s.size();
		sa.resize(n+1);
		std::iota(sa.begin(), sa.end(), 0);
		rank.assign(n+1, -1);
		for(int i = 0;i < n;i++){
			rank[i] = s[i];
		}
		std::vector<int> tmp(n+1);
		int k;
		auto comp_sa = [&](int i, int j) -> bool {
			if(rank[i] != rank[j])return rank[i] < rank[j];
			int ri = i + k <= n ? rank[i+k] : -1;
			int rj = j + k <= n ? rank[j+k] : -1;
			return ri < rj;
		};
		for(k = 1;k <= n;k *= 2){
			sort(sa.begin(), sa.end(), comp_sa);
			tmp[sa[0]] = 0;
			for(int i = 1;i <= n;i++){
				tmp[sa[i]] = tmp[sa[i-1]] + (comp_sa(sa[i-1], sa[i]) ? 1 : 0);
			}
			rank = tmp;
		}

		if(not gen_lcp)return;

		lcp.assign(n, 0);
		int h = 0;
		for(int i = 0;i < n;i++){
			int j = sa[rank[i]-1];
			if(h)h--;
			for(;j+h < n and i+h < n;h++){
				if(s[j+h] != s[i+h])break;
			}
			lcp[rank[i]-1] = h;
		}
	}
};

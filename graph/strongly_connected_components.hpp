
#pragma once

#include<vector>

struct scc_graph {
	int n;
	int k;
	std::vector<std::vector<int>> g;
	std::vector<std::vector<int>> rg;
	std::vector<bool> used;
	std::vector<int> cmp;
	std::vector<int> vs;

	scc_graph(int _n) : n(_n), k(0), g(n), rg(n), used(n), cmp(n) {}

	void add_edge(int a, int b) {
		g[a].push_back(b);
		rg[b].push_back(a);
	}

	void dfs(int v){
		used[v] = true;
		for(auto to : g[v]){
			if(not used[to])dfs(to);
		}
		vs.push_back(v);
	}

	void rdfs(int v, int col){
		used[v] = true;
		cmp[v] = col;
		for(auto to : rg[v]){
			if(not used[to])rdfs(to, col);
		}
	}

	std::vector<std::vector<int>> scc() {
		for(int i = 0;i < n;i++){
			if(not used[i])dfs(i);
		}
		for(int i = 0;i < n;i++){
			used[i] = false;
		}
		for(auto i = vs.rbegin();i != vs.rend();i++){
			if(not used[*i])rdfs(*i, k++);
		}
		std::vector<std::vector<int>> ret(k);
		for(int i = 0;i < n;i++){
			ret[cmp[i]].push_back(i);
		}
		return ret;
	}
};

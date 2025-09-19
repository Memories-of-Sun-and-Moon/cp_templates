#pragma once

#include "./dinic.hpp"

#include<vector>
#include<ranges>

vector<pair<int, int>> bipartite_matching(const int &l, const int &r, const vector<pair<int, int>> &es) {

	dinic<int> matching(l+r+2);
	const int S = l+r+0;
	const int T = l+r+1;

	for(int i = 0;i < l;i++)matching.add_edge(S, i, 1);
	for(int i = 0;i < r;i++)matching.add_edge(l+i, T, 1);
	for(auto [u, v] : es){
		matching.add_edge(u, l+v, 1);
	}

	matching.calc(S, T);

	std::vector<pair<int, int>> ret;
	
	// C++23
	// for(auto [idx, edge] : es | std::views::enumerate) {
	for(int idx = 0;idx < ssize(es);idx++){
		auto &edge = es[idx];
		if(matching.get_flow(l+r+idx) == 1){
			ret.emplace_back(edge);
		}
	}

	return ret;
}

#pragma once

#include "../data_structure/union_find.hpp"
#include "./lowlink.hpp"

#include<cassert>
#include<tuple>

auto two_edge_connected_components(std::vector<std::vector<int>> &g){
	lowlink l(g);
	union_find uf((int)g.size());
	for(int i = 0;i < (int)g.size();i++){
		for(int to : g[i]){
			if(not l.is_bridge(i, to)){
				uf.unite(i, to);
			}
		}
	}

	std::vector<std::vector<int>> group = uf.groups();
	std::vector<int> comp((int)g.size());
	for(int i = 0;i < (int)group.size();i++){
		for(int v : group[i]){
			comp[v] = i;
		}
	}

	std::vector<std::vector<int>> tree((int)group.size());
	for(int i = 0;i < (int)g.size();i++){
		for(int to : g[i]){
			if(comp[i] != comp[to]){
				tree[comp[i]].push_back(comp[to]);
			}
		}
	}

	return make_tuple(group, comp, tree);
}

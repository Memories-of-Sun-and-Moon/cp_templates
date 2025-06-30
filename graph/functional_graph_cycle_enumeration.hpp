
#pragma once

#include<vector>

std::vector<std::vector<int>> functional_graph_cycle_enumeration(std::vector<int> a){
	std::vector<std::vector<int>> ret;
	int n = (int)a.size();
	std::vector vis(n, 0);
	for(int i = 0;i < n;i++){
		if(vis[i] != 0)continue;
		int cur = i;
		while(vis[cur] == 0){
			vis[cur] = 1;
			cur = a[cur];
		}
		if(vis[cur] == 1){
			int cnt = 0;
			int u = cur;
			std::vector<int> v;
			do{
				cnt++;
				v.emplace_back(u);
				u = a[u];
			}while(u != cur);
			ret.emplace_back(v);
		}
		for(int v = i;vis[v] != 2;v = a[v]){
			vis[v] = 2;
		}
	}
	return ret;
}

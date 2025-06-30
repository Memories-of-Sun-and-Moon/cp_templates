
#include<numeric>
#include<vector>
#include<utility>
#include<queue>

template<typename T=long long>
std::pair<T, std::vector<int>> tree_diameter(const std::vector<std::vector<std::pair<int, T>>> &g){
	int n = (int)g.size();
	std::vector dis(n, std::numeric_limits<T>::max());
	std::queue<int> q;
	dis[0] = 0;
	q.push(0);

	while(not q.empty()){
		int v = q.front();
		q.pop();
		for(auto [to, c] : g[v]){
			if(dis[to] != std::numeric_limits<T>::max())continue;
			dis[to] = dis[v]+c;
			q.push(to);
		}
	}

	int r1 = -1;
	T mx = 0;
	for(int v = 0;v < n;v++){
		if(chmax(mx, dis[v])){
			r1 = v;
		}
	}

	dis.assign(n, std::numeric_limits<T>::max());
	std::vector<int> par(n, -1);
	dis[r1] = 0;
	q.push(r1);

	while(not q.empty()){
		int v = q.front();
		q.pop();
		for(auto [to, c] : g[v]){
			if(dis[to] != std::numeric_limits<T>::max())continue;
			dis[to] = dis[v]+c;
			par[to] = v;
			q.push(to);
		}
	}

	int r2 = -1;
	T diameter = 0;
	for(int v = 0;v < n;v++){
		if(chmax(diameter, dis[v])){
			r2 = v;
		}
	}

	std::vector<int> path;
	for(int cur = r2;cur != -1;cur = par[cur]){
		path.emplace_back(cur);
	}

	return {diameter, path};
}

std::pair<int, std::vector<int>> tree_diameter(const std::vector<std::vector<int>> &g_unweighted){
	int n = (int)g_unweighted.size();
	std::vector<std::vector<std::pair<int, int>>> g(n);

	for(int u = 0;u < n;u++){
		for(int v : g_unweighted[u]){
			g[u].emplace_back(v, 1);
			g[v].emplace_back(u, 1);
		}
	}
	return tree_diameter(g);
}


template<typename T=ll>
pair<T, vector<int>> tree_diameter(const vector<vector<pair<int, T>>> &g){
	int n = (int)g.size();
	vector dis(n, inf<T>());
	queue<int> q;
	dis[0] = 0;
	q.push(0);

	while(not q.empty()){
		int v = q.front();
		q.pop();
		for(auto [to, c] : g[v]){
			if(dis[to] != inf<T>())continue;
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

	dis.assign(n, inf<T>());
	vector<int> par(n, -1);
	dis[r1] = 0;
	q.push(r1);

	while(not q.empty()){
		int v = q.front();
		q.pop();
		for(auto [to, c] : g[v]){
			if(dis[to] != inf<T>())continue;
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

	vector<int> path;
	for(int cur = r2;cur != -1;cur = par[cur]){
		path.eb(cur);
	}

	return {diameter, path};
}

pair<int, vector<int>> tree_diameter(const vector<vector<int>> &g_unweighted){
	int n = (int)g_unweighted.size();
	vector<vector<pair<int, int>>> g(n);

	for(int u = 0;u < n;u++){
		for(int v : g_unweighted[u]){
			g[u].eb(v, 1);
			g[v].eb(u, 1);
		}
	}
	return tree_diameter(g);
}

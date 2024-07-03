
struct scc_graph {
	int n;
	int k;
	vector<vector<int>> g;
	vector<vector<int>> rg;
	vector<bool> used;
	vector<int> cmp;
	vector<int> vs;

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
		vs.pb(v);
	}

	void rdfs(int v, int col){
		used[v] = true;
		cmp[v] = col;
		for(auto to : rg[v]){
			if(not used[to])rdfs(to, col);
		}
	}

	vector<vector<int>> scc() {
		for(int i = 0;i < n;i++){
			if(not used[i])dfs(i);
		}
		for(int i = 0;i < n;i++){
			used[i] = false;
		}
		for(auto i = vs.rbegin();i != vs.rend();i++){
			if(not used[*i])rdfs(*i, k++);
		}
		vector<vector<int>> ret(k);
		for(int i = 0;i < n;i++){
			ret[cmp[i]].push_back(i);
		}
		return ret;
	}
};

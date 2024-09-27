
struct lowest_common_ancestor {
private:
	int n;
	int root;
	vector<vector<int>>par;
public:
	vector<int>depth;

	lowest_common_ancestor(vector<vector<int>>& g, int Root) : n((int)g.size()) {
		depth.resize(n);
		par.resize(n);
		for (int i = 0; i < n; i++)par[i].resize(31);
		root = Root;

		auto dfs = [&](auto f, int v, int p, int d) -> void {
			par[v][0] = p;
			depth[v] = d;
			for(size_t i = 0;i < g[v].size();i++){
				if(g[v][i] == p)continue;
				f(f, g[v][i], v, d+1);
			}
		};

		dfs(dfs, root, -1, 0);
		
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < n; j++) {
				if (par[j][i] == -1)par[j][i + 1] = -1;
				else par[j][i + 1] = par[par[j][i]][i];
			}
		}
	}

	int get(int u, int v) {
		if (depth[u] > depth[v])swap(u, v);
		for (int i = 30; i >= 0; i--) {
			if (((depth[v] - depth[u]) >> i) & 1) {
				v = par[v][i];
			}
		}
		if (u == v)return u;

		for (int i = 30; i >= 0; i--) {
			if (par[u][i] != par[v][i]) {
				u = par[u][i];
				v = par[v][i];
			}
		}
		return par[u][0];
	}
};

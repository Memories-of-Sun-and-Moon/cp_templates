
template<typename T> 
struct primal_dual_with_negative_edges {
	struct edge {
		int to;
		T cap, cost, rev;
	};
	int V;
	T infty;
	vector<vector<edge>> G;
	vector<T> dist;
	vector<int> prevv, preve;

	primal_dual_with_negative_edges(int _V) : V(_V), infty(numeric_limits<T>::max()/2) {
		G.resize(V);
		dist.resize(V);
		prevv.resize(V);
		preve.resize(V);
	}

	void add_edge(int from, int to, int cap, int cost) {
		G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
		G[to].push_back((edge){from, 0, -cost, (int)G[from].size()-1});
	}

	optional<T> min_cost_flow(int s, int t, T f) {
		int res = 0;
		while(f > 0){
			dist.assign(V, infty);
			dist[s] = 0;
			bool update = true;
			while(update) {
				update = false;
				for(int v = 0;v < V;v++) {
					if(dist[v] == infty) continue;
					for(int i = 0;i < (int)G[v].size();i++) {
						auto &e = G[v][i];
						if(e.cap > 0 && dist[e.to] > dist[v]+e.cost) {
							dist[e.to] = dist[v] + e.cost;
							prevv[e.to] = v;
							preve[e.to] = i;
							update = true;
						}
					}
				}
			}

			if(dist[t] == infty) {
				return nullopt;
			}

			int d = f;
			for(int v = t;v != s;v = prevv[v]) {
				d = min(d, G[prevv[v]][preve[v]].cap);
			}
			f -= d;
			res += d*dist[t];
			for(int v = t;v != s;v = prevv[v]) {
				auto &e = G[prevv[v]][preve[v]];
				e.cap -= d;
				G[v][e.rev].cap += d;
			}
		}
		return res;
	}
};

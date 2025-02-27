
template<typename T>
struct primal_dual{
	struct edge {
		int to;
		T cap, cost, rev;
		T max_cap;
	};
	int V;
	T infty;
	vector<vector<edge>> G;
	vector<T> h, dist;
	vector<int> prevv, preve;
	vector<bool> used_edge;

	primal_dual(int _V) : V(_V), infty(numeric_limits<T>::max()/2) {
		G.resize(V);
		h.resize(V);
		dist.resize(V);
		prevv.resize(V);
		preve.resize(V);
		used_edge.resize(V);
	}

	void add_edge(int from, int to, T cap, T cost){
		G[from].push_back((edge){to, cap, cost, (int)G[to].size(), cap});
		G[to].push_back((edge){from, 0, -cost, (int)G[from].size()-1, 0});
		used_edge[from] = true;
		used_edge[to] = true;
	}

	pair<bool, T> min_cost_flow(int s, int t, T f){
		T res = 0;
		while(f > 0){
			priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> que;
			dist.assign(V, infty);
			dist[s] = 0;
			que.push({0, s});
			while(not que.empty()){
				auto [cst, v] = que.top();
				que.pop();
				if(dist[v] < cst)continue;
				for(int i = 0;i < (int)G[v].size();i++){
					auto &e = G[v][i];
					if(e.cap > 0 && dist[e.to] > dist[v]+e.cost+h[v]-h[e.to]){
						dist[e.to] = dist[v]+e.cost+h[v]-h[e.to];
						prevv[e.to] = v;
						preve[e.to] = i;
						que.push({dist[e.to], e.to});
					}
				}
			}
			if(dist[t] == infty){
				return make_pair(false, res);
			}
			for(int v = 0;v < V;v++){
				if(not used_edge[v])continue;
				h[v] += dist[v];
			}
			T d = f;
			for(int v = t;v != s;v = prevv[v]){
				d = min(d, G[prevv[v]][preve[v]].cap);
			}
			f -= d;
			res += d*h[t];
			for(int v = t;v != s;v = prevv[v]){
				edge &e = G[prevv[v]][preve[v]];
				e.cap -= d;
				G[v][e.rev].cap += d;
			}
		}
		return make_pair(true, res);
	}
};

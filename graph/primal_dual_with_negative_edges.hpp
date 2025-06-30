
#include<numeric>
#include<utility>
#include<vector>

template<typename T> 
struct primal_dual_with_negative_edges {
	struct edge {
		int to;
		T cap, cost, rev;
		T init_cap;
	};
	int V;
	T infty;
	std::vector<std::vector<edge>> G;
	std::vector<T> dist;
	std::vector<int> prevv, preve;

	std::vector<int> from_idx, to_idx;
	int edge_idx;

	primal_dual_with_negative_edges(int _V) : V(_V), infty(std::numeric_limits<T>::max()/2), edge_idx(0) {
		G.resize(V);
		dist.resize(V);
		prevv.resize(V);
		preve.resize(V);
	}

	int add_edge(int from, int to, T cap, T cost) {
		G[from].push_back((edge){to, cap, cost, (int)G[to].size(), cap});
		G[to].push_back((edge){from, 0, -cost, (int)G[from].size()-1, 0});
		from_idx.emplace_back(from);
		to_idx.emplace_back((int)G[from].size()-1);
		
		return edge_idx++;
	}

	std::pair<bool, T> min_cost_flow(int s, int t, T f) {
		T res = 0;
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
				return make_pair(false, res);
			}

			T d = f;
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
		return make_pair(true, res);
	}

	T get_flow(int idx){
		return G[from_idx[idx]][to_idx[idx]].init_cap - G[from_idx[idx]][to_idx[idx]].cap;
	}
};

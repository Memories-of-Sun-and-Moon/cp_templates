
#include<numeric>
#include<queue>
#include<vector>

template<typename T>
struct dinic {

	struct edge{
		int to;
		T cap;
		T rev;
		T init_cap;
	};
		
	int n;
	std::vector<std::vector<edge>> G;
	std::vector<int> level;
	std::vector<int> iter;

	std::vector<int> from_idx, to_idx;
	int edge_idx;

	dinic(int _v) : n(_v), G(n), level(n), iter(n), edge_idx(0) {}

	int add_edge(int from, int to, T cap){
		G[from].push_back((edge){to, cap, (T)G[to].size(), cap});
		G[to].push_back((edge){from, 0, (T)(G[from].size() - 1), 0});
		from_idx.emplace_back(from);
		to_idx.emplace_back((int)G[from].size()-1);
		
		return edge_idx++;
	}

	void bfs(int s){
		for(int i = 0;i < n;i++)level[i] = -1;
		std::queue<int> que;
		level[s] = 0;
		que.push(s);
		while(!que.empty()){
			int v = que.front();
			que.pop();
			for(int i = 0;i < (int)G[v].size();i++){
				edge &e = G[v][i];
				if(e.cap > 0 && level[e.to] < 0){
					level[e.to] = level[v] + 1;
					que.push(e.to);
				}
			}
		}
	}

	T dfs(int v, int t, T f){
		if(v == t)return f;
		for(int &i = iter[v];i < (int)G[v].size();i++){
			edge &e = G[v][i];
			if(e.cap > 0 && level[v] < level[e.to]){
				T d = dfs(e.to, t, min(f, e.cap));
				if(d > 0){
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	T calc(int s, int t){
		T flow = 0;
		for(;;){
			bfs(s);
			if(level[t] < 0)return flow;
			for(int i = 0;i < n;i++)iter[i] = 0;
			T f;
			while((f = dfs(s, t, std::numeric_limits<T>::max())) > 0) {
				flow += f;
			}
		}
	}

	T get_flow(int idx){
		return G[from_idx[idx]][to_idx[idx]].init_cap - G[from_idx[idx]][to_idx[idx]].cap;
	}
};

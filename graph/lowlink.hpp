
class lowlink{
	vector<vector<int>> g;
	vector<int> order, low;
	vector<bool> __is_articulation;

	void dfs(int cur, int pre, int &time){
		int count_child = 0;
		low[cur] = order[cur] = time++;
		for(int to : g[cur]){
			if(to == pre)continue;
			if(order[to] == -1){
				dfs(to, cur, time);
				count_child++;
				if(pre != -1){
					if(not __is_articulation[cur]) __is_articulation[cur] = (low[to] >= order[cur]);
				}
				low[cur] = min(low[cur], low[to]);
			}else{
				low[cur] = min(low[cur], order[to]);
			}
		}
		if(pre == -1){
			__is_articulation[cur] = (count_child >= 2);
		}
	}

public:

	lowlink(const vector<vector<int>> &_g) : g(_g), order(g.size(), -1), low(g.size()), __is_articulation(g.size(), false){
		int time = 0;
		for(int v = 0;v < (int)g.size();v++){
			if(order[v] == -1){
				dfs(v, -1, time);
			}
		}
	}

	bool is_bridge(int u, int v) const {
		if(order[u] > order[v]){
			swap(u, v);
		}
		return order[u] < low[v];
	}

	bool is_articulation(int v) const {
		return __is_articulation[v];
	}
};

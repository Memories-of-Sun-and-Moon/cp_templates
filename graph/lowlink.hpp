
class lowlink{
	vector<vector<int>> g;
	vector<int> order, low;
	vector<bool> is_articulation;

	void dfs(int v, int pre, int &time){
		low[v] = order[v] = time++;
		for(int to : g[v]){
			if(to == pre)continue;
			if(order[to] == -1){
				dfs(to, v, time);
				low[v] = min(low[v], low[to]);
			}else{
				low[v] = min(low[v], order[to]);
			}
		}
	}

public:

	lowlink(const vector<vector<int>> &_g) : g(_g), order(g.size(), -1), low(g.size()){
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
};

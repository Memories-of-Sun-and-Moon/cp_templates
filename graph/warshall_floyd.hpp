
template<typename T>
struct warshall_floyd {
private:
	int V;
public:
	vector<vector<T>> dist;

	warshall_floyd(vector<vector<T>> &edge_cost, T infty=::numeric_limits<T>()/2) : V(ssize(edge_cost)), dist(edge_cost){
		for(int k = 0;k < V;k++){
			for(int i = 0;i < V;i++){
				if(dist[i][k] == infty)continue;
				for(int j = 0;j < V;j++){
					if(dist[k][j] == infty)continue;
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}

	void update(int s, int t, T cost){
		dist[s][t] = cost;
		for(int u = 0;u < V;u++){
			for(int v = 0;v < V;v++){
				dist[u][v] = min(dist[u][v], dist[u][s]+dist[s][t]+dist[t][v]);
			}
		}
	}
};


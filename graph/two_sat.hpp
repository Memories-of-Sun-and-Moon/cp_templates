
#include "./strongly_connected_components.hpp"

struct two_sat {
	int n;
	scc_graph g;

	two_sat(int _n) : n(_n), g(scc_graph(2*n)) {}

	// (i = f1) || (j = f2)
	void add_clause(int i, bool f1, int j, bool f2){
		g.add_edge((i << 1) ^ !f1, (j << 1) ^ f2);
		g.add_edge((j << 1) ^ !f2, (i << 1) ^ f1);
	}

	// (i = f1) -> (j = f2) <=> (1 = !f1) || (j = f2)
	void add_if(int i, bool f1, int j, bool f2){
		add_clause(i, !f1, j, f2);
	}

	// i
	void set_true(int i){
		add_clause(i, true, i, true);
	}

	// !i
	void set_false(int i){
		add_clause(i, false, i, false);
	}

	std::vector<bool> solve(){
		std::vector<std::vector<int>> scc = g.scc();
		std::vector<int> c(2*n);
		for(int i = 0;i < (int)scc.size();i++){
			for(auto v : scc[i]){
				c[v] = i;
			}
		}
		std::vector<bool> res(n);
		for(int i = 0;i < n;i++){
			if(c[i << 1] == c[i << 1 | 1])return std::vector<bool>();
			res[i] = (c[i << 1] < c[i << 1 | 1]);
		}
		return res;
	}
};

#define PROBLEM "https://yukicoder.me/problems/no/2780"

#include "./../../template/template.hpp"
#include "./../../graph/strongly_connected_components.hpp"

using namespace mmrz;

void mmrz::solve(){
	int n;
	cin >> n;
	scc_graph g(n);
	vector<vector<int>> gr(n);
	rep(i, n){
		int a;
		cin >> a;
		rep(j, a){
			int b;
			cin >> b;
			b--;
			gr[i].pb(b);
			g.add_edge(i, b);
		}
	}
	
	auto scc = g.scc();

	vector<int> topol(n);
	rep(i, len(scc)){
		for(auto y : scc[i]){
			topol[y] = i;
		}
	}

	bool flg = false;
	for(auto i : scc[0]){
		if(i == 0)flg = true;
	}

	if(!flg){
		cout << "No" << endl;
		return;
	}

	rep(i, len(scc)-1){
		bool c = false;
		for(auto j : scc[i]){
			for(auto k : gr[j]){
				if(topol[k] == i+1)c = true;
			}
		}
		if(not c){
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
}

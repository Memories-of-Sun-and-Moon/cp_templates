# define PROBLEM "https://atcoder.jp/contests/typical90/tasks/typical90_u"

# include <bits/stdc++.h>
using namespace std;

struct strongly_connected_components {
private:
    int v;
    vector<vector<int>> g, rg;
    vector<int> vs;
    vector<bool> used;

    int groups = 0;

    void dfs(int cur){
        used[cur] = true;
        for(auto to : g[cur]){
            if(not used[to])dfs(to);
        }
        vs.push_back(cur);
    }

    void rdfs(int cur, int k){
        used[cur] = true;
        group[cur] = k;
        for(auto to : rg[cur]){
            if(not used[to])rdfs(to, k);
        }
    }

    void scc(){
        vs.clear();
        groups = 0;
        for(int i = 0;i < v;i++){
            if(not used[i])dfs(i);
        }
        used.assign(v, false);
        for(int i = (int)vs.size() - 1;i >= 0;i--){
            if(not used[vs[i]])rdfs(vs[i], groups++);
        }
    }
public:
    // 強連結成分のグループ番号
    vector<int> group;

    strongly_connected_components(vector<vector<int>> _g) : g(_g){
        v = (int)g.size();
        rg.resize(v);
        for(int i = 0;i < v;i++)for(auto to : g[i])rg[to].push_back(i);
        used.resize(v, false);
        group.resize(v, 0);
        scc();
    }
};
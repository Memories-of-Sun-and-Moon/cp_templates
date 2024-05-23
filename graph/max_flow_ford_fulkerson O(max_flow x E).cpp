# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"
# include <bits/stdc++.h>
using namespace std;

//Ford-Fulkerson algorithm O(max_flow|E|)
template<typename T>struct max_flow {

    struct edge{
        int to;
        T cap;
        T rev;
    };

    int n;
    vector<vector<edge>> G;
    vector<bool> used;

    max_flow(int _v) : n(_v) {
        G.resize(n);
        used.resize(n, false);
    }

    void add_edge(int from, int to, T cap){
        G[from].push_back((edge){to, cap, (T)G[to].size()});
        G[to].push_back((edge){from, 0, (T)(G[from].size() - 1)});
    }

    T dfs(int v, int t, T f){
        if(v == t)return f;
        used[v] = true;
        for(int i = 0;i < (int)G[v].size();i++){
            edge &e = G[v][i];
            if(!used[e.to] && e.cap > 0){
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
            for(int i = 0;i < n;i++)used[i] = false;
            int f = dfs(s, t, inf<T>());
            if(f == 0)return flow;
            flow += f;
        }
    }
};

int v, e;

int main(){
    cin >> v >> e;
    max_flow<int> mf(v);

    for(int i = 0;i < e;i++){
        int a, b, c;
        cin >> a >> b >> c;
        mf.add_edge(a, b, c);
    }
    cout << mf.calc(0, v - 1) << endl;
}
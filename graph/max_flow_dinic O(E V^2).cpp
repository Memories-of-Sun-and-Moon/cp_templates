# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"
# include <bits/stdc++.h>
using namespace std;

//dinic algorithm O(|E||v|^2)よりも非常に高速に動作 
template<typename T>struct max_flow {

    struct edge{
        int to;
        T cap;
        T rev;
    };
    
    int n;
    vector<vector<edge>> G;
    vector<int> level; // sからの距離
    vector<int> iter; // どこまで調べ終わったか

    max_flow(int _v) : n(_v) {
        G.resize(n);
        level.resize(n);
        iter.resize(n);
    }

    void add_edge(int from, int to, T cap){
        G[from].push_back((edge){to, cap, (T)G[to].size()});
        G[to].push_back((edge){from, 0, (T)(G[from].size() - 1)});
    }

    // s 空の最短距離を計算
    void bfs(int s){
        for(int i = 0;i < n;i++)level[i] = -1;
        queue<int> que;
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

    //増加パスをDFSで探す
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
            int f;
            while((f = dfs(s, t, inf<T>())) > 0) {
                flow += f;
            }
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

template<typename T>
struct ford_fulkerson {

    struct edge{
        int to;
        T cap;
        T rev;
    };

    int n;
    vector<vector<edge>> G;
    vector<bool> used;

    ford_fulkerson(int _v) : n(_v), G(n), used(n) {}

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

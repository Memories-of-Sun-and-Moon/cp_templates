# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"
#include <bits/stdc++.h>
using namespace std;

template<typename T = int> struct warshall_floyd {
    int V;
    vector<vector<T>> d;
    T inf;

    warshall_floyd(int _V) : V(_V){
        inf = ::std::numeric_limits<T>::max() / 2;
        d = vector<vector<T>>(V, vector<T>(V));
        for(int i = 0;i < V;i++){
            for(int j = 0;j < V;j++){
                if(i == j)d[i][j] = 0;
                else d[i][j] = inf;
            }
        }
    }

    void set(int a, int b, T cost){
        d[a][b] = cost;
    }

    void calc(){
        for(int k = 0;k < V;k++){
            for(int i = 0;i < V;i++){
                if(d[i][k] == inf)continue;
                for(int j = 0;j < V;j++){
                    if(d[k][j] == inf)continue;
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
};

int v, e;
int s, t, d;

int main(){
    cin >> v >> e;
    warshall_floyd<long long> wf(v);
    for(int i = 0;i < e;i++){
        cin >> s >> t >> d;
        wf.set(s, t, d);
    }
    wf.calc();
    for(int i = 0;i < v;i++){
        if(wf.d[i][i] < 0){
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    for(int i = 0;i < v;i++){
        for(int j = 0;j < v;j++){
            if(j)cout << " ";
            if(wf.d[i][j] == wf.inf)cout << "INF";
            else cout << wf.d[i][j];
        }
        cout << endl;
    }
}
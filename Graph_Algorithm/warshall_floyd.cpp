#include "bits/stdc++.h"
using namespace std;

// Verified
// https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=6730684#1

template<typename T>struct warshall_floyd {
    int V;
    vector<vector<T>> d;

    warshall_floyd(int _V) : V(_V){
        T Infinity = ::std::numeric_limits<T>::max() / 2;
        d = vector<vector<T>>(V, vector<T>(V));
        for(int i = 0;i < V;i++){
            for(int j = 0;j < V;j++){
                if(i == j)d[i][j] = 0;
                else d[i][j] = Infinity;
            }
        }
    }

    void set(int a, int b, T cost){
        d[a][b] = cost;
        d[b][a] = cost;
    }

    void calc(){
        for(int k = 0;k < V;k++){
            for(int i = 0;i < V;i++){
                for(int j = 0;j < V;j++){
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
};
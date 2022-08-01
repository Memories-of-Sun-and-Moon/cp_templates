# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"
# include "bits/stdc++.h"
using namespace std;

struct UnionFind {
	UnionFind(size_t size){
        for(int i = 0;i < (int)size;i++){
            par.emplace_back(i);
            rnk.emplace_back(0);
        }
    }
	vector<int> par, rnk;

    int root(int x){
        if(par[x] == x)return x;
        else return par[x] = root(par[x]);
    }

    bool is_root(int x){
        return root(x) == x;
    }

    void unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y)return;
        if(rnk[x] < rnk[y]){
            par[x] = y;
        }else{
            par[y] = x;
            if(rnk[x] == rnk[y])rnk[x]++;
        }
    }
    bool same(int x,int y){
        return root(x) == root(y);
    }
};

int n, q;
int com, x, y;

int main(){
    cin >> n >> q;
    UnionFind uf(n);
    while(q--){
        cin >> com >> x >> y;
        if(com == 0)uf.unite(x, y);
        else cout << uf.same(x, y) << endl;
    }
}
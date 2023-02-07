# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"
# include "bits/stdc++.h"
using namespace std;

struct union_find {
	vector<int> par, rnk;

    union_find(size_t size){
        par.resize(size);
        rnk.resize(size, 0);
        for(int i = 0;i < (int)size;i++){
            par[i] = i;
        }
    }

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
    union_find uf(n);
    while(q--){
        cin >> com >> x >> y;
        if(com == 0)uf.unite(x, y);
        else cout << uf.same(x, y) << endl;
    }
}
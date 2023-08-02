# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B"
# include "bits/stdc++.h"
using namespace std;


//1-indexed に注意
template<typename T>struct binary_indexed_tree {
    int n;
    vector<T> bit;
    binary_indexed_tree(int n_) : n(n_ + 1), bit(n, 0) {}

    void add(int i, T x){
        for(int idx = i;idx < n;idx += (idx & -idx)){
            bit[idx] += x;
        }
    }

    //[1, i] の総和
    T sum(int i) {
        T ret = 0;
        for(int idx = i;idx > 0;idx -= (idx & -idx)){
            ret += bit[idx];
        }
        return ret;
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    binary_indexed_tree<int> bit(n);
    while(q--){
        int com, x, y;
        cin >> com >> x >> y;
        if(com == 0){
            bit.add(x, y);
        }else{
            cout << bit.sum(y) - (x != 1 ? bit.sum(x - 1) : 0) << endl;
        }
    }
}
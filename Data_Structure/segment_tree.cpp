#include "bits/stdc++.h"
using namespace std;

// Verified
// https://onlinejudge.u-aizu.ac.jp/status/users/M3_cp/submissions/2/DSL_2_A/judge/6708968/C++17

template<typename T>struct segment_tree {
    using F = function<T(T, T)>;

    int n;
    vector<T> node;
    F combine; // 区間の演算
    T identify; // 単位元

    //扱う配列がすでにできている場合
    segment_tree(vector<T> v, F _combine, T _identity) : combine(_combine), identify(_identity) {
        int sz = (int)v.size();
        n = 1;
        while(n < sz)n *= 2;
        node.resize(2 * n - 1, identify);

        for(int i = 0;i < sz;i++)node[i + n - 1] = v[i];
        for(int i = n - 2;i >= 0;i--)node[i] = combine(node[2 * i + 1], node[2 * i + 2]);
    }

    //空のものからやっていく場合
    segment_tree(int _n, F _combine, T _identify) : combine(_combine), identify(_identify){
        int sz = _n;
        n = 1;
        while(n < sz)n *= 2;
        node.resize(2 * n - 1, identify);
    }

    T operator[](int x) {return node[x + n - 1]; }

    void set(int x, T val){
        x += (n - 1);

        node[x] = val;
        while(x > 0){
            x = (x - 1) / 2;
            node[x] = combine(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    T fold(int a, int b, int k = 0, int l = 0, int r = -1){
        //最初に呼び出された時の対象区間は [0, n)
        if(r < 0) r = n;

        //要求区間と対象区間が交わらない -> 適当に（単位元を）返す
        if(r <= a || b <= l)return identify;
        
        //要求区間が対象区間と完全被覆 -> 対象区間を答えの計算に使う
        if(a <= l && r <= b)return node[k];

        //要求区間が対象区間の一部を被覆 -> 子についての探索を行う
        T vl = fold(a, b, 2 * k + 1, l, (l + r) / 2);
        T vr = fold(a, b, 2 * k + 2, (l + r) / 2, r);
        return combine(vl, vr);
    }
};

//Usage

int n;

int main(){
    auto combine_sum = [](int a, int b){return a + b; };
    segment_tree<int> Range_Sum_Query(n, combine_sum, 0);
}

/*転倒数
int main() {
    auto combine_sum = [](int a, int b){return a + b; };
    segment_tree<int> seg(n, combine_sum, 0);

    LL ans = 0;

    REP(i, n){
        LL num = i - seg.fold(0, a[i]);
        seg.set(a[i], 1);
        ans += num;
    }
}
*/
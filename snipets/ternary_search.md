# ternary search (三分探索)

- 極値が $1$ つしかなく、その極値を取る区間がデカすぎないもの

連続でない関数を考えるときは、極値が広範囲に及ぶ可能性があることに注意する

## 極小値を取るパターン
```cpp
ll lo = -1, hi = 1e8;
while(hi - lo > 10) {
    ll c1 = (lo + lo + hi) / 3LL;
    ll c2 = (lo + hi + hi) / 3LL;
    if(f(x, c1) > f(x, c2)){
        lo = c1;
    }else{
        hi = c2;
    }
}
```
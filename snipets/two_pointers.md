# Two Pointers (尺取り法)

- $[l, r)$ であることに注意

# 初期解を作る必要がある時

```cpp
int right = 0;

// left == 0 の時の、最大の r を外で計算しておく

for(int left = 0;left < n;left++){
    while(right < n && (条件)){
        //right を右に動かす処理
    }
    // ↓(left次第で)尺取り法の内部が保たれた状態になっている
    
    // ↑(left次第で)尺取り法の内部が保たれた状態になっている
    
    // left を取り除く処理
    // left はここでインクリメントしなくてよい
}
```

# 初期解を作る必要がない時

```cpp
for(int left = 0, right = 0;left < n;left++){
    while(right < n && (条件)){
        //right を右に動かす処理
    }
    // ↓(left次第で)尺取り法の内部が保たれた状態になっている
    
    // ↑(left次第で)尺取り法の内部が保たれた状態になっている
    
    // left を取り除く処理
    // left はここでインクリメントしなくてよい
}
```

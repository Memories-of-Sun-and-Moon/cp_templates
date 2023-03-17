```cpp
for(int left = 0, right = 0;left < n;left++){
    while(right < n && (条件)){
        right を右に動かす処理
    }
    // ↓尺取り法の内部が保たれた状態になっている
    
    // ↑尺取り法の内部が保たれた状態になっている
    
    // left を取り除く処理
}
```
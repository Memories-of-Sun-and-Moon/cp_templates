# Mo's Algorithm

```cpp
struct mo_query {
    int l, r, i;
};

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n){
        cin >> a[i], a[i]--;
    }
    vector<mo_query> lri(q);
    rep(i, q){
        cin >> lri[i].l >> lri[i].r;
        lri[i].l--;
        lri[i].r--;
        lri[i].i = i;
    }
    int sq = sqrt(n);
    sort(all(lri), [&](mo_query const& lhs, mo_query const& rhs){
        if(lhs.l / sq != rhs.l / sq){
            return lhs.l / sq < rhs.l / sq;
        }else{
            return lhs.r < rhs.r;
        }
    });

    int cl = 0;
    int cr = 0;
    //
    // クエリが持つべき物をここに書く
    // はじめは[0, 0]に関する結果を保存しておく 
    //
    vector<ll> ans(q);

    auto add = [&](int x) -> void {
        // 区間を増やす際の処理
        return;
    };

    auto del = [&](int x) -> void {
        // 区間を減らす際の処理
        return;
    };

    for(auto [l, r, i] : lri){
        while(cl < l){
            del(cl);
            cl++;
        }
        while(l < cl){
            cl--;
            add(cl);
        }
        while(cr < r){
            cr++;
            add(cr);
        }
        while(r < cr){
            del(cr);
            cr--;
        }
        ans[i] = cur_ans;
    }
    rep(i, q){
        cout << ans[i] << endl;
    }
}
```
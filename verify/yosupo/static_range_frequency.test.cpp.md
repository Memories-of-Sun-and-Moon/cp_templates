---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/mo.hpp
    title: Mo's Algorithm
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_frequency
    links:
    - https://judge.yosupo.jp/problem/static_range_frequency
  bundledCode: "#line 1 \"verify/yosupo/static_range_frequency.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\n\n#line\
    \ 1 \"template/template.hpp\"\n# include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing ull = unsigned long long;\nconst double pi = acos(-1);\n\
    template<class T>constexpr T inf() { return ::std::numeric_limits<T>::max(); }\n\
    template<class T>constexpr T hinf() { return inf<T>() / 2; }\ntemplate <typename\
    \ T_char>T_char TL(T_char cX) { return tolower(cX); }\ntemplate <typename T_char>T_char\
    \ TU(T_char cX) { return toupper(cX); }\ntemplate<class T> bool chmin(T& a,T b)\
    \ { if(a > b){a = b; return true;} return false; }\ntemplate<class T> bool chmax(T&\
    \ a,T b) { if(a < b){a = b; return true;} return false; }\nint popcnt(unsigned\
    \ long long n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++;\
    \ return cnt; }\nint d_sum(ll n) { int ret = 0; while (n > 0) { ret += n % 10;\
    \ n /= 10; }return ret; }\nint d_cnt(ll n) { int ret = 0; while (n > 0) { ret++;\
    \ n /= 10; }return ret; }\nll gcd(ll a, ll b) { if (b == 0)return a; return gcd(b,\
    \ a%b); };\nll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g*b; };\nll MOD(ll\
    \ x, ll m){return (x%m+m)%m; }\nll FLOOR(ll x, ll m) {ll r = (x%m+m)%m; return\
    \ (x-r)/m; }\ntemplate<class T> using dijk = priority_queue<T, vector<T>, greater<T>>;\n\
    # define all(qpqpq)           (qpqpq).begin(),(qpqpq).end()\n# define UNIQUE(wpwpw)\
    \        (wpwpw).erase(unique(all((wpwpw))),(wpwpw).end())\n# define LOWER(epepe)\
    \         transform(all((epepe)),(epepe).begin(),TL<char>)\n# define UPPER(rprpr)\
    \         transform(all((rprpr)),(rprpr).begin(),TU<char>)\n# define rep(i,upupu)\
    \         for(ll i = 0, i##_len = (upupu);(i) < (i##_len);(i)++)\n# define reps(i,opopo)\
    \        for(ll i = 1, i##_len = (opopo);(i) <= (i##_len);(i)++)\n# define len(x)\
    \                ((ll)(x).size())\n# define bit(n)               (1LL << (n))\n\
    # define pb push_back\n# define exists(c, e)         ((c).find(e) != (c).end())\n\
    \nstruct INIT{\n\tINIT(){\n\t\tstd::ios::sync_with_stdio(false);\n\t\tstd::cin.tie(0);\n\
    \t\tcout << fixed << setprecision(20);\n\t}\n}INIT;\n\nnamespace mmrz {\n\tvoid\
    \ solve();\n}\n\nint main(){\n\tmmrz::solve();\n}\n#line 1 \"data_structure/mo.hpp\"\
    \nclass Mo {\n    vector<pair<int, int>> lr;\npublic:\n    Mo() = default;\n \
    \   Mo(const vector<pair<int, int>> &_lr) : lr(_lr) {}\n\n    template<typename\
    \ AL, typename AR, typename EL, typename ER, typename F>\n    void calc(const\
    \ AL &add_left, const AR &add_right, const EL &erase_left, const ER& erase_right,\
    \ const F &f, int _n = -1, int _B = -1){\n        int n = (_n == -1 ? ranges::max(lr,\
    \ {}, &pair<int, int>::second).second : _n);\n        int q = (int)lr.size();\n\
    \        int B = (_B == -1 ? max(1, n/int(sqrt(q))) : _B);\n\n        vector<int>\
    \ index(q);\n        iota(index.begin(), index.end(), 0);\n        sort(index.begin(),\
    \ index.end(), [&](int i, int j){\n            const auto &[l_i, r_i] = lr[i];\n\
    \            const auto &[l_j, r_j] = lr[j];\n            const int B_i = l_i\
    \ / B, B_j = l_j / B;\n            return (B_i != B_j ? (B_i < B_j) : (r_i < r_j));\n\
    \        });\n\n        int l = 0, r = 0;\n        for(int idx : index){\n   \
    \         const auto &[L, R] = lr[idx];\n\n            while(L < l)add_left(--l);\n\
    \            while(l < L)erase_left(l++);\n            \n            while(r <\
    \ R)add_right(r++);\n            while(R < r)erase_right(--r);\n\n           \
    \ f(idx);\n        }\n    }\n\n    template<typename A, typename E, typename F>\n\
    \    void calc(const A &add, const E &erase, const F &f){\n        calc(add, add,\
    \ erase, erase, f);\n    }\n};\n#line 5 \"verify/yosupo/static_range_frequency.test.cpp\"\
    \n\nusing namespace mmrz;\n\nvoid mmrz::solve(){\n    int n, q;\n    cin >> n\
    \ >> q;\n    vector<int> a(n);\n    for(auto &x : a)cin >> x;\n    if(q == 0){\n\
    \        return;\n    }\n    if(n == 0){\n        while(q--){\n            int\
    \ l, r, x;\n            cin >> l >> r >> x;\n            cout << 0 << endl;\n\
    \        }\n        return;\n    }\n    vector<pair<int, int>> lr(q);\n    vector<int>\
    \ x(q);\n    rep(i, q){\n        cin >> lr[i].first >> lr[i].second >> x[i];\n\
    \    }\n\n    {\n        vector<int> v;\n        for(auto &e : a)v.pb(e);\n  \
    \      for(auto &e : x)v.pb(e);\n        sort(all(v));\n        UNIQUE(v);\n \
    \       map<int, int> cmp;\n        rep(i, len(v))cmp[v[i]] = i;\n        for(auto\
    \ &e : a)e = cmp[e];\n        for(auto &e : x)e = cmp[e];\n    }\n\n    Mo mo(lr);\n\
    \n    vector<int> cnt(n+q);\n\n    auto add = [&](int idx) -> void {\n       \
    \ cnt[a[idx]]++;\n    };\n\n    auto erase = [&](int idx) -> void {\n        cnt[a[idx]]--;\n\
    \    };\n\n    vector<int> ans(q);\n    auto f = [&](int query_id) -> void {\n\
    \        ans[query_id] = cnt[x[query_id]];\n    };\n\n    mo.calc(add, erase,\
    \ f);\n\n    rep(i, q){\n        cout << ans[i] << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \n\n#include \"./../../template/template.hpp\"\n#include \"./../../data_structure/mo.hpp\"\
    \n\nusing namespace mmrz;\n\nvoid mmrz::solve(){\n    int n, q;\n    cin >> n\
    \ >> q;\n    vector<int> a(n);\n    for(auto &x : a)cin >> x;\n    if(q == 0){\n\
    \        return;\n    }\n    if(n == 0){\n        while(q--){\n            int\
    \ l, r, x;\n            cin >> l >> r >> x;\n            cout << 0 << endl;\n\
    \        }\n        return;\n    }\n    vector<pair<int, int>> lr(q);\n    vector<int>\
    \ x(q);\n    rep(i, q){\n        cin >> lr[i].first >> lr[i].second >> x[i];\n\
    \    }\n\n    {\n        vector<int> v;\n        for(auto &e : a)v.pb(e);\n  \
    \      for(auto &e : x)v.pb(e);\n        sort(all(v));\n        UNIQUE(v);\n \
    \       map<int, int> cmp;\n        rep(i, len(v))cmp[v[i]] = i;\n        for(auto\
    \ &e : a)e = cmp[e];\n        for(auto &e : x)e = cmp[e];\n    }\n\n    Mo mo(lr);\n\
    \n    vector<int> cnt(n+q);\n\n    auto add = [&](int idx) -> void {\n       \
    \ cnt[a[idx]]++;\n    };\n\n    auto erase = [&](int idx) -> void {\n        cnt[a[idx]]--;\n\
    \    };\n\n    vector<int> ans(q);\n    auto f = [&](int query_id) -> void {\n\
    \        ans[query_id] = cnt[x[query_id]];\n    };\n\n    mo.calc(add, erase,\
    \ f);\n\n    rep(i, q){\n        cout << ans[i] << '\\n';\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - data_structure/mo.hpp
  isVerificationFile: true
  path: verify/yosupo/static_range_frequency.test.cpp
  requiredBy: []
  timestamp: '2024-07-03 18:57:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/static_range_frequency.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/static_range_frequency.test.cpp
- /verify/verify/yosupo/static_range_frequency.test.cpp.html
title: verify/yosupo/static_range_frequency.test.cpp
---
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
    # define pb push_back\n# define eb emplace_back\n# define exists(c, e)       \
    \  ((c).find(e) != (c).end())\n\nstruct INIT{\n\tINIT(){\n\t\tstd::ios::sync_with_stdio(false);\n\
    \t\tstd::cin.tie(0);\n\t\tcout << fixed << setprecision(20);\n\t}\n}INIT;\n\n\
    namespace mmrz {\n\tvoid solve();\n}\n\nint main(){\n\tmmrz::solve();\n}\n#line\
    \ 1 \"data_structure/mo.hpp\"\nclass Mo {\n\tstd::vector<std::pair<int, int>>\
    \ lr;\npublic:\n\tMo() = default;\n\tMo(const std::vector<std::pair<int, int>>\
    \ &_lr) : lr(_lr) {}\n\n\ttemplate<typename AL, typename AR, typename EL, typename\
    \ ER, typename F>\n\tvoid calc(const AL &add_left, const AR &add_right, const\
    \ EL &erase_left, const ER& erase_right, const F &f, int _n = -1, int _B = -1){\n\
    \t\tint n = (_n == -1 ? ranges::max(lr, {}, &std::pair<int, int>::second).second\
    \ : _n);\n\t\tint q = (int)lr.size();\n\t\tint B = (_B == -1 ? max(1, n/int(sqrt(q)))\
    \ : _B);\n\n\t\tstd::vector<int> index(q);\n\t\tiota(index.begin(), index.end(),\
    \ 0);\n\t\tsort(index.begin(), index.end(), [&](int i, int j){\n\t\t\tconst auto\
    \ &[l_i, r_i] = lr[i];\n\t\t\tconst auto &[l_j, r_j] = lr[j];\n\t\t\tconst int\
    \ B_i = l_i / B, B_j = l_j / B;\n\t\t\tif(B_i != B_j){\n\t\t\t\treturn B_i < B_j;\n\
    \t\t\t}\n\t\t\tif(B_i & 1){\n\t\t\t\treturn r_j < r_i;\n\t\t\t}else{\n\t\t\t\t\
    return r_i < r_j;\n\t\t\t}\n\t\t});\n\n\t\tint l = 0, r = 0;\n\t\tfor(int idx\
    \ : index){\n\t\t\tconst auto &[L, R] = lr[idx];\n\n\t\t\twhile(L < l)add_left(--l);\n\
    \t\t\twhile(r < R)add_right(r++);\n\t\t\t\n\t\t\twhile(l < L)erase_left(l++);\n\
    \t\t\twhile(R < r)erase_right(--r);\n\n\t\t\tf(idx);\n\t\t}\n\t}\n\n\ttemplate<typename\
    \ A, typename E, typename F>\n\tvoid calc(const A &add, const E &erase, const\
    \ F &f){\n\t\tcalc(add, add, erase, erase, f);\n\t}\n};\n#line 5 \"verify/yosupo/static_range_frequency.test.cpp\"\
    \n\nusing namespace mmrz;\n\nvoid mmrz::solve(){\n\tint n, q;\n\tcin >> n >> q;\n\
    \tvector<int> a(n);\n\tfor(auto &x : a)cin >> x;\n\tif(q == 0){\n\t\treturn;\n\
    \t}\n\tif(n == 0){\n\t\twhile(q--){\n\t\t\tint l, r, x;\n\t\t\tcin >> l >> r >>\
    \ x;\n\t\t\tcout << 0 << '\\n';\n\t\t}\n\t\treturn;\n\t}\n\tvector<pair<int, int>>\
    \ lr(q);\n\tvector<int> x(q);\n\trep(i, q){\n\t\tcin >> lr[i].first >> lr[i].second\
    \ >> x[i];\n\t}\n\n\t{\n\t\tvector<int> v;\n\t\tfor(auto &e : a)v.pb(e);\n\t\t\
    for(auto &e : x)v.pb(e);\n\t\tsort(all(v));\n\t\tUNIQUE(v);\n\t\tmap<int, int>\
    \ cmp;\n\t\trep(i, len(v))cmp[v[i]] = i;\n\t\tfor(auto &e : a)e = cmp[e];\n\t\t\
    for(auto &e : x)e = cmp[e];\n\t}\n\n\tMo mo(lr);\n\n\tvector<int> cnt(n+q);\n\n\
    \tauto add = [&](int idx) -> void {\n\t\tcnt[a[idx]]++;\n\t};\n\n\tauto erase\
    \ = [&](int idx) -> void {\n\t\tcnt[a[idx]]--;\n\t};\n\n\tvector<int> ans(q);\n\
    \tauto f = [&](int query_id) -> void {\n\t\tans[query_id] = cnt[x[query_id]];\n\
    \t};\n\n\tmo.calc(add, erase, f);\n\n\trep(i, q){\n\t\tcout << ans[i] << '\\n';\n\
    \t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \n\n#include \"./../../template/template.hpp\"\n#include \"./../../data_structure/mo.hpp\"\
    \n\nusing namespace mmrz;\n\nvoid mmrz::solve(){\n\tint n, q;\n\tcin >> n >> q;\n\
    \tvector<int> a(n);\n\tfor(auto &x : a)cin >> x;\n\tif(q == 0){\n\t\treturn;\n\
    \t}\n\tif(n == 0){\n\t\twhile(q--){\n\t\t\tint l, r, x;\n\t\t\tcin >> l >> r >>\
    \ x;\n\t\t\tcout << 0 << '\\n';\n\t\t}\n\t\treturn;\n\t}\n\tvector<pair<int, int>>\
    \ lr(q);\n\tvector<int> x(q);\n\trep(i, q){\n\t\tcin >> lr[i].first >> lr[i].second\
    \ >> x[i];\n\t}\n\n\t{\n\t\tvector<int> v;\n\t\tfor(auto &e : a)v.pb(e);\n\t\t\
    for(auto &e : x)v.pb(e);\n\t\tsort(all(v));\n\t\tUNIQUE(v);\n\t\tmap<int, int>\
    \ cmp;\n\t\trep(i, len(v))cmp[v[i]] = i;\n\t\tfor(auto &e : a)e = cmp[e];\n\t\t\
    for(auto &e : x)e = cmp[e];\n\t}\n\n\tMo mo(lr);\n\n\tvector<int> cnt(n+q);\n\n\
    \tauto add = [&](int idx) -> void {\n\t\tcnt[a[idx]]++;\n\t};\n\n\tauto erase\
    \ = [&](int idx) -> void {\n\t\tcnt[a[idx]]--;\n\t};\n\n\tvector<int> ans(q);\n\
    \tauto f = [&](int query_id) -> void {\n\t\tans[query_id] = cnt[x[query_id]];\n\
    \t};\n\n\tmo.calc(add, erase, f);\n\n\trep(i, q){\n\t\tcout << ans[i] << '\\n';\n\
    \t}\n}\n"
  dependsOn:
  - template/template.hpp
  - data_structure/mo.hpp
  isVerificationFile: true
  path: verify/yosupo/static_range_frequency.test.cpp
  requiredBy: []
  timestamp: '2025-06-30 19:47:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/static_range_frequency.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/static_range_frequency.test.cpp
- /verify/verify/yosupo/static_range_frequency.test.cpp.html
title: verify/yosupo/static_range_frequency.test.cpp
---

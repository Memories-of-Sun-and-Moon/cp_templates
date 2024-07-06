---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/ford_fulkerson.hpp
    title: "\u6700\u5927\u6D41(Ford-Fulkerson)"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
  bundledCode: "#line 1 \"verify/aoj/grl/6_A___ford_fulkerson.test.cpp\"\n# define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n\n#line 1 \"template/template.hpp\"\n# include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing ull = unsigned long long;\nconst double pi\
    \ = acos(-1);\ntemplate<class T>constexpr T inf() { return ::std::numeric_limits<T>::max();\
    \ }\ntemplate<class T>constexpr T hinf() { return inf<T>() / 2; }\ntemplate <typename\
    \ T_char>T_char TL(T_char cX) { return tolower(cX); }\ntemplate <typename T_char>T_char\
    \ TU(T_char cX) { return toupper(cX); }\ntemplate<class T> bool chmin(T& a,T b)\
    \ { if(a > b){a = b; return true;} return false; }\ntemplate<class T> bool chmax(T&\
    \ a,T b) { if(a < b){a = b; return true;} return false; }\nint popcnt(unsigned\
    \ long long n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++;\
    \ return cnt; }\nint d_sum(ll n) { int ret = 0; while (n > 0) { ret += n % 10;\
    \ n /= 10; }return ret; }\nint d_cnt(ll n) { int ret = 0; while (n > 0) { ret++;\
    \ n /= 10; }return ret; }\nll gcd(ll a, ll b) { if (b == 0)return a; return gcd(b,\
    \ a%b); };\nll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g*b; };\nll iroot(ll\
    \ x) {return sqrtl(x); }\nll MOD(ll x, ll m){return (x%m+m)%m; }\nll FLOOR(ll\
    \ x, ll m) {ll r = (x%m+m)%m; return (x-r)/m; }\ntemplate<class T> using dijk\
    \ = priority_queue<T, vector<T>, greater<T>>;\n# define all(qpqpq)           (qpqpq).begin(),(qpqpq).end()\n\
    # define UNIQUE(wpwpw)        (wpwpw).erase(unique(all((wpwpw))),(wpwpw).end())\n\
    # define LOWER(epepe)         transform(all((epepe)),(epepe).begin(),TL<char>)\n\
    # define UPPER(rprpr)         transform(all((rprpr)),(rprpr).begin(),TU<char>)\n\
    # define rep(i,upupu)         for(ll i = 0, i##_len = (upupu);(i) < (i##_len);(i)++)\n\
    # define reps(i,opopo)        for(ll i = 1, i##_len = (opopo);(i) <= (i##_len);(i)++)\n\
    # define len(x)                ((ll)(x).size())\n# define bit(n)             \
    \  (1LL << (n))\n# define pb push_back\n# define exists(c, e)         ((c).find(e)\
    \ != (c).end())\n\nstruct INIT{\n\tINIT(){\n\t\tstd::ios::sync_with_stdio(false);\n\
    \t\tstd::cin.tie(0);\n\t\tcout << fixed << setprecision(20);\n\t}\n}INIT;\n\n\
    namespace mmrz {\n\tvoid solve();\n}\n\nint main(){\n\tmmrz::solve();\n}\n#line\
    \ 1 \"graph/ford_fulkerson.hpp\"\n\ntemplate<typename T>\nstruct ford_fulkerson\
    \ {\n\n    struct edge{\n        int to;\n        T cap;\n        T rev;\n   \
    \ };\n\n    int n;\n    vector<vector<edge>> G;\n    vector<bool> used;\n\n  \
    \  ford_fulkerson(int _v) : n(_v), G(n), used(n) {}\n\n    void add_edge(int from,\
    \ int to, T cap){\n        G[from].push_back((edge){to, cap, (T)G[to].size()});\n\
    \        G[to].push_back((edge){from, 0, (T)(G[from].size() - 1)});\n    }\n\n\
    \    T dfs(int v, int t, T f){\n        if(v == t)return f;\n        used[v] =\
    \ true;\n        for(int i = 0;i < (int)G[v].size();i++){\n            edge &e\
    \ = G[v][i];\n            if(!used[e.to] && e.cap > 0){\n                T d =\
    \ dfs(e.to, t, min(f, e.cap));\n                if(d > 0){\n                 \
    \   e.cap -= d;\n                    G[e.to][e.rev].cap += d;\n              \
    \      return d;\n                }\n            }\n        }\n        return\
    \ 0;\n    }\n\n    T calc(int s, int t){\n        T flow = 0;\n        for(;;){\n\
    \            for(int i = 0;i < n;i++)used[i] = false;\n            int f = dfs(s,\
    \ t, inf<T>());\n            if(f == 0)return flow;\n            flow += f;\n\
    \        }\n    }\n};\n#line 5 \"verify/aoj/grl/6_A___ford_fulkerson.test.cpp\"\
    \n\nusing namespace mmrz;\n\nvoid mmrz::solve(){\n    int n, m;\n    cin >> n\
    \ >> m;\n    ford_fulkerson<int> f(n);\n    while(m--){\n        int a, b, c;\n\
    \        cin >> a >> b >> c;\n        f.add_edge(a, b, c);\n    }\n    cout <<\
    \ f.calc(0, n-1) << endl;\n}\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n\n#include \"./../../../template/template.hpp\"\n#include \"./../../../graph/ford_fulkerson.hpp\"\
    \n\nusing namespace mmrz;\n\nvoid mmrz::solve(){\n    int n, m;\n    cin >> n\
    \ >> m;\n    ford_fulkerson<int> f(n);\n    while(m--){\n        int a, b, c;\n\
    \        cin >> a >> b >> c;\n        f.add_edge(a, b, c);\n    }\n    cout <<\
    \ f.calc(0, n-1) << endl;\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/ford_fulkerson.hpp
  isVerificationFile: true
  path: verify/aoj/grl/6_A___ford_fulkerson.test.cpp
  requiredBy: []
  timestamp: '2024-07-06 23:08:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/grl/6_A___ford_fulkerson.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/grl/6_A___ford_fulkerson.test.cpp
- /verify/verify/aoj/grl/6_A___ford_fulkerson.test.cpp.html
title: verify/aoj/grl/6_A___ford_fulkerson.test.cpp
---

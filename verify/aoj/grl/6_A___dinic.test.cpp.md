---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dinic.hpp
    title: "\u6700\u5927\u6D41(Dinic)"
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
  bundledCode: "#line 1 \"verify/aoj/grl/6_A___dinic.test.cpp\"\n# define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\n\n#line\
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
    \ solve();\n}\n\nint main(){\n\tmmrz::solve();\n}\n#line 1 \"graph/dinic.hpp\"\
    \n\ntemplate<typename T>\nstruct dinic {\n\n    struct edge{\n        int to;\n\
    \        T cap;\n        T rev;\n    };\n    \n    int n;\n    vector<vector<edge>>\
    \ G;\n    vector<int> level;\n    vector<int> iter;\n\n    dinic(int _v) : n(_v),\
    \ G(n), level(n), iter(n) {}\n\n    void add_edge(int from, int to, T cap){\n\
    \        G[from].push_back((edge){to, cap, (T)G[to].size()});\n        G[to].push_back((edge){from,\
    \ 0, (T)(G[from].size() - 1)});\n    }\n\n    void bfs(int s){\n        for(int\
    \ i = 0;i < n;i++)level[i] = -1;\n        queue<int> que;\n        level[s] =\
    \ 0;\n        que.push(s);\n        while(!que.empty()){\n            int v =\
    \ que.front();\n            que.pop();\n            for(int i = 0;i < (int)G[v].size();i++){\n\
    \                edge &e = G[v][i];\n                if(e.cap > 0 && level[e.to]\
    \ < 0){\n                    level[e.to] = level[v] + 1;\n                   \
    \ que.push(e.to);\n                }\n            }\n        }\n    }\n\n    T\
    \ dfs(int v, int t, T f){\n        if(v == t)return f;\n        for(int &i = iter[v];i\
    \ < (int)G[v].size();i++){\n            edge &e = G[v][i];\n            if(e.cap\
    \ > 0 && level[v] < level[e.to]){\n                T d = dfs(e.to, t, min(f, e.cap));\n\
    \                if(d > 0){\n                    e.cap -= d;\n               \
    \     G[e.to][e.rev].cap += d;\n                    return d;\n              \
    \  }\n            }\n        }\n        return 0;\n    }\n\n    T calc(int s,\
    \ int t){\n        T flow = 0;\n        for(;;){\n            bfs(s);\n      \
    \      if(level[t] < 0)return flow;\n            for(int i = 0;i < n;i++)iter[i]\
    \ = 0;\n            int f;\n            while((f = dfs(s, t, inf<T>())) > 0) {\n\
    \                flow += f;\n            }\n        }\n    }\n};\n#line 5 \"verify/aoj/grl/6_A___dinic.test.cpp\"\
    \n\nusing namespace mmrz;\n\nvoid mmrz::solve(){\n    int n, m;\n    cin >> n\
    \ >> m;\n    dinic<int> f(n);\n    while(m--){\n        int a, b, c;\n       \
    \ cin >> a >> b >> c;\n        f.add_edge(a, b, c);\n    }\n    cout << f.calc(0,\
    \ n-1) << endl;\n}\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n\n#include \"./../../../template/template.hpp\"\n#include \"./../../../graph/dinic.hpp\"\
    \n\nusing namespace mmrz;\n\nvoid mmrz::solve(){\n    int n, m;\n    cin >> n\
    \ >> m;\n    dinic<int> f(n);\n    while(m--){\n        int a, b, c;\n       \
    \ cin >> a >> b >> c;\n        f.add_edge(a, b, c);\n    }\n    cout << f.calc(0,\
    \ n-1) << endl;\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/dinic.hpp
  isVerificationFile: true
  path: verify/aoj/grl/6_A___dinic.test.cpp
  requiredBy: []
  timestamp: '2024-07-07 01:02:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/grl/6_A___dinic.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/grl/6_A___dinic.test.cpp
- /verify/verify/aoj/grl/6_A___dinic.test.cpp.html
title: verify/aoj/grl/6_A___dinic.test.cpp
---
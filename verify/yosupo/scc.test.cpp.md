---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_components.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
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
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"verify/yosupo/scc.test.cpp\"\n# define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
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
    \ 1 \"graph/strongly_connected_components.hpp\"\n\n#line 3 \"graph/strongly_connected_components.hpp\"\
    \n\nstruct scc_graph {\n\tint n;\n\tint k;\n\tstd::vector<std::vector<int>> g;\n\
    \tstd::vector<std::vector<int>> rg;\n\tstd::vector<bool> used;\n\tstd::vector<int>\
    \ cmp;\n\tstd::vector<int> vs;\n\n\tscc_graph(int _n) : n(_n), k(0), g(n), rg(n),\
    \ used(n), cmp(n) {}\n\n\tvoid add_edge(int a, int b) {\n\t\tg[a].push_back(b);\n\
    \t\trg[b].push_back(a);\n\t}\n\n\tvoid dfs(int v){\n\t\tused[v] = true;\n\t\t\
    for(auto to : g[v]){\n\t\t\tif(not used[to])dfs(to);\n\t\t}\n\t\tvs.push_back(v);\n\
    \t}\n\n\tvoid rdfs(int v, int col){\n\t\tused[v] = true;\n\t\tcmp[v] = col;\n\t\
    \tfor(auto to : rg[v]){\n\t\t\tif(not used[to])rdfs(to, col);\n\t\t}\n\t}\n\n\t\
    std::vector<std::vector<int>> scc() {\n\t\tfor(int i = 0;i < n;i++){\n\t\t\tif(not\
    \ used[i])dfs(i);\n\t\t}\n\t\tfor(int i = 0;i < n;i++){\n\t\t\tused[i] = false;\n\
    \t\t}\n\t\tfor(auto i = vs.rbegin();i != vs.rend();i++){\n\t\t\tif(not used[*i])rdfs(*i,\
    \ k++);\n\t\t}\n\t\tstd::vector<std::vector<int>> ret(k);\n\t\tfor(int i = 0;i\
    \ < n;i++){\n\t\t\tret[cmp[i]].push_back(i);\n\t\t}\n\t\treturn ret;\n\t}\n};\n\
    #line 5 \"verify/yosupo/scc.test.cpp\"\n\nvoid mmrz::solve(){\n\tint n, m;\n\t\
    cin >> n >> m;\n\tscc_graph g(n);\n\twhile(m--){\n\t\tint u, v;\n\t\tcin >> u\
    \ >> v;\n\t\tg.add_edge(u, v);\n\t}\n\tvector<vector<int>> vs = g.scc();\n\tcout\
    \ << len(vs) << '\\n';\n\tfor(auto &v : vs){\n\t\tcout << len(v);\n\t\tfor(auto\
    \ &x : v)cout << \" \" << x;\n\t\tcout << '\\n';\n\t}\n}\n"
  code: "# define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include \"./../../template/template.hpp\"\
    \n#include \"./../../graph/strongly_connected_components.hpp\"\n\nvoid mmrz::solve(){\n\
    \tint n, m;\n\tcin >> n >> m;\n\tscc_graph g(n);\n\twhile(m--){\n\t\tint u, v;\n\
    \t\tcin >> u >> v;\n\t\tg.add_edge(u, v);\n\t}\n\tvector<vector<int>> vs = g.scc();\n\
    \tcout << len(vs) << '\\n';\n\tfor(auto &v : vs){\n\t\tcout << len(v);\n\t\tfor(auto\
    \ &x : v)cout << \" \" << x;\n\t\tcout << '\\n';\n\t}\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/strongly_connected_components.hpp
  isVerificationFile: true
  path: verify/yosupo/scc.test.cpp
  requiredBy: []
  timestamp: '2025-07-01 01:47:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/scc.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/scc.test.cpp
- /verify/verify/yosupo/scc.test.cpp.html
title: verify/yosupo/scc.test.cpp
---

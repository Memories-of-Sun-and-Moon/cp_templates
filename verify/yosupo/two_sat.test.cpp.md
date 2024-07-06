---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_components.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: graph/two_sat.hpp
    title: 2-SAT
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
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"verify/yosupo/two_sat.test.cpp\"\n# define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
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
    # define pb push_back\n# define exists(c, e)         ((c).find(e) != (c).end())\n\
    \nstruct INIT{\n\tINIT(){\n\t\tstd::ios::sync_with_stdio(false);\n\t\tstd::cin.tie(0);\n\
    \t\tcout << fixed << setprecision(20);\n\t}\n}INIT;\n\nnamespace mmrz {\n\tvoid\
    \ solve();\n}\n\nint main(){\n\tmmrz::solve();\n}\n#line 1 \"graph/two_sat.hpp\"\
    \n\n#line 1 \"graph/strongly_connected_components.hpp\"\n\nstruct scc_graph {\n\
    \tint n;\n\tint k;\n\tvector<vector<int>> g;\n\tvector<vector<int>> rg;\n\tvector<bool>\
    \ used;\n\tvector<int> cmp;\n\tvector<int> vs;\n\n\tscc_graph(int _n) : n(_n),\
    \ k(0), g(n), rg(n), used(n), cmp(n) {}\n\n\tvoid add_edge(int a, int b) {\n\t\
    \tg[a].push_back(b);\n\t\trg[b].push_back(a);\n\t}\n\n\tvoid dfs(int v){\n\t\t\
    used[v] = true;\n\t\tfor(auto to : g[v]){\n\t\t\tif(not used[to])dfs(to);\n\t\t\
    }\n\t\tvs.pb(v);\n\t}\n\n\tvoid rdfs(int v, int col){\n\t\tused[v] = true;\n\t\
    \tcmp[v] = col;\n\t\tfor(auto to : rg[v]){\n\t\t\tif(not used[to])rdfs(to, col);\n\
    \t\t}\n\t}\n\n\tvector<vector<int>> scc() {\n\t\tfor(int i = 0;i < n;i++){\n\t\
    \t\tif(not used[i])dfs(i);\n\t\t}\n\t\tfor(int i = 0;i < n;i++){\n\t\t\tused[i]\
    \ = false;\n\t\t}\n\t\tfor(auto i = vs.rbegin();i != vs.rend();i++){\n\t\t\tif(not\
    \ used[*i])rdfs(*i, k++);\n\t\t}\n\t\tvector<vector<int>> ret(k);\n\t\tfor(int\
    \ i = 0;i < n;i++){\n\t\t\tret[cmp[i]].push_back(i);\n\t\t}\n\t\treturn ret;\n\
    \t}\n};\n#line 3 \"graph/two_sat.hpp\"\n\nstruct two_sat {\n\tint n;\n\tscc_graph\
    \ g;\n\n\ttwo_sat(int _n) : n(_n), g(scc_graph(2*n)) {}\n\n\t// (i = f1) || (j\
    \ = f2)\n\tvoid add_clause(int i, bool f1, int j, bool f2){\n\t\tg.add_edge((i\
    \ << 1) ^ !f1, (j << 1) ^ f2);\n\t\tg.add_edge((j << 1) ^ !f2, (i << 1) ^ f1);\n\
    \t}\n\n\t// (i = f1) -> (j = f2) <=> (1 = !f1) || (j = f2)\n\tvoid add_if(int\
    \ i, bool f1, int j, bool f2){\n\t\tadd_clause(i, !f1, j, f2);\n\t}\n\n\t// i\n\
    \tvoid set_true(int i){\n\t\tadd_clause(i, true, i, true);\n\t}\n\n\t// !i\n\t\
    void set_false(int i){\n\t\tadd_clause(i, false, i, false);\n\t}\n\n\tvector<bool>\
    \ solve(){\n\t\tvector<vector<int>> scc = g.scc();\n\t\tvector<int> c(2*n);\n\t\
    \tfor(int i = 0;i < (int)scc.size();i++){\n\t\t\tfor(auto v : scc[i]){\n\t\t\t\
    \tc[v] = i;\n\t\t\t}\n\t\t}\n\t\tvector<bool> res(n);\n\t\tfor(int i = 0;i < n;i++){\n\
    \t\t\tif(c[i << 1] == c[i << 1 | 1])return vector<bool>();\n\t\t\tres[i] = (c[i\
    \ << 1] < c[i << 1 | 1]);\n\t\t}\n\t\treturn res;\n\t}\n};\n#line 5 \"verify/yosupo/two_sat.test.cpp\"\
    \n\nvoid mmrz::solve(){\n\tchar _p;\n\tstring _cnf;\n\tint n, m;\n\tcin >> _p\
    \ >> _cnf >> n >> m;\n\n\tauto f = [](int x) -> pair<int, bool> {\n\t\tbool tf\
    \ = (x > 0 ? true : false);\n\t\tx = abs(x)-1;\n\t\treturn make_pair(x, tf);\n\
    \t};\n\n\ttwo_sat ts(n);\n\twhile(m--){\n\t\tint x, y, _zero;\n\t\tcin >> x >>\
    \ y >> _zero;\n\t\tauto [nx, x_tf] = f(x);\n\t\tauto [ny, y_tf] = f(y);\n\t\t\
    ts.add_clause(nx, x_tf, ny, y_tf);\n\t}\n\n\tauto ret = ts.solve();\n\tif(ret.empty()){\n\
    \t\tcout << \"s UNSATISFIABLE\" << endl;\n\t\treturn;\n\t}\n\tcout << \"s SATISFIABLE\"\
    \ << endl;\n\tcout << \"v\";\n\trep(i, n){\n\t\tcout << \" \" << (ret[i] ? \"\"\
    \ : \"-\") << i+1;\n\t}\n\tcout << \" 0\" << endl;\n}\n"
  code: "# define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#include\
    \ \"./../../template/template.hpp\"\n#include \"./../../graph/two_sat.hpp\"\n\n\
    void mmrz::solve(){\n\tchar _p;\n\tstring _cnf;\n\tint n, m;\n\tcin >> _p >> _cnf\
    \ >> n >> m;\n\n\tauto f = [](int x) -> pair<int, bool> {\n\t\tbool tf = (x >\
    \ 0 ? true : false);\n\t\tx = abs(x)-1;\n\t\treturn make_pair(x, tf);\n\t};\n\n\
    \ttwo_sat ts(n);\n\twhile(m--){\n\t\tint x, y, _zero;\n\t\tcin >> x >> y >> _zero;\n\
    \t\tauto [nx, x_tf] = f(x);\n\t\tauto [ny, y_tf] = f(y);\n\t\tts.add_clause(nx,\
    \ x_tf, ny, y_tf);\n\t}\n\n\tauto ret = ts.solve();\n\tif(ret.empty()){\n\t\t\
    cout << \"s UNSATISFIABLE\" << endl;\n\t\treturn;\n\t}\n\tcout << \"s SATISFIABLE\"\
    \ << endl;\n\tcout << \"v\";\n\trep(i, n){\n\t\tcout << \" \" << (ret[i] ? \"\"\
    \ : \"-\") << i+1;\n\t}\n\tcout << \" 0\" << endl;\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/two_sat.hpp
  - graph/strongly_connected_components.hpp
  isVerificationFile: true
  path: verify/yosupo/two_sat.test.cpp
  requiredBy: []
  timestamp: '2024-07-07 01:02:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/two_sat.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/two_sat.test.cpp
- /verify/verify/yosupo/two_sat.test.cpp.html
title: verify/yosupo/two_sat.test.cpp
---

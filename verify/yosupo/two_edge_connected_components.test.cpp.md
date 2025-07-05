---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/union_find.hpp
    title: Union-Find
  - icon: ':heavy_check_mark:'
    path: graph/lowlink.hpp
    title: "lowlink\u3092\u7528\u3044\u305F\u6A4B\u30FB\u95A2\u7BC0\u70B9\u306E\u691C\
      \u51FA"
  - icon: ':heavy_check_mark:'
    path: graph/two_edge_connected_components.hpp
    title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"verify/yosupo/two_edge_connected_components.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
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
    \ 2 \"graph/two_edge_connected_components.hpp\"\n\n#line 2 \"data_structure/union_find.hpp\"\
    \n\n#line 5 \"data_structure/union_find.hpp\"\n\nstruct union_find {\n\tstd::vector<int>\
    \ v;\n\tint g_size;\n\tint n;\n\n\tunion_find(size_t size) : v(size, -1), g_size(size),\
    \ n(size) {}\n\n\tint root(int x){\n\t\tassert(x < n);\n\t\treturn (v[x] < 0 ?\
    \ x : v[x] = root(v[x]));\n\t}\n\n\tbool is_root(int x){\n\t\tassert(x < n);\n\
    \t\treturn root(x) == x;\n\t}\n\n\tbool unite(int x, int y){\n\t\tassert(x < n\
    \ && y < n);\n\t\tx = root(x);\n\t\ty = root(y);\n\t\tif(x != y){\n\t\t\tif(v[x]\
    \ > v[y])std::swap(x, y);\n\t\t\tv[x] += v[y];\n\t\t\tv[y] = x;\n\t\t\tg_size--;\n\
    \t\t\treturn true;\n\t\t}\n\t\treturn false;\n\t}\n\n\tbool is_same(int x,int\
    \ y){\n\t\tassert(x < n && y < n);\n\t\treturn root(x) == root(y);\n\t}\n\n\t\
    int get_size(int x){\n\t\tassert(x < n);\n\t\tx = root(x);\n\t\treturn -v[x];\n\
    \t}\n\n\tint groups_size(){\n\t\treturn g_size;\n\t}\n\n\tstd::vector<std::vector<int>>\
    \ groups(){\n\t\tstd::vector<std::vector<int>> member(n);\n\t\tfor(int i = 0;i\
    \ < n;i++){\n\t\t\tmember[root(i)].push_back(i);\n\t\t}\n\n\t\tstd::vector<std::vector<int>>\
    \ ret;\n\t\tfor(int i = 0;i < n;i++){\n\t\t\tif(member[i].empty())continue;\n\t\
    \t\tret.push_back(member[i]);\n\t\t}\n\t\treturn ret;\n\t}\n};\n#line 2 \"graph/lowlink.hpp\"\
    \n\n#line 5 \"graph/lowlink.hpp\"\n\nclass lowlink{\n\tstd::vector<std::vector<int>>\
    \ g;\n\tstd::vector<int> order, low;\n\tstd::vector<bool> __is_articulation;\n\
    \n\tvoid dfs(int cur, int pre, int &time){\n\t\tint count_child = 0;\n\t\tlow[cur]\
    \ = order[cur] = time++;\n\t\tbool first_parent = true;\n\t\tfor(int to : g[cur]){\n\
    \t\t\tif(to == pre && std::exchange(first_parent, false))continue;\n\t\t\tif(order[to]\
    \ == -1){\n\t\t\t\tdfs(to, cur, time);\n\t\t\t\tcount_child++;\n\t\t\t\tif(pre\
    \ != -1){\n\t\t\t\t\tif(not __is_articulation[cur]) __is_articulation[cur] = (low[to]\
    \ >= order[cur]);\n\t\t\t\t}\n\t\t\t\tlow[cur] = std::min(low[cur], low[to]);\n\
    \t\t\t}else{\n\t\t\t\tlow[cur] = std::min(low[cur], order[to]);\n\t\t\t}\n\t\t\
    }\n\t\tif(pre == -1){\n\t\t\t__is_articulation[cur] = (count_child >= 2);\n\t\t\
    }\n\t}\n\npublic:\n\n\tlowlink(const std::vector<std::vector<int>> &_g) : g(_g),\
    \ order(g.size(), -1), low(g.size()), __is_articulation(g.size(), false){\n\t\t\
    int time = 0;\n\t\tfor(int v = 0;v < (int)g.size();v++){\n\t\t\tif(order[v] ==\
    \ -1){\n\t\t\t\tdfs(v, -1, time);\n\t\t\t}\n\t\t}\n\t}\n\n\tbool is_bridge(int\
    \ u, int v) const {\n\t\tif(order[u] > order[v]){\n\t\t\tstd::swap(u, v);\n\t\t\
    }\n\t\treturn order[u] < low[v];\n\t}\n\n\tbool is_articulation(int v) const {\n\
    \t\treturn __is_articulation[v];\n\t}\n};\n#line 5 \"graph/two_edge_connected_components.hpp\"\
    \n\n#line 8 \"graph/two_edge_connected_components.hpp\"\n\nauto two_edge_connected_components(std::vector<std::vector<int>>\
    \ &g){\n\tlowlink l(g);\n\tunion_find uf((int)g.size());\n\tfor(int i = 0;i <\
    \ (int)g.size();i++){\n\t\tfor(int to : g[i]){\n\t\t\tif(not l.is_bridge(i, to)){\n\
    \t\t\t\tuf.unite(i, to);\n\t\t\t}\n\t\t}\n\t}\n\n\tstd::vector<std::vector<int>>\
    \ group = uf.groups();\n\tstd::vector<int> comp((int)g.size());\n\tfor(int i =\
    \ 0;i < (int)group.size();i++){\n\t\tfor(int v : group[i]){\n\t\t\tcomp[v] = i;\n\
    \t\t}\n\t}\n\n\tstd::vector<std::vector<int>> tree((int)group.size());\n\tfor(int\
    \ i = 0;i < (int)g.size();i++){\n\t\tfor(int to : g[i]){\n\t\t\tif(comp[i] !=\
    \ comp[to]){\n\t\t\t\ttree[comp[i]].push_back(comp[to]);\n\t\t\t}\n\t\t}\n\t}\n\
    \n\treturn make_tuple(group, comp, tree);\n}\n#line 5 \"verify/yosupo/two_edge_connected_components.test.cpp\"\
    \n\nvoid mmrz::solve(){\n\tint n, m;\n\tcin >> n >> m;\n\tvector<vector<int>>\
    \ g(n);\n\twhile(m--){\n\t\tint a, b;\n\t\tcin >> a >> b;\n\t\tg[a].pb(b);\n\t\
    \tg[b].pb(a);\n\t}\n\n\tauto [groups, comp, tree] = two_edge_connected_components(g);\n\
    \n\tcout << len(groups) << '\\n';\n\tfor(auto v : groups){\n\t\tcout << len(v);\n\
    \t\tfor(auto c : v){\n\t\t\tcout << \" \" << c;\n\t\t}\n\t\tcout << '\\n';\n\t\
    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#include \"./../../template/template.hpp\"\n#include \"./../../graph/two_edge_connected_components.hpp\"\
    \n\nvoid mmrz::solve(){\n\tint n, m;\n\tcin >> n >> m;\n\tvector<vector<int>>\
    \ g(n);\n\twhile(m--){\n\t\tint a, b;\n\t\tcin >> a >> b;\n\t\tg[a].pb(b);\n\t\
    \tg[b].pb(a);\n\t}\n\n\tauto [groups, comp, tree] = two_edge_connected_components(g);\n\
    \n\tcout << len(groups) << '\\n';\n\tfor(auto v : groups){\n\t\tcout << len(v);\n\
    \t\tfor(auto c : v){\n\t\t\tcout << \" \" << c;\n\t\t}\n\t\tcout << '\\n';\n\t\
    }\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/two_edge_connected_components.hpp
  - data_structure/union_find.hpp
  - graph/lowlink.hpp
  isVerificationFile: true
  path: verify/yosupo/two_edge_connected_components.test.cpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/two_edge_connected_components.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/two_edge_connected_components.test.cpp
- /verify/verify/yosupo/two_edge_connected_components.test.cpp.html
title: verify/yosupo/two_edge_connected_components.test.cpp
---

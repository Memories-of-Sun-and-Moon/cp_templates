---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/primal_dual_with_negative_edges.hpp\"\n\ntemplate<typename\
    \ T> \nstruct primal_dual_with_negative_edges {\n\tstruct edge {\n\t\tint to;\n\
    \t\tT cap, cost, rev;\n\t};\n\tint V;\n\tT infty;\n\tvector<vector<edge>> G;\n\
    \tvector<T> dist;\n\tvector<int> prevv, preve;\n\n\tprimal_dual_with_negative_edges(int\
    \ _V) : V(_V), infty(numeric_limits<T>::max()/2) {\n\t\tG.resize(V);\n\t\tdist.resize(V);\n\
    \t\tprevv.resize(V);\n\t\tpreve.resize(V);\n\t}\n\n\tvoid add_edge(int from, int\
    \ to, int cap, int cost) {\n\t\tG[from].push_back((edge){to, cap, cost, (int)G[to].size()});\n\
    \t\tG[to].push_back((edge){from, 0, -cost, (int)G[from].size()-1});\n\t}\n\n\t\
    optional<T> min_cost_flow(int s, int t, T f) {\n\t\tint res = 0;\n\t\twhile(f\
    \ > 0){\n\t\t\tdist.assign(V, infty);\n\t\t\tdist[s] = 0;\n\t\t\tbool update =\
    \ true;\n\t\t\twhile(update) {\n\t\t\t\tupdate = false;\n\t\t\t\tfor(int v = 0;v\
    \ < V;v++) {\n\t\t\t\t\tif(dist[v] == infty) continue;\n\t\t\t\t\tfor(int i =\
    \ 0;i < (int)G[v].size();i++) {\n\t\t\t\t\t\tauto &e = G[v][i];\n\t\t\t\t\t\t\
    if(e.cap > 0 && dist[e.to] > dist[v]+e.cost) {\n\t\t\t\t\t\t\tdist[e.to] = dist[v]\
    \ + e.cost;\n\t\t\t\t\t\t\tprevv[e.to] = v;\n\t\t\t\t\t\t\tpreve[e.to] = i;\n\t\
    \t\t\t\t\t\tupdate = true;\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\n\
    \t\t\tif(dist[t] == infty) {\n\t\t\t\treturn nullopt;\n\t\t\t}\n\n\t\t\tT d =\
    \ f;\n\t\t\tfor(int v = t;v != s;v = prevv[v]) {\n\t\t\t\td = min(d, G[prevv[v]][preve[v]].cap);\n\
    \t\t\t}\n\t\t\tf -= d;\n\t\t\tres += d*dist[t];\n\t\t\tfor(int v = t;v != s;v\
    \ = prevv[v]) {\n\t\t\t\tauto &e = G[prevv[v]][preve[v]];\n\t\t\t\te.cap -= d;\n\
    \t\t\t\tG[v][e.rev].cap += d;\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  code: "\ntemplate<typename T> \nstruct primal_dual_with_negative_edges {\n\tstruct\
    \ edge {\n\t\tint to;\n\t\tT cap, cost, rev;\n\t};\n\tint V;\n\tT infty;\n\tvector<vector<edge>>\
    \ G;\n\tvector<T> dist;\n\tvector<int> prevv, preve;\n\n\tprimal_dual_with_negative_edges(int\
    \ _V) : V(_V), infty(numeric_limits<T>::max()/2) {\n\t\tG.resize(V);\n\t\tdist.resize(V);\n\
    \t\tprevv.resize(V);\n\t\tpreve.resize(V);\n\t}\n\n\tvoid add_edge(int from, int\
    \ to, int cap, int cost) {\n\t\tG[from].push_back((edge){to, cap, cost, (int)G[to].size()});\n\
    \t\tG[to].push_back((edge){from, 0, -cost, (int)G[from].size()-1});\n\t}\n\n\t\
    optional<T> min_cost_flow(int s, int t, T f) {\n\t\tint res = 0;\n\t\twhile(f\
    \ > 0){\n\t\t\tdist.assign(V, infty);\n\t\t\tdist[s] = 0;\n\t\t\tbool update =\
    \ true;\n\t\t\twhile(update) {\n\t\t\t\tupdate = false;\n\t\t\t\tfor(int v = 0;v\
    \ < V;v++) {\n\t\t\t\t\tif(dist[v] == infty) continue;\n\t\t\t\t\tfor(int i =\
    \ 0;i < (int)G[v].size();i++) {\n\t\t\t\t\t\tauto &e = G[v][i];\n\t\t\t\t\t\t\
    if(e.cap > 0 && dist[e.to] > dist[v]+e.cost) {\n\t\t\t\t\t\t\tdist[e.to] = dist[v]\
    \ + e.cost;\n\t\t\t\t\t\t\tprevv[e.to] = v;\n\t\t\t\t\t\t\tpreve[e.to] = i;\n\t\
    \t\t\t\t\t\tupdate = true;\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\n\
    \t\t\tif(dist[t] == infty) {\n\t\t\t\treturn nullopt;\n\t\t\t}\n\n\t\t\tT d =\
    \ f;\n\t\t\tfor(int v = t;v != s;v = prevv[v]) {\n\t\t\t\td = min(d, G[prevv[v]][preve[v]].cap);\n\
    \t\t\t}\n\t\t\tf -= d;\n\t\t\tres += d*dist[t];\n\t\t\tfor(int v = t;v != s;v\
    \ = prevv[v]) {\n\t\t\t\tauto &e = G[prevv[v]][preve[v]];\n\t\t\t\te.cap -= d;\n\
    \t\t\t\tG[v][e.rev].cap += d;\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/primal_dual_with_negative_edges.hpp
  requiredBy: []
  timestamp: '2025-02-22 05:25:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/primal_dual_with_negative_edges.hpp
layout: document
redirect_from:
- /library/graph/primal_dual_with_negative_edges.hpp
- /library/graph/primal_dual_with_negative_edges.hpp.html
title: graph/primal_dual_with_negative_edges.hpp
---

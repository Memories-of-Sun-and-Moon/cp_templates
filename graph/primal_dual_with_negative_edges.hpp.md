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
  bundledCode: "#line 1 \"graph/primal_dual_with_negative_edges.hpp\"\n\n#include<numeric>\n\
    #include<utility>\n#include<vector>\n\ntemplate<typename T> \nstruct primal_dual_with_negative_edges\
    \ {\n\tstruct edge {\n\t\tint to;\n\t\tT cap, cost, rev;\n\t\tT init_cap;\n\t\
    };\n\tint V;\n\tT infty;\n\tstd::vector<std::vector<edge>> G;\n\tstd::vector<T>\
    \ dist;\n\tstd::vector<int> prevv, preve;\n\n\tstd::vector<int> from_idx, to_idx;\n\
    \tint edge_idx;\n\n\tprimal_dual_with_negative_edges(int _V) : V(_V), infty(std::numeric_limits<T>::max()/2),\
    \ edge_idx(0) {\n\t\tG.resize(V);\n\t\tdist.resize(V);\n\t\tprevv.resize(V);\n\
    \t\tpreve.resize(V);\n\t}\n\n\tint add_edge(int from, int to, T cap, T cost) {\n\
    \t\tG[from].push_back((edge){to, cap, cost, (int)G[to].size(), cap});\n\t\tG[to].push_back((edge){from,\
    \ 0, -cost, (int)G[from].size()-1, 0});\n\t\tfrom_idx.emplace_back(from);\n\t\t\
    to_idx.emplace_back((int)G[from].size()-1);\n\t\t\n\t\treturn edge_idx++;\n\t\
    }\n\n\tstd::pair<bool, T> min_cost_flow(int s, int t, T f) {\n\t\tT res = 0;\n\
    \t\twhile(f > 0){\n\t\t\tdist.assign(V, infty);\n\t\t\tdist[s] = 0;\n\t\t\tbool\
    \ update = true;\n\t\t\twhile(update) {\n\t\t\t\tupdate = false;\n\t\t\t\tfor(int\
    \ v = 0;v < V;v++) {\n\t\t\t\t\tif(dist[v] == infty) continue;\n\t\t\t\t\tfor(int\
    \ i = 0;i < (int)G[v].size();i++) {\n\t\t\t\t\t\tauto &e = G[v][i];\n\t\t\t\t\t\
    \tif(e.cap > 0 && dist[e.to] > dist[v]+e.cost) {\n\t\t\t\t\t\t\tdist[e.to] = dist[v]\
    \ + e.cost;\n\t\t\t\t\t\t\tprevv[e.to] = v;\n\t\t\t\t\t\t\tpreve[e.to] = i;\n\t\
    \t\t\t\t\t\tupdate = true;\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\n\
    \t\t\tif(dist[t] == infty) {\n\t\t\t\treturn make_pair(false, res);\n\t\t\t}\n\
    \n\t\t\tT d = f;\n\t\t\tfor(int v = t;v != s;v = prevv[v]) {\n\t\t\t\td = min(d,\
    \ G[prevv[v]][preve[v]].cap);\n\t\t\t}\n\t\t\tf -= d;\n\t\t\tres += d*dist[t];\n\
    \t\t\tfor(int v = t;v != s;v = prevv[v]) {\n\t\t\t\tauto &e = G[prevv[v]][preve[v]];\n\
    \t\t\t\te.cap -= d;\n\t\t\t\tG[v][e.rev].cap += d;\n\t\t\t}\n\t\t}\n\t\treturn\
    \ make_pair(true, res);\n\t}\n\n\tT get_flow(int idx){\n\t\treturn G[from_idx[idx]][to_idx[idx]].init_cap\
    \ - G[from_idx[idx]][to_idx[idx]].cap;\n\t}\n};\n"
  code: "\n#include<numeric>\n#include<utility>\n#include<vector>\n\ntemplate<typename\
    \ T> \nstruct primal_dual_with_negative_edges {\n\tstruct edge {\n\t\tint to;\n\
    \t\tT cap, cost, rev;\n\t\tT init_cap;\n\t};\n\tint V;\n\tT infty;\n\tstd::vector<std::vector<edge>>\
    \ G;\n\tstd::vector<T> dist;\n\tstd::vector<int> prevv, preve;\n\n\tstd::vector<int>\
    \ from_idx, to_idx;\n\tint edge_idx;\n\n\tprimal_dual_with_negative_edges(int\
    \ _V) : V(_V), infty(std::numeric_limits<T>::max()/2), edge_idx(0) {\n\t\tG.resize(V);\n\
    \t\tdist.resize(V);\n\t\tprevv.resize(V);\n\t\tpreve.resize(V);\n\t}\n\n\tint\
    \ add_edge(int from, int to, T cap, T cost) {\n\t\tG[from].push_back((edge){to,\
    \ cap, cost, (int)G[to].size(), cap});\n\t\tG[to].push_back((edge){from, 0, -cost,\
    \ (int)G[from].size()-1, 0});\n\t\tfrom_idx.emplace_back(from);\n\t\tto_idx.emplace_back((int)G[from].size()-1);\n\
    \t\t\n\t\treturn edge_idx++;\n\t}\n\n\tstd::pair<bool, T> min_cost_flow(int s,\
    \ int t, T f) {\n\t\tT res = 0;\n\t\twhile(f > 0){\n\t\t\tdist.assign(V, infty);\n\
    \t\t\tdist[s] = 0;\n\t\t\tbool update = true;\n\t\t\twhile(update) {\n\t\t\t\t\
    update = false;\n\t\t\t\tfor(int v = 0;v < V;v++) {\n\t\t\t\t\tif(dist[v] == infty)\
    \ continue;\n\t\t\t\t\tfor(int i = 0;i < (int)G[v].size();i++) {\n\t\t\t\t\t\t\
    auto &e = G[v][i];\n\t\t\t\t\t\tif(e.cap > 0 && dist[e.to] > dist[v]+e.cost) {\n\
    \t\t\t\t\t\t\tdist[e.to] = dist[v] + e.cost;\n\t\t\t\t\t\t\tprevv[e.to] = v;\n\
    \t\t\t\t\t\t\tpreve[e.to] = i;\n\t\t\t\t\t\t\tupdate = true;\n\t\t\t\t\t\t}\n\t\
    \t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\n\t\t\tif(dist[t] == infty) {\n\t\t\t\treturn\
    \ make_pair(false, res);\n\t\t\t}\n\n\t\t\tT d = f;\n\t\t\tfor(int v = t;v !=\
    \ s;v = prevv[v]) {\n\t\t\t\td = min(d, G[prevv[v]][preve[v]].cap);\n\t\t\t}\n\
    \t\t\tf -= d;\n\t\t\tres += d*dist[t];\n\t\t\tfor(int v = t;v != s;v = prevv[v])\
    \ {\n\t\t\t\tauto &e = G[prevv[v]][preve[v]];\n\t\t\t\te.cap -= d;\n\t\t\t\tG[v][e.rev].cap\
    \ += d;\n\t\t\t}\n\t\t}\n\t\treturn make_pair(true, res);\n\t}\n\n\tT get_flow(int\
    \ idx){\n\t\treturn G[from_idx[idx]][to_idx[idx]].init_cap - G[from_idx[idx]][to_idx[idx]].cap;\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/primal_dual_with_negative_edges.hpp
  requiredBy: []
  timestamp: '2025-07-01 01:47:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/primal_dual_with_negative_edges.hpp
layout: document
redirect_from:
- /library/graph/primal_dual_with_negative_edges.hpp
- /library/graph/primal_dual_with_negative_edges.hpp.html
title: graph/primal_dual_with_negative_edges.hpp
---

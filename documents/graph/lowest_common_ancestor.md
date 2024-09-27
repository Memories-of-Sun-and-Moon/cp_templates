---
title: Lowest Common Ancestor
documentation_of: ./../../graph/lowest_common_ancestor.hpp
---

# Lowest Common Ancestor

## 使い方

``lowest_common_ancestor(vector<vector<int>> g, int root)`` : $root$ を 根とする木の LCA を求めるためのコンストラクタ。 $O(N \log N)$
``get(int u, int v)`` : 頂点 $u, v$ の $LCA$ を求める。 $O(\log N)$

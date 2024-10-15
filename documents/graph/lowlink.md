---
title: lowlinkを用いた橋・関節点の検出
documentation_of: ./../../graph/lowlink.hpp
---

# lowlinkを用いた橋・関節点の検出

## 使い方

- ``lowlink(vector<vector<int>> g)`` : グラフ $G$ に関する lowlink を求めるコンストラクタ。 $O(N)$
- ``is_bridge(int u, int v)`` : 辺 $(u, v)$ が橋かどうかを返す。 $O(1)$
- ``is_articulation(int v)`` : 頂点 $v$ が関節点かどうかを返す。 $O(1)$

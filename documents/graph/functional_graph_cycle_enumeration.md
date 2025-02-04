---
title: functional_graph のサイクル列挙
documentation_of: ./../../graph/functinoal_graph_cycle_enumeration.hpp
---

# functional_graph のサイクル列挙

## 使い方

- ``vector<vector<int>> functinoal_graph_cycle_enumeration(vector<int> a)`` : $(i, a_i)$ に辺が張られている functional graph について、全てのサイクルを返す。 $O(N)$

## 説明

functional graph 内では $\rho$ の形が存在する。重複して頂点を見ることなく、サイクルを検出したい。

探索中に頂点に付けるラベルについて、

0. 未訪問
1. サイクルに含まれる
2. サイクルに含まれない

とする。

頂点 $i$ について、未訪問であれば $i$ から functional graph を辿る。

既に訪問済みの頂点に到達するまでラベル $1$ を暫定的に振る（ここで、初めて見つけた到達済みの頂点を $v$ とする）。

$v$ から functional graph を辿り、再び $v$ にたどり着くまでが実際にサイクルとなっている。

また、 $i$ から $v$ の手前までのパスはサイクルではないため、ラベル $2$ を振り直す。

## verify

- [CF897-D](https://codeforces.com/contest/1867/submission/304415923)

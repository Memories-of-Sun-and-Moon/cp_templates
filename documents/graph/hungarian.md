---
title: 割当問題（ハンガリアン法）
documentation_of: ./../../graph/hungarian.hpp
---

# ハンガリアン法

## 使い方

行が人、列が仕事を表す $N$ 行 $N$ 列の行列を用意する。（割り当てがない場合は、$A_{i, j} = 0$ としてよい）

- ``vector<int> hungarian<bool is_min, typename T>(vector<vector<T>> A)`` : 割当問題における
  - ``is_min`` が ``true`` の時 : 最小重み最大マッチングの割り当てを返す $O(N^3)$
  - ``is_min`` が ``false`` の時 : 最大重み最大マッチングの割り当てを返す $O(N^3)$

## メモ

割当問題をハンガリアン法で解く。

- 最小重み最大マッチングを、最小費用流で解けることを理解するのが前提
- $i$ からスタートする増加路を考える
- 二部グラフの最大マッチングの形のグラフになっていることを活用して、（ダイクストラ法などのグラフアルゴリズムを使うことなく）ポテンシャルの計算をするのが肝っぽい

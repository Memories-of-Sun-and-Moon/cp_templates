---
title: 2-SAT
documentation_of: ./../../graph/two_sat.hpp
---

# 2-SAT

## 使い方

- ``two_sat(n)`` : コンストラクタ。$n$ は変数の数を表す
- ``void add_clause(int i, int f1, int j, int f2)`` : 句を追加する
- ``void add_clause(int i, int f1, int j, int f2)`` : 句を追加する
- ``void add_true(int i)`` : 句を追加する
- ``void add_false(int i)`` : 句を追加する
- ``vector<bool> solve()`` : 与えられた $n$ 変数 $m$ 句が充足可能か調べる。充足可能であった場合、真偽の割り当て例を $1$ つ返す。不可能な場合、空の配列を返す。 $O(N+M)$

## 概要

論理式の対応を有向グラフとみて、矛盾がないかをチェックする。チェックに強連結成分分解を行う部分がネックとなり、$O(N+M)$ となる。

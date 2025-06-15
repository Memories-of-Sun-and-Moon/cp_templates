---
title: ハッシュマップ
documentation_of: ./../../data_structure/hash_map.hpp
---

# ハッシュマップ

## 使い方

``hash_map<Key, Val, N, HashFunc>`` : $N$ 程度の種類を格納できるハッシュマップを用意。
1. $N$ は格納予定の量の $2$ 倍程度とするとよさそう
2. ハッシュ関数が無い型を使うときは HashFunc を定義する

## 概要

``unordered_map`` の代用

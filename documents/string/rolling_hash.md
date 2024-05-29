---
title: ローリングハッシュ
documentation_of: ./../../string/rolling_hash.hpp
---

# ローリングハッシュ

## 使い方

添え字は **0-indexed** であることに注意。

- ``rolling_hash(string s)`` : $s$ のハッシュ値の前計算を行う $O(\lvert s \rvert)$
- ``ull slice(int begin, int length)`` : $s$ の $begin$ 文字目から $length$ 文字のハッシュを返す。

## 概要

[参考](https://qiita.com/keymoon/items/11fac5627672a6d6a9f6)

MOD $2^{61}-1$ を採用している。MOD をランダムにしていないため、文字列の統合等をしなくとも、文字長が同じであれば一致判定を行うことができる。

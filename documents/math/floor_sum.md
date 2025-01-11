---
title: floor_sum
documentation_of: ./../../math/floor_sum.hpp
---

# floor_sum

## 使い方

- ``floor_sum(ll n, ll m, ll a, ll b)`` : $\sum_{i=0}^{N-1} \lfloor \frac{Ai+B}{M} \rfloor$ の値を返す。 $O(\log a + log m)$

## 説明

[参考(ACL contest のユーザー解説)](https://atcoder.jp/contests/practice2/editorial/579)

以下、一瞬で理解できなかったパートの行間を埋めたもの。

$f(n, m, a, b) = \sum_{i=0}^{N-1} \lfloor \frac{Ai+B}{M} \rfloor$ とする。

- $a \geq m$ の場合、答えに $\frac{(n-1)n}{2}\times \lfloor \frac{a}{m} \rfloor$ を加算する
- $b \geq m$ の場合、答えに $n \times \lfloor \frac{b}{m} \rfloor$ を加算する

事によって、 $1 \leq a < m, 0 \leq b < m$ の場合に帰着できる（$a=0$ は自明）

そして、 $y = \lfloor \frac{an+b}{m} \rfloor, z = (an+b)\% m$ として次の等式が成立する。

$$f(n, m, a, b) = f(y, a, m, z)$$

$m, a$ がユークリッドの互除法と同じ挙動をする （$\because (an+b, m), (m, (an+b)\%m), \cdots$ のような遷移が $a$ にも存在する）ので、 $O(\log a + \log m)$ で計算可能となる。

> $$f(n, m, a, b) = \sum_{x=1}^{y}(\# \; of \; i \in \{0, 1, \cdots, n-1\} \; \rm{s.t.} \; \lfloor \frac{ai+b}{m} \rfloor) \geq x$$

$\lfloor \frac{ai+b}{m} \rfloor = x$ である数を数えている

> $$f(n, m, a, b) = \sum_{x=0}^{y-1}(\# \; of \; i \in \{0, 1, \cdots, n-1\} \; \rm{s.t.} \; \lfloor \frac{ai+b}{m} \rfloor) \geq (y-x)$$

for 文の順序を逆にした感じ



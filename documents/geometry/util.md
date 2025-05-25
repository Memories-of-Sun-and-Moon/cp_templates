---
title: 幾何ライブラリ
documentation_of: ./../../geometry/util.hpp
---

# 幾何ライブラリ

幾何に関するものをまとめたライブラリ。ファイル分け等は要検討

# 使い方

- EPS は ``10^{-9}`` 統一
- 浮動小数型として ``long double`` を採用

## point 型

点やベクトルを表す際に使用

- 四則演算
- 絶対値
- ノルム
- 比較( x 座標優先)
- 入出力

## segment 型

線分を表す際に使用

- 入出力

## line 型

直線を表す際に使用。 segment と同一

## circle 型

円を表す際に使用。

# 関数群

## ``DOUBLE dot(point a, point b)``

- $2$ 点の内積を計算

## ``DOUBLE cross(point a, point b)``

- $2$ 点の外積を計算

## ``int ccw(point p0, p1, p2)``

$3$ 点の関係を判定

- ``COUNTER_CLOCKWISE : 1``
- ``CLOCKWISE : -1``
- ``ONLINE_BACK : 2``
- ``ONLINE_FRONT : -2``
- ``ON_SEGMENT : 0``

を返す

## ``bool intersect(segment s1, segment s2)``

- $2$ 直線の交差判定

## ``point project(line s, point p)``

- 直線と点の射影を返す

## ``point reflect(line s, point p)``

- 直線と点の反射を返す

## ``DOUBLE get_distance(line l, point p)``
## ``DOUBLE get_distance_sp(segment l, point p)``
## ``DOUBLE get_distance(segment s1, segment_s2)``

- 距離を返す

## ``vector<point> get_crosspoint(line l, line m)``

- $2$ 直線の交点を返す。ない場合は空の配列が返る

## ``is_orthogonal(point a, point b)``
## ``is_orthogonal(segment a, segment b)``

- 直交判定をする

## ``is_parallel(point a, point b)``
## ``is_parallel(segment a, segment b)``

- 平行判定をする

## ``DOUBLE area(polygon p)``

- (凸とは限らない)多角形 $p$ の面積を求める

## ``bool is_convex(polygon p, bool allow_colinear=false)``

- 多角形 $p$ の凸性判定を行う(``allow_colinear=true`` の時は、$3$ 点が同一直線状にあることを許す)

## ``int contains(polygon g, point p)``

- (凸とは限らない)多角形 $g$ と点 $p$ の包含関係を返す
  - 含まれる場合は 2
  - 辺上は 1
  - それ以外は 0

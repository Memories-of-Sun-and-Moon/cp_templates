---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/area_of_union_of_rectangles.hpp
    title: "area_of_union_of_rectangles(\u9577\u65B9\u5F62\u306E\u548C\u96C6\u5408\
      \u306E\u9762\u7A4D)"
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_segment_tree.hpp
    title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/area_of_union_of_rectangles
    links:
    - https://judge.yosupo.jp/problem/area_of_union_of_rectangles
  bundledCode: "#line 1 \"verify/yosupo/area_of_union_of_rectangles.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/area_of_union_of_rectangles\"\n\n\
    #line 1 \"template/template.hpp\"\n# include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing ull = unsigned long long;\nconst double pi\
    \ = acos(-1);\ntemplate<class T>constexpr T inf() { return ::std::numeric_limits<T>::max();\
    \ }\ntemplate<class T>constexpr T hinf() { return inf<T>() / 2; }\ntemplate <typename\
    \ T_char>T_char TL(T_char cX) { return tolower(cX); }\ntemplate <typename T_char>T_char\
    \ TU(T_char cX) { return toupper(cX); }\ntemplate<class T> bool chmin(T& a,T b)\
    \ { if(a > b){a = b; return true;} return false; }\ntemplate<class T> bool chmax(T&\
    \ a,T b) { if(a < b){a = b; return true;} return false; }\nint popcnt(unsigned\
    \ long long n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++;\
    \ return cnt; }\nint d_sum(ll n) { int ret = 0; while (n > 0) { ret += n % 10;\
    \ n /= 10; }return ret; }\nint d_cnt(ll n) { int ret = 0; while (n > 0) { ret++;\
    \ n /= 10; }return ret; }\nll gcd(ll a, ll b) { if (b == 0)return a; return gcd(b,\
    \ a%b); };\nll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g*b; };\nll MOD(ll\
    \ x, ll m){return (x%m+m)%m; }\nll FLOOR(ll x, ll m) {ll r = (x%m+m)%m; return\
    \ (x-r)/m; }\ntemplate<class T> using dijk = priority_queue<T, vector<T>, greater<T>>;\n\
    # define all(qpqpq)           (qpqpq).begin(),(qpqpq).end()\n# define UNIQUE(wpwpw)\
    \        (wpwpw).erase(unique(all((wpwpw))),(wpwpw).end())\n# define LOWER(epepe)\
    \         transform(all((epepe)),(epepe).begin(),TL<char>)\n# define UPPER(rprpr)\
    \         transform(all((rprpr)),(rprpr).begin(),TU<char>)\n# define rep(i,upupu)\
    \         for(ll i = 0, i##_len = (upupu);(i) < (i##_len);(i)++)\n# define reps(i,opopo)\
    \        for(ll i = 1, i##_len = (opopo);(i) <= (i##_len);(i)++)\n# define len(x)\
    \                ((ll)(x).size())\n# define bit(n)               (1LL << (n))\n\
    # define pb push_back\n# define eb emplace_back\n# define exists(c, e)       \
    \  ((c).find(e) != (c).end())\n\nstruct INIT{\n\tINIT(){\n\t\tstd::ios::sync_with_stdio(false);\n\
    \t\tstd::cin.tie(0);\n\t\tcout << fixed << setprecision(20);\n\t}\n}INIT;\n\n\
    namespace mmrz {\n\tvoid solve();\n}\n\nint main(){\n\tmmrz::solve();\n}\n#line\
    \ 2 \"data_structure/area_of_union_of_rectangles.hpp\"\n\n#line 2 \"data_structure/lazy_segment_tree.hpp\"\
    \n\n#line 5 \"data_structure/lazy_segment_tree.hpp\"\n\ntemplate<class S, auto\
    \ op, auto e, class F, auto mapping, auto composition, auto id>\nstruct lazy_segment_tree\
    \ {\nprivate:\n\tint n;\n\tint log;\n\tint size;\n\tstd::vector<S> node;\n\tstd::vector<F>\
    \ lazy;\n\n\tvoid update(int k) { node[k] = op(node[2 * k], node[2 * k + 1]);\
    \ }\n\tvoid all_apply(int k, F f) {\n\t\tnode[k] = mapping(f, node[k]);\n\t\t\
    if(k < size) lazy[k] = composition(f, lazy[k]);\n\t}\n\tvoid push(int k) {\n\t\
    \tall_apply(2*k + 0, lazy[k]);\n\t\tall_apply(2*k + 1, lazy[k]);\n\t\tlazy[k]\
    \ = id();\n\t}\npublic:\n\tlazy_segment_tree() : lazy_segment_tree(0) {}\n\n\t\
    lazy_segment_tree(int _n) : lazy_segment_tree(std::vector<S>(_n, e())) {}\n\n\t\
    lazy_segment_tree(const std::vector<S> &v) : n((int)v.size()) {\n\t\tsize = 1;\n\
    \t\twhile(size < n) size <<= 1;\n\n\t\tlog = __builtin_ctz(size);\n\n\t\tnode.resize(2*size,\
    \ e());\n\t\tlazy.resize(size, id());\n\n\t\tfor(int i = 0;i < n;i++)node[i +\
    \ size] = v[i];\n\t\tfor(int i = size-1;i >= 1;i--)node[i] = op(node[2*i + 0],\
    \ node[2*i + 1]);\n\t}\n\n\tvoid set(int x, S val) {\n\t\tassert(0 <= x && x <\
    \ n);\n\t\tx += size;\n\n\t\tfor(int i = log;i >= 1;i--)push(x >> i);\n\t\tnode[x]\
    \ = val;\n\t\tfor(int i = 1;i <= log;i++)update(x >> i);\n\t}\n\n\tS operator[](int\
    \ x) {\n\t\tassert(0 <= x && x < n);\n\t\tx += size;\n\n\t\tfor(int i = log;i\
    \ >= 1;i--)push(x >> i);\n\t\treturn node[x];\n\t}\n\n\tS fold(int l, int r) {\n\
    \t\tassert(0 <= l && l <= r && r <= n);\n\t\tif(l == r)return e();\n\n\t\tl +=\
    \ size;\n\t\tr += size;\n\n\t\tfor(int i = log;i >= 1;i--) {\n\t\t\tif(((l >>\
    \ i) << i) != l)push(l >> i);\n\t\t\tif(((r >> i) << i) != r)push((r-1) >> i);\n\
    \t\t}\n\n\t\tS L = e(), R = e();\n\t\tfor(;l < r;l >>= 1, r >>= 1){\n\t\t\tif(l&1)L\
    \ = op(L, node[l++]);\n\t\t\tif(r&1)R = op(node[--r], R);\n\t\t}\n\t\treturn op(L,\
    \ R);\n\t}\n\n\tS all_fold() { return node[1]; };\n\n\tvoid apply(int x, F f)\
    \ {\n\t\tassert(0 <= x && x < n);\n\n\t\tx += size;\n\t\tfor(int i = log;i >=\
    \ 1;i--)push(x >> i);\n\t\tnode[x] = mapping(f, node[x]);\n\t\tfor(int i = 1;i\
    \ <= log;i++)update(x >> i);\n\t}\n\n\tvoid apply(int l, int r, F f) {\n\t\tassert(0\
    \ <= l && l <= r && r <= n);\n\t\tif(l == r)return;\n\n\t\tl += size;\n\t\tr +=\
    \ size;\n\n\t\tfor(int i = log;i >= 1;i--) {\n\t\t\tif(((l >> i) << i) != l)push(l\
    \ >> i);\n\t\t\tif(((r >> i) << i) != r)push((r-1) >> i);\n\t\t}\n\n\t\t{\n\t\t\
    \tint l2 = l, r2 = r;\n\t\t\twhile (l < r) {\n\t\t\t\tif (l & 1) all_apply(l++,\
    \ f);\n\t\t\t\tif (r & 1) all_apply(--r, f);\n\t\t\t\tl >>= 1;\n\t\t\t\tr >>=\
    \ 1;\n\t\t\t}\n\t\t\tl = l2;\n\t\t\tr = r2;\n\t\t}\n\n\t\tfor (int i = 1; i <=\
    \ log; i++) {\n\t\t\tif (((l >> i) << i) != l) update(l >> i);\n\t\t\tif (((r\
    \ >> i) << i) != r) update((r - 1) >> i);\n\t\t}\n\t}\n\n\ttemplate<bool (*g)(S)>\
    \ int max_right(int l) {\n\t\treturn max_right(l, [](S x){ return g(x); });\n\t\
    }\n\ttemplate<class G> int max_right(int l, G g) {\n\t\tassert(0 <= l && l <=\
    \ n);\n\t\tassert(g(e()));\n\n\t\tif(l == n)return n;\n\n\t\tl += size;\n\t\t\
    for(int i = log;i >= 1;i--)push(l >> i);\n\n\t\tS sum = e();\n\t\tdo {\n\t\t\t\
    while(l%2 == 0)l >>= 1;\n\t\t\tif(not g(op(sum, node[l]))) {\n\t\t\t\twhile(l\
    \ < size) {\n\t\t\t\t\tpush(l);\n\t\t\t\t\tl <<= 1;\n\t\t\t\t\tif(g(op(sum, node[l])))\
    \ {\n\t\t\t\t\t\tsum = op(sum, node[l]);\n\t\t\t\t\t\tl++;\n\t\t\t\t\t}\n\t\t\t\
    \t}\n\t\t\t\treturn l-size;\n\t\t\t}\n\t\t\tsum = op(sum, node[l]);\n\t\t\tl++;\n\
    \t\t}while((l&-l) != l);\n\t\treturn n;\n\t}\n\n\ttemplate <bool (*g)(S)> int\
    \ min_left(int r) {\n\t\treturn min_left(r, [](S x) { return g(x); });\n\t}\n\t\
    template<class G> int min_left(int r, G g) {\n\t\tassert(0 <= r && r <= n);\n\t\
    \tassert(g(e()));\n\n\t\tif(r == 0)return 0;\n\n\t\tr += size;\n\t\tfor(int i\
    \ = log;i >= 1;i--)push((r-1) >> i);\n\n\t\tS sum = e();\n\t\tdo {\n\t\t\tr--;\n\
    \t\t\twhile(r > 1 && (r%2))r >>= 1;\n\t\t\tif(not g(op(node[r], sum))) {\n\t\t\
    \t\twhile(r < size) {\n\t\t\t\t\tpush(r);\n\t\t\t\t\tr = r*2 + 1;\n\t\t\t\t\t\
    if(g(op(node[r], sum))) {\n\t\t\t\t\t\tsum = op(node[r], sum);\n\t\t\t\t\t\tr--;\n\
    \t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\treturn r+1-size;\n\t\t\t}\n\t\t\tsum = op(node[r],\
    \ sum);\n\t\t}while((r&-r) != r);\n\t\treturn 0;\n\t}\n};\n#line 4 \"data_structure/area_of_union_of_rectangles.hpp\"\
    \n\n#line 11 \"data_structure/area_of_union_of_rectangles.hpp\"\n\ntemplate<class\
    \ T>\nstruct area_of_union_rectangles {\nprivate:\n\tstd::vector<T> ys;\n\tstd::vector<std::tuple<T,\
    \ int, int>> xs;\n\tstd::vector<std::tuple<T, T, T, T>> rectangles;\n\tusing S\
    \ = std::pair<int, T>;\n\tusing F = int;\n\tstatic S op(S a, S b){\n\t\tif(a.first\
    \ < b.first)return a;\n\t\tif(a.first > b.first)return b;\n\t\treturn std::make_pair(a.first,\
    \ a.second+b.second);\n\t}\n\tstatic S e(){ return std::make_pair(std::numeric_limits<int>::max()/2,\
    \ 0); }\n\tstatic S mapping(F f, S x){ return std::make_pair(x.first+f, x.second);\
    \ }\n\tstatic F composition(F f, F g){ return f+g; }\n\tstatic F id(){ return\
    \ 0; }\npublic:\n\n\t// l, d, r, u\n\tarea_of_union_rectangles(std::vector<std::tuple<T,\
    \ T, T, T>> _rectangles) : rectangles(_rectangles) {\n\t\tys.reserve(rectangles.size()+rectangles.size());\n\
    \t\txs.reserve(rectangles.size()+rectangles.size());\n\n\t\tfor(size_t i = 0;i\
    \ < rectangles.size();i++){\n\t\t\tauto &[l, d, r, u] = rectangles[i];\n\t\t\t\
    ys.emplace_back(d);\n\t\t\tys.emplace_back(u);\n\t\t\txs.emplace_back(l, i, 1);\n\
    \t\t\txs.emplace_back(r, i, -1);\n\t\t}\n\n\t\tstd::sort(ys.begin(), ys.end());\n\
    \t\tys.erase(unique(ys.begin(), ys.end()), ys.end());\n\t\tstd::sort(xs.begin(),\
    \ xs.end());\n\n\t\tstd::map<T, int> y_compress;\n\t\tfor(size_t i = 0;i < ys.size();i++){\n\
    \t\t\ty_compress[ys[i]] = i;\n\t\t}\n\t\tfor(size_t i = 0;i < rectangles.size();i++){\n\
    \t\t\tauto &[l, d, r, u] = rectangles[i];\n\t\t\tu = y_compress[u];\n\t\t\td =\
    \ y_compress[d];\n\t\t}\n\t};\n\n\ttemplate<typename U>\n\tU solve(){\n\t\tstd::vector<S>\
    \ vs((int)ys.size()-1);\n\t\tfor(size_t i = 0;i+1 < ys.size();i++){\n\t\t\tvs[i]\
    \ = std::make_pair(0, ys[i+1]-ys[i]);\n\t\t}\n\t\tlazy_segment_tree<S, op, e,\
    \ F, mapping, composition, id> seg(vs);\n\t\t\n\t\tU ret = 0;\n\n\t\tT total =\
    \ ys.back() - ys.front();\n\t\tfor(size_t i = 0;i+1 < xs.size();i++){\n\t\t\t\
    auto &[X, idx, delta] = xs[i];\n\t\t\tauto &[l, d, r, u] = rectangles[idx];\n\t\
    \t\tseg.apply(d, u, delta);\n\n\t\t\tauto [mn, cnt] = seg.all_fold();\n\n\t\t\t\
    U dy = total - (mn == 0 ? cnt : 0);\n\t\t\tU dx = std::get<0>(xs[i+1]) - X;\n\n\
    \t\t\tret += dy*dx;\n\t\t}\n\n\t\treturn ret;\n\t}\n};\n#line 5 \"verify/yosupo/area_of_union_of_rectangles.test.cpp\"\
    \n\nvoid mmrz::solve(){\n\tint n;\n\tcin >> n;\n\tvector<tuple<int, int, int,\
    \ int>> rectangles(n);\n\tfor(auto &[l, d, r, u] : rectangles)cin >> l >> d >>\
    \ r >> u;\n\n\tcout << area_of_union_rectangles<int>(rectangles).solve<ll>() <<\
    \ '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/area_of_union_of_rectangles\"\
    \n\n#include \"./../../template/template.hpp\"\n#include \"./../../data_structure/area_of_union_of_rectangles.hpp\"\
    \n\nvoid mmrz::solve(){\n\tint n;\n\tcin >> n;\n\tvector<tuple<int, int, int,\
    \ int>> rectangles(n);\n\tfor(auto &[l, d, r, u] : rectangles)cin >> l >> d >>\
    \ r >> u;\n\n\tcout << area_of_union_rectangles<int>(rectangles).solve<ll>() <<\
    \ '\\n';\n}\n"
  dependsOn:
  - template/template.hpp
  - data_structure/area_of_union_of_rectangles.hpp
  - data_structure/lazy_segment_tree.hpp
  isVerificationFile: true
  path: verify/yosupo/area_of_union_of_rectangles.test.cpp
  requiredBy: []
  timestamp: '2025-07-01 03:22:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/area_of_union_of_rectangles.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/area_of_union_of_rectangles.test.cpp
- /verify/verify/yosupo/area_of_union_of_rectangles.test.cpp.html
title: verify/yosupo/area_of_union_of_rectangles.test.cpp
---

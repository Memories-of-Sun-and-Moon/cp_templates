---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree_0-indexed.hpp
    title: "0-indexed\u306E\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"verify/aoj/dsl/2_B___segment_tree_0-indexed.test.cpp\"\n\
    # define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#line 1 \"template/template.hpp\"\n# include <bits/stdc++.h>\nusing namespace\
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
    # define pb push_back\n# define exists(c, e)         ((c).find(e) != (c).end())\n\
    \nstruct INIT{\n\tINIT(){\n\t\tstd::ios::sync_with_stdio(false);\n\t\tstd::cin.tie(0);\n\
    \t\tcout << fixed << setprecision(20);\n\t}\n}INIT;\n\nnamespace mmrz {\n\tvoid\
    \ solve();\n}\n\nint main(){\n\tmmrz::solve();\n}\n#line 1 \"data_structure/segment_tree_0-indexed.hpp\"\
    \n\ntemplate<typename T>struct [[deprecated(\"use 1-indexed segment tree (segment_tree.hpp)\"\
    )]] segment_tree {\n\tusing F = function<T(T, T)>;\n\n\tint n;\n\tvector<T> node;\n\
    \tF combine;\n\tT identify;\n\n\tsegment_tree(vector<T> v, F _combine, T _identity)\
    \ : combine(_combine), identify(_identity) {\n\t\tint sz = (int)v.size();\n\t\t\
    n = 1;\n\t\twhile(n < sz)n *= 2;\n\t\tnode.resize(2 * n - 1, identify);\n\n\t\t\
    for(int i = 0;i < sz;i++)node[i + n - 1] = v[i];\n\t\tfor(int i = n - 2;i >= 0;i--)node[i]\
    \ = combine(node[2 * i + 1], node[2 * i + 2]);\n\t}\n\n\tsegment_tree(int _n,\
    \ F _combine, T _identify) : combine(_combine), identify(_identify){\n\t\tint\
    \ sz = _n;\n\t\tn = 1;\n\t\twhile(n < sz)n *= 2;\n\t\tnode.resize(2 * n - 1, identify);\n\
    \t}\n\n\tT operator[](int x) {return node[x + n - 1]; }\n\n\tvoid set(int x, T\
    \ val){\n\t\tx += (n - 1);\n\n\t\tnode[x] = val;\n\t\twhile(x > 0){\n\t\t\tx =\
    \ (x - 1) / 2;\n\t\t\tnode[x] = combine(node[2 * x + 1], node[2 * x + 2]);\n\t\
    \t}\n\t}\n\n\tT fold(int a, int b, int k = 0, int l = 0, int r = -1){\n\t\tif(r\
    \ < 0) r = n;\n\n\t\tif(r <= a || b <= l)return identify;\n\t\t\n\t\tif(a <= l\
    \ && r <= b)return node[k];\n\n\t\tT vl = fold(a, b, 2 * k + 1, l, (l + r) / 2);\n\
    \t\tT vr = fold(a, b, 2 * k + 2, (l + r) / 2, r);\n\t\treturn combine(vl, vr);\n\
    \t}\n};\n#line 5 \"verify/aoj/dsl/2_B___segment_tree_0-indexed.test.cpp\"\n\n\
    void mmrz::solve(){\n\tint n, q;\n\tcin >> n >> q;\n\tauto combine = [](ll a,\
    \ ll b){return a+b; };\n\tsegment_tree<ll> seg(n, combine, 0);\n\twhile(q--){\n\
    \t\tint com, x, y;\n\t\tcin >> com >> x >> y;\n\t\tx--;\n\t\tif(com)cout << seg.fold(x,\
    \ y) << endl;\n\t\telse seg.set(x, seg[x]+y);\n\t}\n}\n"
  code: "# define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include \"./../../../template/template.hpp\"\n#include \"./../../../data_structure/segment_tree_0-indexed.hpp\"\
    \n\nvoid mmrz::solve(){\n\tint n, q;\n\tcin >> n >> q;\n\tauto combine = [](ll\
    \ a, ll b){return a+b; };\n\tsegment_tree<ll> seg(n, combine, 0);\n\twhile(q--){\n\
    \t\tint com, x, y;\n\t\tcin >> com >> x >> y;\n\t\tx--;\n\t\tif(com)cout << seg.fold(x,\
    \ y) << endl;\n\t\telse seg.set(x, seg[x]+y);\n\t}\n}\n"
  dependsOn:
  - template/template.hpp
  - data_structure/segment_tree_0-indexed.hpp
  isVerificationFile: true
  path: verify/aoj/dsl/2_B___segment_tree_0-indexed.test.cpp
  requiredBy: []
  timestamp: '2024-07-07 01:02:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/dsl/2_B___segment_tree_0-indexed.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/dsl/2_B___segment_tree_0-indexed.test.cpp
- /verify/verify/aoj/dsl/2_B___segment_tree_0-indexed.test.cpp.html
title: verify/aoj/dsl/2_B___segment_tree_0-indexed.test.cpp
---

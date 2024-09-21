---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
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
  bundledCode: "#line 1 \"verify/aoj/dsl/2_B___segment_tree.test.cpp\"\n# define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\n\n#line\
    \ 1 \"template/template.hpp\"\n# include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing ull = unsigned long long;\nconst double pi = acos(-1);\n\
    template<class T>constexpr T inf() { return ::std::numeric_limits<T>::max(); }\n\
    template<class T>constexpr T hinf() { return inf<T>() / 2; }\ntemplate <typename\
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
    \ solve();\n}\n\nint main(){\n\tmmrz::solve();\n}\n#line 1 \"data_structure/segment_tree.hpp\"\
    \n\ntemplate<typename T>struct segment_tree {\n\tusing F = function<T(T, T)>;\n\
    \n\tint offset;\n\tint n;\n\tvector<T> node;\n\tF combine;\n\tT identify;\n\n\t\
    segment_tree(int _n, F _combine, T _identify) : segment_tree(vector<T>(_n, _identify),\
    \ _combine, _identify) {}\n\n\tsegment_tree(vector<T> v, F _combine, T _identify)\
    \ : combine(_combine), identify(_identify) {\n\t\tn = (int)v.size();\n\t\toffset\
    \ = 1;\n\t\twhile(offset < n)offset <<= 1;\n\n\t\tnode.resize(2*offset, identify);\n\
    \n\t\tfor(int i = 0;i < n;i++)node[i + offset] = v[i];\n\t\tfor(int i = offset\
    \ - 1;i >= 1;i--)node[i] = combine(node[2 * i + 0], node[2 * i + 1]);\n\t}\n\n\
    \tT operator[](int x) {return node[x + offset]; }\n\n\tvoid set(int x, T val){\n\
    \t\tx += offset;\n\n\t\tnode[x] = val;\n\t\twhile(x >>= 1){;\n\t\t\tnode[x] =\
    \ combine(node[2 * x + 0], node[2 * x + 1]);\n\t\t}\n\t}\n\n\tT fold(int a, int\
    \ b){\n\t\tT L = identify, R = identify;\n\t\tfor(a += offset, b += offset; a\
    \ < b;a >>= 1, b >>= 1){\n\t\t\tif(a&1)L = combine(L, node[a++]);\n\t\t\tif(b&1)R\
    \ = combine(node[--b], R);\n\t\t}\n\t\treturn combine(L, R);\n\t}\n\n\tint max_right(const\
    \ function<bool(T)> f, int l = 0){\n\t\tif(l == n)return n;\n\t\tl += offset;\n\
    \t\tT sum = identify;\n\t\tdo{\n\t\t\twhile(l%2 == 0)l >>= 1;\n\t\t\tif(not f(combine(sum,\
    \ node[l]))){\n\t\t\t\twhile(l < offset){\n\t\t\t\t\tl <<= 1;\n\t\t\t\t\tif(f(combine(sum,\
    \ node[l]))){\n\t\t\t\t\t\tsum = combine(sum, node[l]);\n\t\t\t\t\t\t++l;\n\t\t\
    \t\t\t}\n\t\t\t\t}\n\t\t\t\treturn l - offset;\n\t\t\t}\n\t\t\tsum = combine(sum,\
    \ node[l]);\n\t\t\t++l;\n\t\t}while((l&-l) != l);\n\t\treturn n;\n\t}\n\n\tint\
    \ min_left(const function<bool(T)> f, int r = -1){\n\t\tif(r == 0)return 0;\n\t\
    \tif(r == -1)r = n;\n\t\tr += offset;\n\t\tT sum = identify;\n\t\tdo{\n\t\t\t\
    --r;\n\t\t\twhile(r > 1 && (r % 2))r >>= 1;\n\t\t\tif(not f(combine(node[r], sum))){\n\
    \t\t\t\twhile(r < offset){\n\t\t\t\t\tr = r*2 + 1;\n\t\t\t\t\tif(f(combine(node[r],\
    \ sum))){\n\t\t\t\t\t\tsum = combine(node[r], sum);\n\t\t\t\t\t\t--r;\n\t\t\t\t\
    \t}\n\t\t\t\t}\n\t\t\t\treturn r+1 - offset;\n\t\t\t}\n\t\t\tsum = combine(node[r],\
    \ sum);\n\t\t}while((r&-r) != r);\n\t\treturn 0;\n\t}\n};\n#line 5 \"verify/aoj/dsl/2_B___segment_tree.test.cpp\"\
    \n\nvoid mmrz::solve(){\n\tint n, q;\n\tcin >> n >> q;\n\tauto combine = [](ll\
    \ a, ll b){return a+b; };\n\tsegment_tree<ll> seg(n, combine, 0);\n\twhile(q--){\n\
    \t\tint com, x, y;\n\t\tcin >> com >> x >> y;\n\t\tx--;\n\t\tif(com)cout << seg.fold(x,\
    \ y) << endl;\n\t\telse seg.set(x, seg[x]+y);\n\t}\n}\n"
  code: "# define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include \"./../../../template/template.hpp\"\n#include \"./../../../data_structure/segment_tree.hpp\"\
    \n\nvoid mmrz::solve(){\n\tint n, q;\n\tcin >> n >> q;\n\tauto combine = [](ll\
    \ a, ll b){return a+b; };\n\tsegment_tree<ll> seg(n, combine, 0);\n\twhile(q--){\n\
    \t\tint com, x, y;\n\t\tcin >> com >> x >> y;\n\t\tx--;\n\t\tif(com)cout << seg.fold(x,\
    \ y) << endl;\n\t\telse seg.set(x, seg[x]+y);\n\t}\n}\n"
  dependsOn:
  - template/template.hpp
  - data_structure/segment_tree.hpp
  isVerificationFile: true
  path: verify/aoj/dsl/2_B___segment_tree.test.cpp
  requiredBy: []
  timestamp: '2024-09-21 12:51:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/dsl/2_B___segment_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/dsl/2_B___segment_tree.test.cpp
- /verify/verify/aoj/dsl/2_B___segment_tree.test.cpp.html
title: verify/aoj/dsl/2_B___segment_tree.test.cpp
---

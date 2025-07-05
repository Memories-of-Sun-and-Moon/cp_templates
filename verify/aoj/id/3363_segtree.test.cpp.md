---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree_2d.hpp
    title: "2D\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3363
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3363
  bundledCode: "#line 1 \"verify/aoj/id/3363_segtree.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3363\"\n\n#line 1 \"\
    template/template.hpp\"\n# include <bits/stdc++.h>\nusing namespace std;\nusing\
    \ ll = long long;\nusing ull = unsigned long long;\nconst double pi = acos(-1);\n\
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
    # define pb push_back\n# define eb emplace_back\n# define exists(c, e)       \
    \  ((c).find(e) != (c).end())\n\nstruct INIT{\n\tINIT(){\n\t\tstd::ios::sync_with_stdio(false);\n\
    \t\tstd::cin.tie(0);\n\t\tcout << fixed << setprecision(20);\n\t}\n}INIT;\n\n\
    namespace mmrz {\n\tvoid solve();\n}\n\nint main(){\n\tmmrz::solve();\n}\n#line\
    \ 2 \"data_structure/segment_tree_2d.hpp\"\n\n#line 5 \"data_structure/segment_tree_2d.hpp\"\
    \n\ntemplate<typename T>struct segment_tree_2d {\n\tusing F = std::function<T(T,\
    \ T)>;\n\tint id(int r, int c) const {return r*2*w+c; }\n\n\tint h, w;\n\tstd::vector<T>\
    \ node;\n\tF combine;\n\tT identify;\n\n\tsegment_tree_2d(int _h, int _w, F _combine,\
    \ T _identify) : combine(_combine), identify(_identify){\n\t\th = w = 1;\n\t\t\
    while(h < _h) h <<= 1;\n\t\twhile(w < _w) w <<= 1;\n\t\tnode.assign(4*h*w, identify);\n\
    \t}\n\n\tsegment_tree_2d(std::vector<std::vector<T>> &v, F _combine, T _identify)\
    \ : combine(_combine), identify(_identify){\n\t\th = w = 1;\n\t\twhile(h < (int)v.size())\
    \ h <<= 1;\n\t\twhile(w < (int)v[0].size()) w <<= 1;\n\t\tnode.assign(4*h*w, identify);\n\
    \t\tfor(int i = 0;i < (int)v.size(); i++){\n\t\t\tfor(int j = 0;j < (int)v[0].size();j++){\n\
    \t\t\t\tnode[id(i+h-1, j+w-1)] = v[i][j];\n\t\t\t}\n\t\t}\n\t\tfor(int i = 2*h-2;\
    \ i > h-2;i--){\n\t\t\tfor(int j = w-2; j >= 0;j--){\n\t\t\t\tnode[id(i, j)] =\
    \ combine(node[id(i, 2*j+1)], node[id(i, 2*j+2)]);\n\t\t\t}\n\t\t}\n\t\tfor(int\
    \ i = h-2;i >= 0;i--){\n\t\t\tfor(int j = 0;j < 2*w-1;j++){\n\t\t\t\tnode[id(i,\
    \ j)] = combine(node[id(2*i+1, j)], node[id(2*i+2, j)]);\n\t\t\t}\n\t\t}\n\t}\n\
    \n\tvoid set(int y, int x, T val){\n\t\ty += h-1;\n\t\tx += w-1;\n\t\tnode[id(y,\
    \ x)] = val;\n\n\t\tfor(int j = (x+1)/2-1;j >= 0;j = (j+1)/2-1){\n\t\t\tnode[id(y,\
    \ j)] = combine(node[id(y, 2*j+1)], node[id(y, 2*j+2)]);\n\t\t}\n\n\t\tfor(int\
    \ i = (y+1)/2-1;i >= 0;i = (i+1)/2-1){\n\t\t\tfor(int j = x;j >= 0;j = (j+1)/2-1){\n\
    \t\t\t\tnode[id(i, j)] = combine(node[id(2*i+1, j)], node[id(2*i+2, j)]);\n\t\t\
    \t}\n\t\t}\n\t}\n\n\tT get(int y, int x){\n\t\treturn node[id(y+h-1, x+w-1)];\n\
    \t}\n\n\tT fold(int li, int lj, int ri, int rj){\n\t\treturn fold_h(li, lj, ri,\
    \ rj);\n\t}\n\n\tT fold_h(int li, int lj, int ri, int rj, int k=0, int si=0, int\
    \ ti=-1){\n\t\tif(ti<0)ti = h;\n\n\t\tif(ri <= si || ti <= li)return identify;\n\
    \t\tif(li <= si && ti <= ri)return fold_w(lj, rj, k);\n\t\tT vs = fold_h(li, lj,\
    \ ri, rj, 2*k+1, si, (si+ti)/2);\n\t\tT vt = fold_h(li, lj, ri, rj, 2*k+2, (si+ti)/2,\
    \ ti);\n\t\treturn combine(vs, vt);\n\t}\n\n\tT fold_w(int lj, int rj, int i,\
    \ int k=0, int sj=0, int tj=-1){\n\t\tif(tj<0) tj = w;\n\n\t\tif(rj <= sj || tj\
    \ <= lj)return identify;\n\t\tif(lj <= sj && tj <= rj)return node[id(i, k)];\n\
    \t\tT vs = fold_w(lj, rj, i, 2*k+1, sj, (sj+tj)/2);\n\t\tT vt = fold_w(lj, rj,\
    \ i, 2*k+2, (sj+tj)/2, tj);\n\t\treturn combine(vs, vt);\n\t}\n};\n\n#line 5 \"\
    verify/aoj/id/3363_segtree.test.cpp\"\n\n// TLE SOLUTION\n\nbool SOLVE(){\n\t\
    int h, w;\n\tcin >> h >> w;\n\tif(h == 0 && w == 0)return 1;\n\tvector<vector<int>>\
    \ f(h, vector<int>(w));\n\trep(i, h)rep(j, w)cin >> f[i][j];\n\tsegment_tree_2d<int>\
    \ seg(h+w, h+w, [](int l, int r){return max(l, r);}, 0);\n\trep(i, h)rep(j, w){\n\
    \t\tint R = w + (i-j), C = (i+j);\n\t\tseg.set(R, C, f[i][j]);\n\t}\n\tvector<int>\
    \ ans(h+w-1);\n\trep(i, h)rep(j, w){\n\t\tint R = w + (i-j), C = (i+j);\n\t\t\
    int ok = 0, ng = h+w-1;\n\t\twhile(ng-ok > 1){\n\t\t\tint mid = (ok+ng)/2;\n\t\
    \t\t(seg.fold(max(R-mid, 0), max(C-mid, 0), min(R+mid+1, h+w),  min(C+mid+1, h+w))\
    \ <= f[i][j] ? ok : ng) = mid;\n\t\t}\n\t\tans[ok]++;\n\t}\n\tfor(int i = h+w-3;i\
    \ >= 1;i--){\n\t\tans[i] += ans[i+1];\n\t}\n\treps(i, h+w-2){\n\t\tcout << ans[i]\
    \ << \" \\n\"[i == h+w-2];\n\t}\n\treturn 0;\n}\n\nvoid mmrz::solve(){\n\twhile(!SOLVE());\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3363\"\
    \n\n#include \"./../../../template/template.hpp\"\n#include \"./../../../data_structure/segment_tree_2d.hpp\"\
    \n\n// TLE SOLUTION\n\nbool SOLVE(){\n\tint h, w;\n\tcin >> h >> w;\n\tif(h ==\
    \ 0 && w == 0)return 1;\n\tvector<vector<int>> f(h, vector<int>(w));\n\trep(i,\
    \ h)rep(j, w)cin >> f[i][j];\n\tsegment_tree_2d<int> seg(h+w, h+w, [](int l, int\
    \ r){return max(l, r);}, 0);\n\trep(i, h)rep(j, w){\n\t\tint R = w + (i-j), C\
    \ = (i+j);\n\t\tseg.set(R, C, f[i][j]);\n\t}\n\tvector<int> ans(h+w-1);\n\trep(i,\
    \ h)rep(j, w){\n\t\tint R = w + (i-j), C = (i+j);\n\t\tint ok = 0, ng = h+w-1;\n\
    \t\twhile(ng-ok > 1){\n\t\t\tint mid = (ok+ng)/2;\n\t\t\t(seg.fold(max(R-mid,\
    \ 0), max(C-mid, 0), min(R+mid+1, h+w),  min(C+mid+1, h+w)) <= f[i][j] ? ok :\
    \ ng) = mid;\n\t\t}\n\t\tans[ok]++;\n\t}\n\tfor(int i = h+w-3;i >= 1;i--){\n\t\
    \tans[i] += ans[i+1];\n\t}\n\treps(i, h+w-2){\n\t\tcout << ans[i] << \" \\n\"\
    [i == h+w-2];\n\t}\n\treturn 0;\n}\n\nvoid mmrz::solve(){\n\twhile(!SOLVE());\n\
    }\n"
  dependsOn:
  - template/template.hpp
  - data_structure/segment_tree_2d.hpp
  isVerificationFile: true
  path: verify/aoj/id/3363_segtree.test.cpp
  requiredBy: []
  timestamp: '2025-07-05 16:17:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/id/3363_segtree.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/id/3363_segtree.test.cpp
- /verify/verify/aoj/id/3363_segtree.test.cpp.html
title: verify/aoj/id/3363_segtree.test.cpp
---

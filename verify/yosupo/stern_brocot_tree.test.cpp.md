---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/stern_brocot_tree.hpp
    title: stern_brocot_tree
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
    PROBLEM: https://judge.yosupo.jp/problem/stern_brocot_tree
    links:
    - https://judge.yosupo.jp/problem/stern_brocot_tree
  bundledCode: "#line 1 \"verify/yosupo/stern_brocot_tree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/stern_brocot_tree\"\n\n#line 1 \"template/template.hpp\"\
    \n# include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nconst double pi = acos(-1);\ntemplate<class T>constexpr\
    \ T inf() { return ::std::numeric_limits<T>::max(); }\ntemplate<class T>constexpr\
    \ T hinf() { return inf<T>() / 2; }\ntemplate <typename T_char>T_char TL(T_char\
    \ cX) { return tolower(cX); }\ntemplate <typename T_char>T_char TU(T_char cX)\
    \ { return toupper(cX); }\ntemplate<class T> bool chmin(T& a,T b) { if(a > b){a\
    \ = b; return true;} return false; }\ntemplate<class T> bool chmax(T& a,T b) {\
    \ if(a < b){a = b; return true;} return false; }\nint popcnt(unsigned long long\
    \ n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++; return\
    \ cnt; }\nint d_sum(ll n) { int ret = 0; while (n > 0) { ret += n % 10; n /= 10;\
    \ }return ret; }\nint d_cnt(ll n) { int ret = 0; while (n > 0) { ret++; n /= 10;\
    \ }return ret; }\nll gcd(ll a, ll b) { if (b == 0)return a; return gcd(b, a%b);\
    \ };\nll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g*b; };\nll MOD(ll x,\
    \ ll m){return (x%m+m)%m; }\nll FLOOR(ll x, ll m) {ll r = (x%m+m)%m; return (x-r)/m;\
    \ }\ntemplate<class T> using dijk = priority_queue<T, vector<T>, greater<T>>;\n\
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
    \ 1 \"math/stern_brocot_tree.hpp\"\n\nnamespace sbt{\n\n\ttemplate<class T>\n\t\
    tuple<T, T, T, T> child(T p, T q, T r, T s, T d, bool is_left){\n\t\tif(is_left){\n\
    \t\t\tr += d*p;\n\t\t\ts += d*q;\n\t\t}else{\n\t\t\tp += d*r;\n\t\t\tq += d*s;\n\
    \t\t}\n\t\treturn make_tuple(p, q, r, s);\n\t}\n\n\ttemplate<class T>\n\ttuple<T,\
    \ T, T, T> parent(T p, T q, T r, T s){\n\t\tif(p == 0 && q == 1 && r == 1 && s\
    \ == 0){\n\t\t\treturn make_tuple(0, 0, 0, 0);\n\t\t}\n\t\tif(p < r || q < s){\n\
    \t\t\tr -= p, s -= q;\n\t\t}else{\n\t\t\tp -= r, q -= s;\n\t\t}\n\t\treturn make_tuple(p,\
    \ q, r, s);\n\t}\n\n\ttemplate<class T>\n\tvector<T> encode_path(T p, T q){\n\t\
    \tvector<T> a;\n\t\tif(p < q){\n\t\t\ta.emplace_back(0);\n\t\t\tswap(p, q);\n\t\
    \t}\n\t\twhile(p != 1){\n\t\t\ta.emplace_back(p/q);\n\t\t\tp %= q;\n\t\t\tswap(p,\
    \ q);\n\t\t}\n\t\tif(not a.empty()){\n\t\t\tif(a.back() == 1){\n\t\t\t\ta.pop_back();\n\
    \t\t\t}else{\n\t\t\t\ta.back()--;\n\t\t\t}\n\t\t}\n\t\treturn a;\n\t}\n\n\ttemplate<class\
    \ T>\n\ttuple<T, T, T, T> decode_path(const vector<T> &a){\n\t\tT p = 0, q = 1,\
    \ r = 1, s = 0;\n\t\tfor(int i = 0;i < ssize(a);i++){\n\t\t\ttie(p, q, r, s) =\
    \ child(p, q, r, s, a[i], i&1);\n\t\t}\n\t\treturn make_tuple(p, q, r, s);\n\t\
    }\n\n\ttemplate<class T>\n\ttuple<T, T, T, T> lca(T p, T q, T r, T s){\n\t\tvector<T>\
    \ a = encode_path(p, q), b = encode_path(r, s);\n\n\t\tint n = min(ssize(a), ssize(b));\n\
    \n\t\tT P = 0, Q = 1, R = 1, S = 0;\n\t\tfor(int i = 0;i < n;i++){\n\t\t\tT c\
    \ = min(a[i], b[i]);\n\t\t\ttie(P, Q, R, S) = child(P, Q, R, S, c, i&1);\n\t\t\
    \tif(a[i] != b[i])break;\n\t\t}\n\t\treturn make_tuple(P, Q, R, S);\n\t}\n\n\t\
    template<class T>\n\toptional<tuple<T, T, T, T>> ancestor(T p, T q, T d){\n\t\t\
    vector<T> a = encode_path(p, q);\n\t\tT P = 0, Q = 1, R = 1, S = 0;\n\t\tfor(int\
    \ i = 0;i < ssize(a);i++){\n\t\t\tT c = min(d, a[i]);\n\t\t\ttie(P, Q, R, S) =\
    \ child(P, Q, R, S, c, i&1);\n\t\t\td -= c;\n\t\t\tif(d == 0)break;\n\t\t}\n\t\
    \tif(d == 0){\n\t\t\treturn make_tuple(P, Q, R, S);\n\t\t}\n\t\treturn nullopt;\n\
    \t}\n\n\ttemplate<class T>\n\ttuple<T, T, T, T> range(T p, T q){\n\t\treturn decode_path(encode_path(p,\
    \ q));\n\t}\n}\n#line 5 \"verify/yosupo/stern_brocot_tree.test.cpp\"\n\nusing\
    \ namespace mmrz;\n\nvoid SOLVE(){\n\tstring op;\n\tcin >> op;\n\tif(op == \"\
    ENCODE_PATH\"){\n\t\tll a, b;\n\t\tcin >> a >> b;\n\t\tvector<ll> path = sbt::encode_path(a,\
    \ b);\n\t\tif(path.empty())cout << 0;\n\t\telse if(path.front() == 0)cout << ssize(path)\
    \ - 1;\n\t\telse cout << ssize(path) << \" R \" << path.front();\n\t\t\n\t\tfor(int\
    \ i = 1; i < ssize(path); i++){\n\t\t\tcout << (i % 2 == 0 ? \" R \" : \" L \"\
    ) << path[i];\n\t\t}\n\t\tcout << \"\\n\";\n\t}else if(op == \"DECODE_PATH\"){\n\
    \t\tint k;\n\t\tcin >> k;\n\t\tvector<ll> path;\n\t\trep(i, k){\n\t\t\tchar c;\n\
    \t\t\tll x;\n\t\t\tcin >> c >> x;\n\t\t\tif(i == 0 && c == 'L'){\n\t\t\t\tpath.emplace_back(0);\n\
    \t\t\t}\n\t\t\tpath.emplace_back(x);\n\t\t}\n\t\tauto [p, q, r, s] = sbt::decode_path(path);\n\
    \t\tcout << p+r << ' ' << q+s << '\\n';\n\t}else if(op == \"LCA\"){\n\t\tll a,\
    \ b, c, d;\n\t\tcin >> a >> b >> c >> d;\n\t\tauto [p, q, r, s] = sbt::lca(a,\
    \ b, c, d);\n\t\tcout << p+r << ' ' << q+s << '\\n';\n\t}else if(op == \"ANCESTOR\"\
    ){\n\t\tll k, a, b;\n\t\tcin >> k >> a >> b;\n\t\tauto ret = sbt::ancestor(a,\
    \ b, k);\n\t\tif(!ret){\n\t\t\tcout << \"-1\\n\";\n\t\t}else{\n\t\t\tauto [p,\
    \ q, r, s] = ret.value();\n\t\t\tcout << p+r << ' ' << q+s << '\\n';\n\t\t}\n\t\
    }else{\n\t\tll a, b;\n\t\tcin >> a >> b;\n\t\tauto [p, q, r, s] = sbt::range(a,\
    \ b);\n\t\tcout << p << ' ' << q << ' ' << r << ' ' << s << '\\n';\n\t}\n}\n\n\
    void mmrz::solve(){\n\tint t = 1;\n\tcin >> t;\n\twhile(t--)SOLVE();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/stern_brocot_tree\"\n\n\
    #include \"./../../template/template.hpp\"\n#include \"./../../math/stern_brocot_tree.hpp\"\
    \n\nusing namespace mmrz;\n\nvoid SOLVE(){\n\tstring op;\n\tcin >> op;\n\tif(op\
    \ == \"ENCODE_PATH\"){\n\t\tll a, b;\n\t\tcin >> a >> b;\n\t\tvector<ll> path\
    \ = sbt::encode_path(a, b);\n\t\tif(path.empty())cout << 0;\n\t\telse if(path.front()\
    \ == 0)cout << ssize(path) - 1;\n\t\telse cout << ssize(path) << \" R \" << path.front();\n\
    \t\t\n\t\tfor(int i = 1; i < ssize(path); i++){\n\t\t\tcout << (i % 2 == 0 ? \"\
    \ R \" : \" L \") << path[i];\n\t\t}\n\t\tcout << \"\\n\";\n\t}else if(op == \"\
    DECODE_PATH\"){\n\t\tint k;\n\t\tcin >> k;\n\t\tvector<ll> path;\n\t\trep(i, k){\n\
    \t\t\tchar c;\n\t\t\tll x;\n\t\t\tcin >> c >> x;\n\t\t\tif(i == 0 && c == 'L'){\n\
    \t\t\t\tpath.emplace_back(0);\n\t\t\t}\n\t\t\tpath.emplace_back(x);\n\t\t}\n\t\
    \tauto [p, q, r, s] = sbt::decode_path(path);\n\t\tcout << p+r << ' ' << q+s <<\
    \ '\\n';\n\t}else if(op == \"LCA\"){\n\t\tll a, b, c, d;\n\t\tcin >> a >> b >>\
    \ c >> d;\n\t\tauto [p, q, r, s] = sbt::lca(a, b, c, d);\n\t\tcout << p+r << '\
    \ ' << q+s << '\\n';\n\t}else if(op == \"ANCESTOR\"){\n\t\tll k, a, b;\n\t\tcin\
    \ >> k >> a >> b;\n\t\tauto ret = sbt::ancestor(a, b, k);\n\t\tif(!ret){\n\t\t\
    \tcout << \"-1\\n\";\n\t\t}else{\n\t\t\tauto [p, q, r, s] = ret.value();\n\t\t\
    \tcout << p+r << ' ' << q+s << '\\n';\n\t\t}\n\t}else{\n\t\tll a, b;\n\t\tcin\
    \ >> a >> b;\n\t\tauto [p, q, r, s] = sbt::range(a, b);\n\t\tcout << p << ' '\
    \ << q << ' ' << r << ' ' << s << '\\n';\n\t}\n}\n\nvoid mmrz::solve(){\n\tint\
    \ t = 1;\n\tcin >> t;\n\twhile(t--)SOLVE();\n}\n"
  dependsOn:
  - template/template.hpp
  - math/stern_brocot_tree.hpp
  isVerificationFile: true
  path: verify/yosupo/stern_brocot_tree.test.cpp
  requiredBy: []
  timestamp: '2025-06-03 05:42:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/stern_brocot_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/stern_brocot_tree.test.cpp
- /verify/verify/yosupo/stern_brocot_tree.test.cpp.html
title: verify/yosupo/stern_brocot_tree.test.cpp
---

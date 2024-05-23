---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geomet.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing LL = long long;\nusing ULL = unsigned long long;\nconst double PI\
    \ = acos(-1);\ntemplate<class T>constexpr T INF() { return ::std::numeric_limits<T>::max();\
    \ }\ntemplate<class T>constexpr T HINF() { return INF<T>() / 2; }\ntemplate <typename\
    \ T_char>T_char TL(T_char cX) { return tolower(cX); };\ntemplate <typename T_char>T_char\
    \ TU(T_char cX) { return toupper(cX); };\ntemplate<class T> bool chmin(T& a,T\
    \ b) { if(a > b){a = b; return true;} return false; }\ntemplate<class T> bool\
    \ chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }\nint popcnt(unsigned\
    \ long long n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++;\
    \ return cnt; }\nint d_sum(LL n) { int ret = 0; while (n > 0) { ret += n % 10;\
    \ n /= 10; }return ret; }\nint d_cnt(LL n) { int ret = 0; while (n > 0) { ret++;\
    \ n /= 10; }return ret; }\nLL gcd(LL a, LL b) { if (b == 0)return a; return gcd(b,\
    \ a%b); };\nLL lcm(LL a, LL b) { LL g = gcd(a, b); return a / g*b; };\n# define\
    \ ALL(qpqpq)           (qpqpq).begin(),(qpqpq).end()\n# define UNIQUE(wpwpw) \
    \       sort(ALL((wpwpw)));(wpwpw).erase(unique(ALL((wpwpw))),(wpwpw).end())\n\
    # define LOWER(epepe)         transform(ALL((epepe)),(epepe).begin(),TL<char>)\n\
    # define UPPER(rprpr)         transform(ALL((rprpr)),(rprpr).begin(),TU<char>)\n\
    # define FOR(i,tptpt,ypypy)   for(LL i=(tptpt);i<(ypypy);i++)\n# define REP(i,upupu)\
    \         FOR(i,0,upupu)\n\nstruct INIT{\n    INIT(){\n        std::ios::sync_with_stdio(false);\n\
    \        std::cin.tie(0);\n        cout << fixed << setprecision(20);\n    }\n\
    }INIT;\n\n# define EPS 10e-9\n\n//a > 0\u306A\u3089\u3070+1, a == 0\u306A\u3089\
    \u30700, a < 0\u306A\u3089\u3070-1\u3000\u3092\u8FD4\u3059\u3002\u3000\u57FA\u672C\
    \u7684\u306BEPS\u8FBC\u307F\u306E\u8A55\u4FA1\u306F\u3053\u308C\u3067\u884C\u3046\
    \u3002\n//\u4E0D\u7B49\u5F0F\u306F\u3001\u52A0\u6E1B\u7B97\u306B\u76F4\u3057\u3066\
    \u3053\u308C\u306B\u9069\u7528\u3059\u308B\u3002\nint sgn(const double a) {\n\
    \    return (a < -EPS ? -1 : (a > EPS ? +1 : 0));\n}\n\n// sqrt\u306B\u8CA0\u6570\
    \u304C\u5165\u3089\u306A\u3044\u3088\u3046\u306B\u3059\u308B\n\n//\u3068\u308A\
    \u3042\u3048\u305A\u771F\u4F3C\u308B\n\n//\u70B9\nstruct Point {\n    double x,\
    \ y;\n\n    Point(double _x = 0.0, double _y = 0.0): x(_x), y(_y) {}\n\n    Point\
    \ operator - () const{return Point(-x, -y);};\n\n    Point operator + (const Point\
    \ &p) const{return Point(x + p.x, y + p.y);}\n    Point operator - (const Point\
    \ &p) const{return Point(x - p.x, y - p.y);}\n    Point operator * (double k)\
    \ const{return Point(x * k, y * k);}\n    Point operator / (double k) const{return\
    \ Point(x / k, y / k);}\n\n    double norm(){return x * x + y * y;}\n    double\
    \ abs(){return sqrt(max(0.0, norm()));};\n};\nistream& operator >> (istream &is,\
    \ Point &p){return is >> p.x >> p.y;}\nostream& operator << (ostream &os, const\
    \ Point &p){return os << p.x << \" \" << p.y;}\n\n\n//\u30D9\u30AF\u30C8\u30EB\
    \ntypedef Point Vector;\n\n//\u5185\u7A4D\ndouble dot(Vector a, Vector b){\n \
    \   return a.x * b.x + a.y * b.y;\n}\n\n//\u5916\u7A4D\ndouble cross(Vector a,\
    \ Vector b){\n    return a.x * b.y - a.y * b.x;\n}\n\n//\u7DDA\u5206\nstruct Segment{\n\
    \    Point p1, p2;\n    Segment(Point _p1 = Point(), Point _p2 = Point()) : p1(_p1),\
    \ p2(_p2) {}\n};\nistream& operator >> (istream &is, Segment &s){return is >>\
    \ s.p1 >> s.p2;}\nostream& operator << (ostream &os, const Segment &s){return\
    \ os << s.p1 << \" \" << s.p2;}\n\n//\u76F4\u7DDA\u2190\u7DDA\u5206\u3068\u533A\
    \u5225\ntypedef Segment Line;\n\n//\u5186\nstruct Circle{\n    Point c;\n    double\
    \ r;\n    Circle(Point _c = Point(), double _r = 0.0): c(_c), r(_r) {}\n};\n\n\
    //\u591A\u89D2\u5F62\ntypedef vector<Point> Polygon;\n\n//\u76F4\u4EA4\u5224\u5B9A\
    \nbool isOrthogonal(Vector a, Vector b){\n    return sgn(dot(a, b)) == 0;\n}\n\
    bool isOrthogonal(Segment s1, Segment s2){\n    return sgn(dot(s1.p2 - s1.p1,\
    \ s2.p2 - s2.p1)) == 0;\n}\n\n//\u4E26\u884C\u5224\u5B9A\nbool isParallel(Vector\
    \ a, Vector b){\n    return sgn(cross(a, b)) == 0;\n}\nbool isParallel(Segment\
    \ s1, Segment s2){\n    return sgn(cross(s1.p2 - s1.p1, s2.p2 - s2.p1)) == 0;\n\
    }\n\n//\u5C04\u5F71\nPoint project(Segment s, Point p){\n    Vector base = s.p2\
    \ - s.p1;\n    double r = dot(p - s.p1, base) / base.norm();\n    return s.p1\
    \ + base * r;\n}\n\n//\u53CD\u5C04\nPoint reflect(Segment s, Point p){\n    return\
    \ p + (project(s, p) - p) * 2.0;\n}\n\nint main(){\n    Line l;\n    int q;\n\
    \    cin >> l >> q;\n    while(q--){\n        Point p;\n        cin >> p;\n  \
    \      cout << reflect(l, p) << endl;\n    }\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nusing LL = long long;\nusing\
    \ ULL = unsigned long long;\nconst double PI = acos(-1);\ntemplate<class T>constexpr\
    \ T INF() { return ::std::numeric_limits<T>::max(); }\ntemplate<class T>constexpr\
    \ T HINF() { return INF<T>() / 2; }\ntemplate <typename T_char>T_char TL(T_char\
    \ cX) { return tolower(cX); };\ntemplate <typename T_char>T_char TU(T_char cX)\
    \ { return toupper(cX); };\ntemplate<class T> bool chmin(T& a,T b) { if(a > b){a\
    \ = b; return true;} return false; }\ntemplate<class T> bool chmax(T& a,T b) {\
    \ if(a < b){a = b; return true;} return false; }\nint popcnt(unsigned long long\
    \ n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++; return\
    \ cnt; }\nint d_sum(LL n) { int ret = 0; while (n > 0) { ret += n % 10; n /= 10;\
    \ }return ret; }\nint d_cnt(LL n) { int ret = 0; while (n > 0) { ret++; n /= 10;\
    \ }return ret; }\nLL gcd(LL a, LL b) { if (b == 0)return a; return gcd(b, a%b);\
    \ };\nLL lcm(LL a, LL b) { LL g = gcd(a, b); return a / g*b; };\n# define ALL(qpqpq)\
    \           (qpqpq).begin(),(qpqpq).end()\n# define UNIQUE(wpwpw)        sort(ALL((wpwpw)));(wpwpw).erase(unique(ALL((wpwpw))),(wpwpw).end())\n\
    # define LOWER(epepe)         transform(ALL((epepe)),(epepe).begin(),TL<char>)\n\
    # define UPPER(rprpr)         transform(ALL((rprpr)),(rprpr).begin(),TU<char>)\n\
    # define FOR(i,tptpt,ypypy)   for(LL i=(tptpt);i<(ypypy);i++)\n# define REP(i,upupu)\
    \         FOR(i,0,upupu)\n\nstruct INIT{\n    INIT(){\n        std::ios::sync_with_stdio(false);\n\
    \        std::cin.tie(0);\n        cout << fixed << setprecision(20);\n    }\n\
    }INIT;\n\n# define EPS 10e-9\n\n//a > 0\u306A\u3089\u3070+1, a == 0\u306A\u3089\
    \u30700, a < 0\u306A\u3089\u3070-1\u3000\u3092\u8FD4\u3059\u3002\u3000\u57FA\u672C\
    \u7684\u306BEPS\u8FBC\u307F\u306E\u8A55\u4FA1\u306F\u3053\u308C\u3067\u884C\u3046\
    \u3002\n//\u4E0D\u7B49\u5F0F\u306F\u3001\u52A0\u6E1B\u7B97\u306B\u76F4\u3057\u3066\
    \u3053\u308C\u306B\u9069\u7528\u3059\u308B\u3002\nint sgn(const double a) {\n\
    \    return (a < -EPS ? -1 : (a > EPS ? +1 : 0));\n}\n\n// sqrt\u306B\u8CA0\u6570\
    \u304C\u5165\u3089\u306A\u3044\u3088\u3046\u306B\u3059\u308B\n\n//\u3068\u308A\
    \u3042\u3048\u305A\u771F\u4F3C\u308B\n\n//\u70B9\nstruct Point {\n    double x,\
    \ y;\n\n    Point(double _x = 0.0, double _y = 0.0): x(_x), y(_y) {}\n\n    Point\
    \ operator - () const{return Point(-x, -y);};\n\n    Point operator + (const Point\
    \ &p) const{return Point(x + p.x, y + p.y);}\n    Point operator - (const Point\
    \ &p) const{return Point(x - p.x, y - p.y);}\n    Point operator * (double k)\
    \ const{return Point(x * k, y * k);}\n    Point operator / (double k) const{return\
    \ Point(x / k, y / k);}\n\n    double norm(){return x * x + y * y;}\n    double\
    \ abs(){return sqrt(max(0.0, norm()));};\n};\nistream& operator >> (istream &is,\
    \ Point &p){return is >> p.x >> p.y;}\nostream& operator << (ostream &os, const\
    \ Point &p){return os << p.x << \" \" << p.y;}\n\n\n//\u30D9\u30AF\u30C8\u30EB\
    \ntypedef Point Vector;\n\n//\u5185\u7A4D\ndouble dot(Vector a, Vector b){\n \
    \   return a.x * b.x + a.y * b.y;\n}\n\n//\u5916\u7A4D\ndouble cross(Vector a,\
    \ Vector b){\n    return a.x * b.y - a.y * b.x;\n}\n\n//\u7DDA\u5206\nstruct Segment{\n\
    \    Point p1, p2;\n    Segment(Point _p1 = Point(), Point _p2 = Point()) : p1(_p1),\
    \ p2(_p2) {}\n};\nistream& operator >> (istream &is, Segment &s){return is >>\
    \ s.p1 >> s.p2;}\nostream& operator << (ostream &os, const Segment &s){return\
    \ os << s.p1 << \" \" << s.p2;}\n\n//\u76F4\u7DDA\u2190\u7DDA\u5206\u3068\u533A\
    \u5225\ntypedef Segment Line;\n\n//\u5186\nstruct Circle{\n    Point c;\n    double\
    \ r;\n    Circle(Point _c = Point(), double _r = 0.0): c(_c), r(_r) {}\n};\n\n\
    //\u591A\u89D2\u5F62\ntypedef vector<Point> Polygon;\n\n//\u76F4\u4EA4\u5224\u5B9A\
    \nbool isOrthogonal(Vector a, Vector b){\n    return sgn(dot(a, b)) == 0;\n}\n\
    bool isOrthogonal(Segment s1, Segment s2){\n    return sgn(dot(s1.p2 - s1.p1,\
    \ s2.p2 - s2.p1)) == 0;\n}\n\n//\u4E26\u884C\u5224\u5B9A\nbool isParallel(Vector\
    \ a, Vector b){\n    return sgn(cross(a, b)) == 0;\n}\nbool isParallel(Segment\
    \ s1, Segment s2){\n    return sgn(cross(s1.p2 - s1.p1, s2.p2 - s2.p1)) == 0;\n\
    }\n\n//\u5C04\u5F71\nPoint project(Segment s, Point p){\n    Vector base = s.p2\
    \ - s.p1;\n    double r = dot(p - s.p1, base) / base.norm();\n    return s.p1\
    \ + base * r;\n}\n\n//\u53CD\u5C04\nPoint reflect(Segment s, Point p){\n    return\
    \ p + (project(s, p) - p) * 2.0;\n}\n\nint main(){\n    Line l;\n    int q;\n\
    \    cin >> l >> q;\n    while(q--){\n        Point p;\n        cin >> p;\n  \
    \      cout << reflect(l, p) << endl;\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: geomet.cpp
  requiredBy: []
  timestamp: '2022-08-02 11:18:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geomet.cpp
layout: document
redirect_from:
- /library/geomet.cpp
- /library/geomet.cpp.html
title: geomet.cpp
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/point.hpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n\nconstexpr double EPS = 1e-7;\n\ninline bool equal(const double &a, const\
    \ double &b) {\n\treturn fabs(a - b) < EPS;\n}\n\ntemplate<typename T> struct\
    \ Point {\npublic:\n\tcomplex<T> p;\n\n\tPoint(T x=0, T y=0) : p(x, y) {}\n\n\t\
    T& x() { return reinterpret_cast<T*>(&p)[0]; }\n\tT& y() { return reinterpret_cast<T*>(&p)[1];\
    \ }\n\n\tconst T& x() const { return reinterpret_cast<const T*>(&p)[0]; }\n\t\
    const T& y() const { return reinterpret_cast<const T*>(&p)[1]; }\n\n\t// point\
    \ \u540C\u58EB\u306E\u6F14\u7B97\n\tconstexpr Point operator+(const Point rhs)\
    \ const {\n\t\treturn Point(this->x() + rhs.x(), this->y() + rhs.y());\n\t}\n\t\
    constexpr Point operator-(const Point rhs) const {\n\t\treturn Point(this->x()\
    \ - rhs.x(), this->y() - rhs.y());\n\t}\n\tconstexpr Point operator*(const Point\
    \ rhs) const {\n\t\treturn Point(this->x() * rhs.x() - this->y() * rhs.y(), this->x()\
    \ * rhs.y() + this->y() * rhs.x());\n\t}\n\tconstexpr Point operator/(const Point\
    \ rhs) const {\n\t\tassert(not equal(0.0, rhs.abs()));\n\t\treturn Point(this->x()\
    \ * rhs.x() + this->y() * rhs.y(), rhs.x() * this->y() - this->x() * rhs.y())\
    \ / (rhs.abs()*rhs.abs());\n\t}\n\n\t// point \u3092\u5B9A\u6570\u500D\u3059\u308B\
    \n\tconstexpr Point operator*(const double rhs) const {\n\t\tassert(not equal(0.0,\
    \ rhs));\n\t\treturn Point(this->x() * rhs, this->y() * rhs);\n\t}\n\tconstexpr\
    \ Point operator/(const double rhs) const {\n\t\tassert(not equal(0.0, rhs));\n\
    \t\treturn Point(this->x() / rhs, this->y() / rhs);\n\t}\n\n\t// \u7D76\u5BFE\u5024\
    \n\tdouble abs() const {\n\t\treturn std::abs(p);\n\t}\n\n\t// \u5358\u4F4D\u30D9\
    \u30AF\u30C8\u30EB\n\tPoint get_unit_vector() const {\n\t\tdouble mag = this->abs();\n\
    \t\tassert(not equal(0.0, mag));\n\t\treturn *this / mag;\n\t}\n\n\t// \u6CD5\u7DDA\
    \u30D9\u30AF\u30C8\u30EB\n\tPoint get_normal_vector() const {\n\t\t// 90\u5EA6\
    \u56DE\u8EE2\u3057\u305F\u5358\u4F4D\u30D9\u30AF\u30C8\u30EB\u3092\u304B\u3051\
    \u308B\n\t\t// TODO: \u3069\u3063\u3061\u306E\u65B9\u5411\u306B\u56DE\u8EE2\u3057\
    \u305F\u3044\u304B\u3092\u547C\u3079\u308B\u3088\u3046\u306B\u3059\u308B\n\t\t\
    return (*this * Point(0.0, 1.0)).get_unit_vector();\n\t}\n\n\t// \u53CD\u6642\u8A08\
    \u56DE\u308A\u306B\u03B8\u56DE\u8EE2\n\t// \u03B8\u306F\u30E9\u30B8\u30A2\u30F3\
    \n\tPoint rotate(const double &theta) {\n\t\treturn Point(cos(theta)*this->x()\
    \ - sin(theta)*this->y(), sin(theta)*this->x() + cos(theta)*this->y());\n\t}\n\
    \n\t// \u30C7\u30D0\u30C3\u30B0\u7528\u51FA\u529B\n\tfriend std::ostream& operator<<(std::ostream&\
    \ os, const Point& rhs) {\n\t\tos << \"(\" <<  rhs.x() << \", \" << rhs.y() <<\
    \ \")\";\n\t\treturn os;\n\t}\n};\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n\nconstexpr double EPS = 1e-7;\n\
    \ninline bool equal(const double &a, const double &b) {\n\treturn fabs(a - b)\
    \ < EPS;\n}\n\ntemplate<typename T> struct Point {\npublic:\n\tcomplex<T> p;\n\
    \n\tPoint(T x=0, T y=0) : p(x, y) {}\n\n\tT& x() { return reinterpret_cast<T*>(&p)[0];\
    \ }\n\tT& y() { return reinterpret_cast<T*>(&p)[1]; }\n\n\tconst T& x() const\
    \ { return reinterpret_cast<const T*>(&p)[0]; }\n\tconst T& y() const { return\
    \ reinterpret_cast<const T*>(&p)[1]; }\n\n\t// point \u540C\u58EB\u306E\u6F14\u7B97\
    \n\tconstexpr Point operator+(const Point rhs) const {\n\t\treturn Point(this->x()\
    \ + rhs.x(), this->y() + rhs.y());\n\t}\n\tconstexpr Point operator-(const Point\
    \ rhs) const {\n\t\treturn Point(this->x() - rhs.x(), this->y() - rhs.y());\n\t\
    }\n\tconstexpr Point operator*(const Point rhs) const {\n\t\treturn Point(this->x()\
    \ * rhs.x() - this->y() * rhs.y(), this->x() * rhs.y() + this->y() * rhs.x());\n\
    \t}\n\tconstexpr Point operator/(const Point rhs) const {\n\t\tassert(not equal(0.0,\
    \ rhs.abs()));\n\t\treturn Point(this->x() * rhs.x() + this->y() * rhs.y(), rhs.x()\
    \ * this->y() - this->x() * rhs.y()) / (rhs.abs()*rhs.abs());\n\t}\n\n\t// point\
    \ \u3092\u5B9A\u6570\u500D\u3059\u308B\n\tconstexpr Point operator*(const double\
    \ rhs) const {\n\t\tassert(not equal(0.0, rhs));\n\t\treturn Point(this->x() *\
    \ rhs, this->y() * rhs);\n\t}\n\tconstexpr Point operator/(const double rhs) const\
    \ {\n\t\tassert(not equal(0.0, rhs));\n\t\treturn Point(this->x() / rhs, this->y()\
    \ / rhs);\n\t}\n\n\t// \u7D76\u5BFE\u5024\n\tdouble abs() const {\n\t\treturn\
    \ std::abs(p);\n\t}\n\n\t// \u5358\u4F4D\u30D9\u30AF\u30C8\u30EB\n\tPoint get_unit_vector()\
    \ const {\n\t\tdouble mag = this->abs();\n\t\tassert(not equal(0.0, mag));\n\t\
    \treturn *this / mag;\n\t}\n\n\t// \u6CD5\u7DDA\u30D9\u30AF\u30C8\u30EB\n\tPoint\
    \ get_normal_vector() const {\n\t\t// 90\u5EA6\u56DE\u8EE2\u3057\u305F\u5358\u4F4D\
    \u30D9\u30AF\u30C8\u30EB\u3092\u304B\u3051\u308B\n\t\t// TODO: \u3069\u3063\u3061\
    \u306E\u65B9\u5411\u306B\u56DE\u8EE2\u3057\u305F\u3044\u304B\u3092\u547C\u3079\
    \u308B\u3088\u3046\u306B\u3059\u308B\n\t\treturn (*this * Point(0.0, 1.0)).get_unit_vector();\n\
    \t}\n\n\t// \u53CD\u6642\u8A08\u56DE\u308A\u306B\u03B8\u56DE\u8EE2\n\t// \u03B8\
    \u306F\u30E9\u30B8\u30A2\u30F3\n\tPoint rotate(const double &theta) {\n\t\treturn\
    \ Point(cos(theta)*this->x() - sin(theta)*this->y(), sin(theta)*this->x() + cos(theta)*this->y());\n\
    \t}\n\n\t// \u30C7\u30D0\u30C3\u30B0\u7528\u51FA\u529B\n\tfriend std::ostream&\
    \ operator<<(std::ostream& os, const Point& rhs) {\n\t\tos << \"(\" <<  rhs.x()\
    \ << \", \" << rhs.y() << \")\";\n\t\treturn os;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: geometry/point.hpp
  requiredBy: []
  timestamp: '2024-03-12 18:15:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/point.hpp
layout: document
redirect_from:
- /library/geometry/point.hpp
- /library/geometry/point.hpp.html
title: geometry/point.hpp
---

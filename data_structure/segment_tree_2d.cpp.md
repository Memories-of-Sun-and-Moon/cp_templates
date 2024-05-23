---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B&lang=ja
  bundledCode: "#line 1 \"data_structure/segment_tree_2d.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B&lang=ja\"\n\
    #include<bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename T>struct segment_tree_2d\
    \ {\n\tusing F = function<T(T, T)>;\n\tint id(int r, int c) const {return r*2*w+c;\
    \ }\n\n\tint h, w;\n\tvector<T> node;\n\tF combine;\n\tT identify;\n\n\tsegment_tree_2d(int\
    \ _h, int _w, F _combine, T _identify) : combine(_combine), identify(_identify){\n\
    \t\th = w = 1;\n\t\twhile(h < _h) h <<= 1;\n\t\twhile(w < _w) w <<= 1;\n\t\tnode.assign(4*h*w,\
    \ identify);\n\t}\n\n\tsegment_tree_2d(vector<vector<T>> &v, F _combine, T _identify)\
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
    \ i, 2*k+2, (sj+tj)/2, tj);\n\t\treturn combine(vs, vt);\n\t}\n};\n\nint main(){\n\
    \tint n;\n\tcin >> n;\n\tconst int  RC = 1050;\n\tsegment_tree_2d<int> seg(RC,\
    \ RC, [](auto l, auto r){return l+r;}, 0);\n\twhile(n--){\n\t\tint x1, y1, x2,\
    \ y2;\n\t\tcin >> x1 >> y1 >> x2 >> y2;\n\t\tseg.set(y1, x1, seg.get(y1, x1)+1);\n\
    \t\tseg.set(y1, x2, seg.get(y1, x2)-1);\n\t\tseg.set(y2, x1, seg.get(y2, x1)-1);\n\
    \t\tseg.set(y2, x2, seg.get(y2, x2)+1);\n\t}\n\tint ans = 0;\n\tfor(int i = 0;i\
    \ < RC;i++)for(int j = 0;j < RC;j++)ans = max(ans, seg.fold(0, 0, i+1, j+1));\n\
    \tcout << ans << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B&lang=ja\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename T>struct\
    \ segment_tree_2d {\n\tusing F = function<T(T, T)>;\n\tint id(int r, int c) const\
    \ {return r*2*w+c; }\n\n\tint h, w;\n\tvector<T> node;\n\tF combine;\n\tT identify;\n\
    \n\tsegment_tree_2d(int _h, int _w, F _combine, T _identify) : combine(_combine),\
    \ identify(_identify){\n\t\th = w = 1;\n\t\twhile(h < _h) h <<= 1;\n\t\twhile(w\
    \ < _w) w <<= 1;\n\t\tnode.assign(4*h*w, identify);\n\t}\n\n\tsegment_tree_2d(vector<vector<T>>\
    \ &v, F _combine, T _identify) : combine(_combine), identify(_identify){\n\t\t\
    h = w = 1;\n\t\twhile(h < (int)v.size()) h <<= 1;\n\t\twhile(w < (int)v[0].size())\
    \ w <<= 1;\n\t\tnode.assign(4*h*w, identify);\n\t\tfor(int i = 0;i < (int)v.size();\
    \ i++){\n\t\t\tfor(int j = 0;j < (int)v[0].size();j++){\n\t\t\t\tnode[id(i+h-1,\
    \ j+w-1)] = v[i][j];\n\t\t\t}\n\t\t}\n\t\tfor(int i = 2*h-2; i > h-2;i--){\n\t\
    \t\tfor(int j = w-2; j >= 0;j--){\n\t\t\t\tnode[id(i, j)] = combine(node[id(i,\
    \ 2*j+1)], node[id(i, 2*j+2)]);\n\t\t\t}\n\t\t}\n\t\tfor(int i = h-2;i >= 0;i--){\n\
    \t\t\tfor(int j = 0;j < 2*w-1;j++){\n\t\t\t\tnode[id(i, j)] = combine(node[id(2*i+1,\
    \ j)], node[id(2*i+2, j)]);\n\t\t\t}\n\t\t}\n\t}\n\n\tvoid set(int y, int x, T\
    \ val){\n\t\ty += h-1;\n\t\tx += w-1;\n\t\tnode[id(y, x)] = val;\n\n\t\tfor(int\
    \ j = (x+1)/2-1;j >= 0;j = (j+1)/2-1){\n\t\t\tnode[id(y, j)] = combine(node[id(y,\
    \ 2*j+1)], node[id(y, 2*j+2)]);\n\t\t}\n\n\t\tfor(int i = (y+1)/2-1;i >= 0;i =\
    \ (i+1)/2-1){\n\t\t\tfor(int j = x;j >= 0;j = (j+1)/2-1){\n\t\t\t\tnode[id(i,\
    \ j)] = combine(node[id(2*i+1, j)], node[id(2*i+2, j)]);\n\t\t\t}\n\t\t}\n\t}\n\
    \n\tT get(int y, int x){\n\t\treturn node[id(y+h-1, x+w-1)];\n\t}\n\n\tT fold(int\
    \ li, int lj, int ri, int rj){\n\t\treturn fold_h(li, lj, ri, rj);\n\t}\n\n\t\
    T fold_h(int li, int lj, int ri, int rj, int k=0, int si=0, int ti=-1){\n\t\t\
    if(ti<0)ti = h;\n\n\t\tif(ri <= si || ti <= li)return identify;\n\t\tif(li <=\
    \ si && ti <= ri)return fold_w(lj, rj, k);\n\t\tT vs = fold_h(li, lj, ri, rj,\
    \ 2*k+1, si, (si+ti)/2);\n\t\tT vt = fold_h(li, lj, ri, rj, 2*k+2, (si+ti)/2,\
    \ ti);\n\t\treturn combine(vs, vt);\n\t}\n\n\tT fold_w(int lj, int rj, int i,\
    \ int k=0, int sj=0, int tj=-1){\n\t\tif(tj<0) tj = w;\n\n\t\tif(rj <= sj || tj\
    \ <= lj)return identify;\n\t\tif(lj <= sj && tj <= rj)return node[id(i, k)];\n\
    \t\tT vs = fold_w(lj, rj, i, 2*k+1, sj, (sj+tj)/2);\n\t\tT vt = fold_w(lj, rj,\
    \ i, 2*k+2, (sj+tj)/2, tj);\n\t\treturn combine(vs, vt);\n\t}\n};\n\nint main(){\n\
    \tint n;\n\tcin >> n;\n\tconst int  RC = 1050;\n\tsegment_tree_2d<int> seg(RC,\
    \ RC, [](auto l, auto r){return l+r;}, 0);\n\twhile(n--){\n\t\tint x1, y1, x2,\
    \ y2;\n\t\tcin >> x1 >> y1 >> x2 >> y2;\n\t\tseg.set(y1, x1, seg.get(y1, x1)+1);\n\
    \t\tseg.set(y1, x2, seg.get(y1, x2)-1);\n\t\tseg.set(y2, x1, seg.get(y2, x1)-1);\n\
    \t\tseg.set(y2, x2, seg.get(y2, x2)+1);\n\t}\n\tint ans = 0;\n\tfor(int i = 0;i\
    \ < RC;i++)for(int j = 0;j < RC;j++)ans = max(ans, seg.fold(0, 0, i+1, j+1));\n\
    \tcout << ans << endl;\n}"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segment_tree_2d.cpp
  requiredBy: []
  timestamp: '2024-05-23 22:56:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/segment_tree_2d.cpp
layout: document
redirect_from:
- /library/data_structure/segment_tree_2d.cpp
- /library/data_structure/segment_tree_2d.cpp.html
title: data_structure/segment_tree_2d.cpp
---

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
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
  bundledCode: "#line 1 \"graph/warshall_floyd.cpp\"\n# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename T = int>\
    \ struct warshall_floyd {\n    int V;\n    vector<vector<T>> d;\n    T inf;\n\n\
    \    warshall_floyd(int _V) : V(_V){\n        inf = ::std::numeric_limits<T>::max()\
    \ / 2;\n        d = vector<vector<T>>(V, vector<T>(V));\n        for(int i = 0;i\
    \ < V;i++){\n            for(int j = 0;j < V;j++){\n                if(i == j)d[i][j]\
    \ = 0;\n                else d[i][j] = inf;\n            }\n        }\n    }\n\
    \n    void set(int a, int b, T cost){\n        d[a][b] = cost;\n    }\n\n    void\
    \ calc(){\n        for(int k = 0;k < V;k++){\n            for(int i = 0;i < V;i++){\n\
    \                if(d[i][k] == inf)continue;\n                for(int j = 0;j\
    \ < V;j++){\n                    if(d[k][j] == inf)continue;\n               \
    \     d[i][j] = min(d[i][j], d[i][k] + d[k][j]);\n                }\n        \
    \    }\n        }\n    }\n};\n\nint v, e;\nint s, t, d;\n\nint main(){\n    cin\
    \ >> v >> e;\n    warshall_floyd<long long> wf(v);\n    for(int i = 0;i < e;i++){\n\
    \        cin >> s >> t >> d;\n        wf.set(s, t, d);\n    }\n    wf.calc();\n\
    \    for(int i = 0;i < v;i++){\n        if(wf.d[i][i] < 0){\n            cout\
    \ << \"NEGATIVE CYCLE\" << endl;\n            return 0;\n        }\n    }\n  \
    \  for(int i = 0;i < v;i++){\n        for(int j = 0;j < v;j++){\n            if(j)cout\
    \ << \" \";\n            if(wf.d[i][j] == wf.inf)cout << \"INF\";\n          \
    \  else cout << wf.d[i][j];\n        }\n        cout << endl;\n    }\n}\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename T = int>\
    \ struct warshall_floyd {\n    int V;\n    vector<vector<T>> d;\n    T inf;\n\n\
    \    warshall_floyd(int _V) : V(_V){\n        inf = ::std::numeric_limits<T>::max()\
    \ / 2;\n        d = vector<vector<T>>(V, vector<T>(V));\n        for(int i = 0;i\
    \ < V;i++){\n            for(int j = 0;j < V;j++){\n                if(i == j)d[i][j]\
    \ = 0;\n                else d[i][j] = inf;\n            }\n        }\n    }\n\
    \n    void set(int a, int b, T cost){\n        d[a][b] = cost;\n    }\n\n    void\
    \ calc(){\n        for(int k = 0;k < V;k++){\n            for(int i = 0;i < V;i++){\n\
    \                if(d[i][k] == inf)continue;\n                for(int j = 0;j\
    \ < V;j++){\n                    if(d[k][j] == inf)continue;\n               \
    \     d[i][j] = min(d[i][j], d[i][k] + d[k][j]);\n                }\n        \
    \    }\n        }\n    }\n};\n\nint v, e;\nint s, t, d;\n\nint main(){\n    cin\
    \ >> v >> e;\n    warshall_floyd<long long> wf(v);\n    for(int i = 0;i < e;i++){\n\
    \        cin >> s >> t >> d;\n        wf.set(s, t, d);\n    }\n    wf.calc();\n\
    \    for(int i = 0;i < v;i++){\n        if(wf.d[i][i] < 0){\n            cout\
    \ << \"NEGATIVE CYCLE\" << endl;\n            return 0;\n        }\n    }\n  \
    \  for(int i = 0;i < v;i++){\n        for(int j = 0;j < v;j++){\n            if(j)cout\
    \ << \" \";\n            if(wf.d[i][j] == wf.inf)cout << \"INF\";\n          \
    \  else cout << wf.d[i][j];\n        }\n        cout << endl;\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/warshall_floyd.cpp
  requiredBy: []
  timestamp: '2024-05-23 22:55:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/warshall_floyd.cpp
layout: document
redirect_from:
- /library/graph/warshall_floyd.cpp
- /library/graph/warshall_floyd.cpp.html
title: graph/warshall_floyd.cpp
---

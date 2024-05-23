---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import random\nimport subprocess\n\nseed = 101\nrandom.seed(seed)\n'''\n\u5909\
    \u66F4\u3059\u3079\u304D\u70B9\n\n1. \u5B9F\u884C\u30D5\u30A1\u30A4\u30EB(mycode)\n\
    2. \u5165\u529B(mmake_file\u5185)\n3. \u30D5\u30A1\u30A4\u30EB\u51FA\u529B(make_file\u5185\
    )\n'''\n\n# ---- \u5B9F\u884C\u30D5\u30A1\u30A4\u30EB ----\nmycode = './B'\n\n\
    def make_file():\n# ---- \u5165\u529B\u3092\u7528\u610F ----\n    h = random.randrange(2,\
    \ 5)\n    w = random.randrange(2, 5)\n    fld = [(['a'] * w) for _ in range(h)]\n\
    \n    for i in range(h):\n        for j in range(w):\n            num = random.randrange(0,\
    \ 26)\n            fld[i][j] = chr(ord('a') + num)\n\n    q = random.randrange(1,\
    \ 5)\n\n    a = [random.randrange(1, h) for _ in range(q)]\n    b = [random.randrange(1,\
    \ w) for _ in range(q)]\n    \n# ---- \u5165\u529B\u3092\u7528\u610F\uFF08\u3053\
    \u3053\u307E\u3067\uFF09 ---- \n\n    with open('test.txt', 'w') as f:\n     \
    \   f.write(f'{h} {w}\\n')\n        for i in range(h):\n            f.write(''.join(fld[i][j]\
    \ for j in range (w)) + '\\n')\n        f.write(f'{q}\\n')\n        for i in range(q):\n\
    \            f.write(f'{a[i]} {b[i]}\\n')\n\n    \n    return\n\niteration = 0\n\
    \nwhile True:\n    make_file()\n    with open('test.txt', 'r') as fh1:\n     \
    \   with open('ret1.txt','w') as fh2:\n            subprocess.check_call(mycode,\
    \ stdin=fh1, stdout=fh2)\n    \n    with open('test.txt', 'r') as fh1:\n     \
    \   with open('ret2.txt','w') as fh2:\n            subprocess.check_call('./_STRESS_SOLVER',\
    \ stdin=fh1, stdout=fh2)\n\n    with open('ret1.txt', 'r') as fh1:\n        with\
    \ open('ret2.txt', 'r') as fh2:\n            ret1 = fh1.read()\n            ret2\
    \ = fh2.read()\n\n            if ret1 != ret2:\n                with open('test.txt',\
    \ 'r') as fh3:\n                    \n                    print(f'seed = {seed}')\n\
    \                    \n                    print(fh3.read())\n               \
    \     print(f'your code = {ret1}')\n                    print(f'requirement(s)\
    \ = {ret2}')\n                    exit()\n    \n    iteration += 1\n    if iteration\
    \ % 100 == 0:\n        print(iteration)"
  dependsOn: []
  isVerificationFile: false
  path: _STRESS_CHECKER.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: _STRESS_CHECKER.py
layout: document
redirect_from:
- /library/_STRESS_CHECKER.py
- /library/_STRESS_CHECKER.py.html
title: _STRESS_CHECKER.py
---

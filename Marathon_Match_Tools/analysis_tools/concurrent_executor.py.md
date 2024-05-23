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
  code: "import concurrent.futures\nimport pathlib\nimport subprocess\n\nfrom colorama\
    \ import Fore, Back, Style\n\ndef run(*, exe: str, input_path: pathlib.Path, output_path:\
    \ pathlib.Path, seed: int):\n    \n    print('running the exe for seed ' + Fore.GREEN\
    \ + f'{seed}' + Style.RESET_ALL)\n    try:\n        with open(input_path) as fh1:\n\
    \            with open(output_path, 'w') as fh2:\n                subprocess.check_call(['cargo',\
    \ 'run', '-r', '--bin', 'tester', str(exe)], stdin=fh1, stdout=fh2)\n    except\
    \ subprocess.SubprocessError:\n        print(Fore.RED + 'failed for seed' + Fore.WHITE\
    \ + ' = ' + Fore.GREEN + f'{seed}' + Style.RESET_ALL)\n\ndef main(max_workers:\
    \ int, testcases: int, exe: str):\n    \n    pathlib.Path('out').mkdir(exist_ok=True)\n\
    \    with concurrent.futures.ThreadPoolExecutor(max_workers=max_workers) as executor:\n\
    \        for i in range(testcases):\n            input_path = pathlib.Path('in',\
    \ f'{i:04}.txt')\n            output_path = pathlib.Path('out', f'{i:04}.out')\n\
    \            executor.submit(run, exe=exe, input_path=input_path, output_path=output_path,\
    \ seed=i)"
  dependsOn: []
  isVerificationFile: false
  path: Marathon_Match_Tools/analysis_tools/concurrent_executor.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Marathon_Match_Tools/analysis_tools/concurrent_executor.py
layout: document
redirect_from:
- /library/Marathon_Match_Tools/analysis_tools/concurrent_executor.py
- /library/Marathon_Match_Tools/analysis_tools/concurrent_executor.py.html
title: Marathon_Match_Tools/analysis_tools/concurrent_executor.py
---

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
  code: "import pathlib\nimport re\nimport subprocess\n\nfrom colorama import Fore,\
    \ Back, Style\n\ndef calc(input_path: pathlib.Path, output_path: pathlib.Path,\
    \ seed: int) -> int:\n\n    print('running the visualizer for seed ' + Fore.GREEN\
    \ + f'{seed}' + Style.RESET_ALL)\n\n    try:\n        ret = subprocess.check_output(['cargo',\
    \ 'run', '--release', '--bin', 'vis', str(input_path), str(output_path)])\n  \
    \  except subprocess.SubprocessError:\n        print(Fore.RED + 'failed for seed'\
    \ + Fore.WHITE + '=' + Fore.GREEN + f'{seed}')\n        return 0\n\n    score\
    \ = re.search(r'\\d+', ret.decode('utf-8'))\n    score = score.group()\n\n   \
    \ return int(score)\n\ndef main(testcases: int):\n    \n    for i in range(testcases):\n\
    \        input_path = pathlib.Path('in', f'{i:04}.txt')\n        output_path =\
    \ pathlib.Path('out', f'{i:04}.out')\n\n        score = calc(input_path=input_path,\
    \ output_path=output_path, seed=i)\n        with open('score.txt', 'a') as f:\n\
    \            f.write(f'{score}\\n')"
  dependsOn: []
  isVerificationFile: false
  path: Marathon_Match_Tools/analysis_tools/score_calclator.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Marathon_Match_Tools/analysis_tools/score_calclator.py
layout: document
redirect_from:
- /library/Marathon_Match_Tools/analysis_tools/score_calclator.py
- /library/Marathon_Match_Tools/analysis_tools/score_calclator.py.html
title: Marathon_Match_Tools/analysis_tools/score_calclator.py
---

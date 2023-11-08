import argparse

from analysis_tools import concurrent_executor
from analysis_tools import archive
from analysis_tools import score_calclator

# parser

parser = argparse.ArgumentParser(description='Analyzer for AHCXXX')
parser.add_argument('-e', default='./AHCXXX', help='実行ファイルの選択')
parser.add_argument('-t', default=10, help='テストケース数')
parser.add_argument('-j', default=1, help='並列実行数')
parser.add_argument('name', help='保存する名前')
args = parser.parse_args()

args.t = int(args.t)
args.j = int(args.j)

concurrent_executor.main(max_workers=args.j, testcases=args.t, exe=args.e)

score_calclator.main(testcases=args.t)

archive.main(name=args.name)
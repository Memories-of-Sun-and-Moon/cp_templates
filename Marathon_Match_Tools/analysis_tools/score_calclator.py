import pathlib
import re
import subprocess

from colorama import Fore, Back, Style

def calc(input_path: pathlib.Path, output_path: pathlib.Path, seed: int) -> int:

    print('running the visualizer for seed ' + Fore.GREEN + f'{seed}' + Style.RESET_ALL)

    try:
        ret = subprocess.check_output(['cargo', 'run', '--release', '--bin', 'vis', str(input_path), str(output_path)])
    except subprocess.SubprocessError:
        print(Fore.RED + 'failed for seed' + Fore.WHITE + '=' + Fore.GREEN + f'{seed}')
        return 0

    score = re.search(r'\d+', ret.decode('utf-8'))
    score = score.group()

    return int(score)

def main(testcases: int):
    
    for i in range(testcases):
        input_path = pathlib.Path('in', f'{i:04}.txt')
        output_path = pathlib.Path('out', f'{i:04}.out')

        score = calc(input_path=input_path, output_path=output_path, seed=i)
        with open('score.txt', 'a') as f:
            f.write(f'{score}\n')
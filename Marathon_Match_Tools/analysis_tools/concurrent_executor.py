import concurrent.futures
import pathlib
import subprocess

from colorama import Fore, Back, Style

def run(*, exe: str, input_path: pathlib.Path, output_path: pathlib.Path, seed: int):
    
    print('running the exe for seed ' + Fore.GREEN + f'{seed}' + Style.RESET_ALL)
    try:
        with open(input_path) as fh1:
            with open(output_path, 'w') as fh2:
                subprocess.check_call(exe, stdin=fh1, stdout=fh2)
    except subprocess.SubprocessError:
        print(Fore.RED + 'failed for seed' + Fore.WHITE + ' = ' + Fore.GREEN + f'{seed}' + Style.RESET_ALL)

def main(max_workers: int, testcases: int, exe: str):
    
    pathlib.Path('out').mkdir(exist_ok=True)
    with concurrent.futures.ThreadPoolExecutor(max_workers=max_workers) as executor:
        for i in range(testcases):
            input_path = pathlib.Path('in', f'{i:04}.txt')
            output_path = pathlib.Path('out', f'{i:04}.txt')
            executor.submit(run, exe=exe, input_path=input_path, output_path=output_path, seed=i)
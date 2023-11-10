import datetime
import pathlib
import subprocess

def main(name: str):
    pathlib.Path('archive').mkdir(exist_ok=True)

    t_delta = datetime.timedelta(hours=9)
    JST = datetime.timezone(t_delta, 'JST')
    now = datetime.datetime.now(JST)
    name = str(f'{now:%m%d%H%M}') + str(name)

    pathlib.Path(name).mkdir()
    
    subprocess.run(['mv', '-v', 'out', f'{name}' + '/out'])
    subprocess.run(['mv', '-v', f'{name}', 'archive/' + f'{name}'])
    subprocess.run(['mv', 'score.txt', 'archive/' + f'{name}' + '/score.txt'])
    subprocess.run(['cp', 'AHCXXX.cpp', 'archive/' + f'{name}' + '/source.cpp'])

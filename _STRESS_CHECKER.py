import random
import subprocess

seed = 101
random.seed(seed)
'''
変更すべき点

1. 実行ファイル(mycode)
2. 入力(mmake_file内)
3. ファイル出力(make_file内)
'''

# ---- 実行ファイル ----
mycode = './B'

def make_file():
# ---- 入力を用意 ----
    h = random.randrange(2, 5)
    w = random.randrange(2, 5)
    fld = [(['a'] * w) for _ in range(h)]

    for i in range(h):
        for j in range(w):
            num = random.randrange(0, 26)
            fld[i][j] = chr(ord('a') + num)

    q = random.randrange(1, 5)

    a = [random.randrange(1, h) for _ in range(q)]
    b = [random.randrange(1, w) for _ in range(q)]
    
# ---- 入力を用意（ここまで） ---- 

    with open('test.txt', 'w') as f:
        f.write(f'{h} {w}\n')
        for i in range(h):
            f.write(''.join(fld[i][j] for j in range (w)) + '\n')
        f.write(f'{q}\n')
        for i in range(q):
            f.write(f'{a[i]} {b[i]}\n')

    
    return

iteration = 0

while True:
    make_file()
    with open('test.txt', 'r') as fh1:
        with open('ret1.txt','w') as fh2:
            subprocess.check_call(mycode, stdin=fh1, stdout=fh2)
    
    with open('test.txt', 'r') as fh1:
        with open('ret2.txt','w') as fh2:
            subprocess.check_call('./_STRESS_SOLVER', stdin=fh1, stdout=fh2)

    with open('ret1.txt', 'r') as fh1:
        with open('ret2.txt', 'r') as fh2:
            ret1 = fh1.read()
            ret2 = fh2.read()

            if ret1 != ret2:
                with open('test.txt', 'r') as fh3:
                    
                    print(f'seed = {seed}')
                    
                    print(fh3.read())
                    print(f'your code = {ret1}')
                    print(f'requirement(s) = {ret2}')
                    exit()
    
    iteration += 1
    if iteration % 100 == 0:
        print(iteration)
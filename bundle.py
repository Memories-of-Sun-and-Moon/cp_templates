import subprocess
import sys

file = sys.argv[1]

with open(file, 'r') as file:
	lines = file.readlines()

for line in lines:
	if "cerr" in line:
		raise ValueError("プログラム中に cerr が含まれています。forループなどで cerr デバッグしたものを消さずに提出すると TLE となる可能性があります。")

lines = [lines[0]] + ["#define debug(...) (static_cast<void>(0))\n"] + lines[3:]

with open('z.cpp', 'w') as file:
	file.writelines(lines)

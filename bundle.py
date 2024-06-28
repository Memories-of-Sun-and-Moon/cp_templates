import subprocess
import sys

file = sys.argv[1]

with open(file, 'r') as file:
	lines = file.readlines()

lines = [lines[0]] + ["#define debug(...) (static_cast<void>(0))\n"] + lines[3:]

with open('z.cpp', 'w') as file:
	file.writelines(lines)

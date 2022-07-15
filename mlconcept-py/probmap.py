## Copyright (C) 2022 bunnicash "@bunnicash" and licensed under GPL-2.0
import string
import random
from collections import Counter
import numpy as np

## Map cells for the game grid (8 of actually TODO 64 unique location lists)
A1 = []; A2 = []; A3 = []; A4 = []; A5 = []; A6 = []; A7 = []; A8 = []
testmap = ["0", "0", "0", "0", "0", "0", "0", "0"]

## Basic probability map (probmap)
def probmap():
	samples = 2
	with open(filepath) as fp:
		line = fp.readline()
		ncnt = 0  # for list (null count)
		while line:
			testmap[ncnt]=line.strip()  # use .strip() to get rid of "\n"s 
			line = fp.readline()
			ncnt += 1

	# Move to cell location identifier
	max_1 = 1 * samples  # max number of 1s permitted (atm 1 in 8 -> 8 in 64)
	A1.append(testmap[0]); A2.append(testmap[1]); A3.append(testmap[2]); A4.append(testmap[3]); A5.append(testmap[4]); A6.append(testmap[5]); A7.append(testmap[6]); A8.append(testmap[7])

	# Count 1s and 0s
	global total_1; global total_0; global probmap_tl
	
	cn_0 = A1.count('0'); cn_1 = A1.count('1'); probmap = cn_1 / samples; total_0 = cn_0; total_1 = cn_1
	print(f"A1: {cn_0}x '0' and {cn_1}x '1' and P1 is {probmap}")

	cn_0 = A2.count('0'); cn_1 = A2.count('1'); probmap = cn_1 / samples; total_0 += cn_0; total_1 += cn_1 
	print(f"A2: {cn_0}x '0' and {cn_1}x '1' and P1 is {probmap}")

	cn_0 = A3.count('0'); cn_1 = A3.count('1'); probmap = cn_1 / samples; total_0 += cn_0; total_1 += cn_1 
	print(f"A3: {cn_0}x '0' and {cn_1}x '1' and P1 is {probmap}")

	cn_0 = A4.count('0'); cn_1 = A4.count('1'); probmap = cn_1 / samples; total_0 += cn_0; total_1 += cn_1 
	print(f"A4: {cn_0}x '0' and {cn_1}x '1' and P1 is {probmap}")

	cn_0 = A5.count('0'); cn_1 = A5.count('1'); probmap = cn_1 / samples; total_0 += cn_0; total_1 += cn_1 
	print(f"A5: {cn_0}x '0' and {cn_1}x '1' and P1 is {probmap}")

	cn_0 = A6.count('0'); cn_1 = A6.count('1'); probmap = cn_1 / samples; total_0 += cn_0; total_1 += cn_1 
	print(f"A6: {cn_0}x '0' and {cn_1}x '1' and P1 is {probmap}")

	cn_0 = A7.count('0'); cn_1 = A7.count('1'); probmap = cn_1 / samples; total_0 += cn_0; total_1 += cn_1 
	print(f"A7: {cn_0}x '0' and {cn_1}x '1' and P1 is {probmap}")

	cn_0 = A8.count('0'); cn_1 = A8.count('1'); probmap = cn_1 / samples; total_0 += cn_0; total_1 += cn_1 
	print(f"A8: {cn_0}x '0' and {cn_1}x '1' and P1 is {probmap}\n")
	
	probmap_tl = total_1 / max_1
	
## Evaluate training grids probmap
mainpath = '/home/main/Desktop/'
files = ["test1.grid", "test2.grid"]

for item in files:
	filepath = mainpath + item
	probmap()
	
print(f"Summary Row A: {total_1}x '1' and {total_0}x '0' and P1(A) is {probmap_tl}\n")





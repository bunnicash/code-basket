## Copyright (C) 2022 bunnicash "@bunnicash" and licensed under GPL-2.0
import string
import random
from collections import Counter
import numpy as np

## Map cells for the game grid (64 unique location lists)
A1 = []; A2 = []; A3 = []; A4 = []; A5 = []; A6 = []; A7 = []; A8 = []; B1 = []; B2 = []; B3 = []; B4 = []; B5 = []; B6 = []; B7 = []; B8 = []
C1 = []; C2 = []; C3 = []; C4 = []; C5 = []; C6 = []; C7 = []; C8 = []; D1 = []; D2 = []; D3 = []; D4 = []; D5 = []; D6 = []; D7 = []; D8 = []
E1 = []; E2 = []; E3 = []; E4 = []; E5 = []; E6 = []; E7 = []; E8 = []; F1 = []; F2 = []; F3 = []; F4 = []; F5 = []; F6 = []; F7 = []; F8 = []
G1 = []; G2 = []; G3 = []; G4 = []; G5 = []; G6 = []; G7 = []; G8 = []; H1 = []; H2 = []; H3 = []; H4 = []; H5 = []; H6 = []; H7 = []; H8 = []

## Sample count start, binary distribution n/k
samples = 0
N = 64
K = 56  # K 0s, N-K 1s

## Define sample size
while samples < 256:
	array1 = np.array([0] * K + [1] * (N-K))
	# "print(array1)" before shuffle: unaltered binary distribution array

	np.random.shuffle(array1)
	# print(f"{array1}\n")
	# "print(array1[1])" print second item of random array (0-n)

	A1.append(array1[0]); A2.append(array1[1]); A3.append(array1[2]); A4.append(array1[3]); A5.append(array1[4]); A6.append(array1[5]); A7.append(array1[6]); A8.append(array1[7])
	samples +=1

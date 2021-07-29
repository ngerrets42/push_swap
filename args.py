# Script originally created by Codam student mraasvel

import random
import time
import sys

def random_args(MAXNUM, MAXARGC):
	random.seed(time.time())
	args = set()
	count = 0
	for i in range(1, MAXARGC + 1):
		num = random.randint(1, MAXNUM)
		if num in args:	
			continue
		if i == MAXARGC:
			count += 1
			print(num)
		else:
			count += 1
			print(num, end = " ")
		args.add(num)
	print("Count:", count)

def range_args(size):
	nums = list(range(0, size))
	random.shuffle(nums)
	print(*nums)

def input_args():
	argv = [2, 1, 3, 6, 5]
	for i, arg in enumerate(argv):
		if i != len(argv) - 1:
			print(arg, end = " ")
		else:
			print(arg)

if __name__ == '__main__':
	INTMAX = 2147483647
	INTMIN = -2147483648
	MAXARGC = 5
	MAXNUM = INTMAX


	if len(sys.argv) > 1:
		MAXARGC = int(sys.argv[1])
	# random_args(MAXNUM, MAXARGC)
	# input_args()
	range_args(MAXARGC)
import random

n = random.randint(1, 100000)
k = random.randint(1, n)
print("%d %d"%(n, k))

for i in range(n):
	l = random.randint(1, 1000000000)
	r = random.randint(l, 1000000000)
	print("%d %d"% (l, r))
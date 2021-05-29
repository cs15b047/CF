import numpy as np

t = 1
n = [1000, 1000, 1000]
q = 100000
print(t)
for test in range(t):
    print(n[test])
    for N in range(n[test] - 1):
        print("{} {}".format( N + 1, N + 2))
    for i in range(n[test]):
        print(np.random.randint(500000, 1000000))
    print(q)
    for i in range(q):
        print("1 1000")

n = 0

for i in range(1, 1001):
    n += (i ** i)

print(n % (10 ** 10))

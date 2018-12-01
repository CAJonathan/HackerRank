import sys
n = int(input())
for i in range(n):
    for j in range(n - i - 1):
        sys.stdout.write(" ")
    for j in range(n - i - 1, n):
        sys.stdout.write("#")
    print("")
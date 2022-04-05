import sys

sys.stdin = open('planting.in', 'r')
sys.stdout = open('planting.out', 'w')

n, cnt = int(input()), [0] * 1000000

for i in range(n - 1):
    a, b = [int(i) for i in input().split()]
    cnt[a] += 1
    cnt[b] += 1
print(max(cnt) + 1)

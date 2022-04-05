import sys
name = 'mountains'
sys.stdin = open(name+'.in', 'r')
sys.stdout = open(name+'.out', 'w')

n = int(input())
mts = []
for i in range (n):
    mts.append([int(j) for j in input().split()])
mts.sort(key = lambda x: (x[0]-x[1],-x[0]-x[1]))
# print(mts)
max = -float('inf')
ans = 0
for m in mts:
    r = m[0]+m[1]
    # print(max,r,m)
    if r > max:
        ans += 1
        max = r
print(ans)

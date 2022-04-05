import sys
name = 'teleport'
sys.stdin = open(name+'.in', 'r')
sys.stdout = open(name+'.out', 'w')

n = int(input())
tasks = []
for i in range (n):
    tasks.append([int(i) for i in input().split()])
f=0
pos = []
neg = []
for a,b in tasks:
    f += abs(a-b)
    if b>0:
        if 2*a<b:
            pos.append((-1,max(2*a,0)))
            pos.append((2,b))
            pos.append((-1,2*(b-max(a,0))))
    else:
        a=-a
        b=-b
        if 2*a<b:
            neg.append((-1, max(2*a,0)))
            neg.append((2, b))
            neg.append((-1, 2 * (b - max(a, 0))))
minf = float('inf')
pos.sort(key = lambda x: x[1])
neg.sort(key = lambda x: x[1])
# print(pos,neg)
slope = 0
y = 0
for (slopechange, newy) in pos:
    # print(f)
    f += slope*(newy-y)
    minf = min(minf,f)
    slope += slopechange
    y = newy
slope = 0
y = 0
for (slopechange, newy) in neg:
    # print(f)
    f += slope*(newy-y)
    minf = min(minf,f)
    slope += slopechange
    y = newy
print(minf)
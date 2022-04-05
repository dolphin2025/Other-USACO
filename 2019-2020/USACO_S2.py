from collections import deque
import sys
name = 'meetings'

if name:
    sys.stdin = open(name+'.in', 'r')
    sys.stdout = open(name+'.out', 'w')

n, l = [int(i) for i in input().split()]

info = [[int(i) for i in input().split()] for i in range (n)]
info = [[i[1],i[0],i[2]] for i in info]
pos = sorted([i for i in info if i[2]==1])
neg = sorted([i for i in info if i[2]==-1])

orderofweights = [i[1] for i in sorted(info)]
newweight = {}
for i in range(len(pos)): newweight[tuple(pos[i])] = orderofweights[len(neg)+i]
for i in range(len(neg)): newweight[tuple(neg[i])] = orderofweights[i]

finishes = [[newweight[tuple(i)],l-i[0] if i[2]==1 else i[0]] for i in info]
finishes.sort(key= lambda x: x[1])
sumw = sum([i[1] for i in info])
runsum = 0
for w,t in finishes:
    runsum += w
    if runsum>=sumw/2: break

ans=0
leftpos = deque()
for i in sorted(info):
    if i[2]==-1:
        while len(leftpos)>0 and i[0]-leftpos[0][0]>2*t: leftpos.popleft()
        # print(len(leftpos))
        ans+=len(leftpos)
    else: leftpos.append(i)
print(ans)
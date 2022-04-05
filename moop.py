import sys
name = 'moop'
sys.stdin = open(name+'.in', 'r')
sys.stdout = open(name+'.out', 'w')


n = int(input())
particles = [[int(i) for i in input().split()] for l in range (n)]
particles.sort()
minl=[float('inf')]

for i in range (n):
    minl.append(min(minl[-1],particles[i][1]))
minl=minl[1:]
maxr=[-float('inf')]

for i in range (n-1,-1,-1):
    maxr.append(max(maxr[-1],particles[i][1]))
maxr=maxr[1:]
maxr.reverse()

print(sum(minl[i]>maxr[i+1] for i in range (n-1))+1)
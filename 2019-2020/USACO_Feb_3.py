import sys
name = 'clocktree'
if name:
    sys.stdin = open(name+'.in', 'r')
    sys.stdout = open(name+'.out', 'w')

n=int(input())
vals=[int(i) for i in input().split()]
graph={i:set() for i in range (n)}
for i in range (n-1):
    a,b=[int(i) for i in input().split()]
    graph[a-1].add(b-1)
    graph[b-1].add(a-1)
numeven, numodd, sumeven, sumodd = 0,0,0,0
seen=set()

def dfs(e,u):
    global numeven, numodd, sumeven, sumodd
    if u not in seen:
        seen.add(u)
        if e:
            numeven+=1
            sumeven+=vals[u]
        else:
            numodd+=1
            sumodd+=vals[u]
        for v in graph[u]: dfs(not(e),v)

dfs(1,0)

if (sumeven-sumodd)%12==11: print(numodd)
elif (sumeven-sumodd)%12==0: print(n)
elif (sumeven-sumodd)%12==1: print(numeven)
else: print(0)
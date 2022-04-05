
import sys
sys.stdin = open('revegetate.in')
sys.stdout = open('revegetate.out','w')
sys.setrecursionlimit(1000000)
n,m = [int(i) for i in input().split()]
graph = {}
for i in range (n):
    graph[i] = set()
for i in range (m):
    inp = input().split()
    if inp[0] == 'D':
        graph[int(inp[1])-1].add((1,int(inp[2])-1))
        graph[int(inp[2])-1].add((1,int(inp[1])-1))
    else:
        graph[int(inp[1])-1].add((0, int(inp[2])-1))
        graph[int(inp[2])-1].add((0, int(inp[1])-1))
a = [2]*n
seen = set()
ans = '1'
def dfs(p,v):
    if a[p] in [v,2]:
        if p in seen:
            return
        a[p] = v
        seen.add(p)
    else:
        print(0)
        sys.exit()
    for c,q in graph[p]:
        if c:
            dfs(q, not v)
        else:
            dfs(q, v)
for p in range (n):
    if p not in seen:
        ans += '0'
        dfs(p,1)

print(ans)
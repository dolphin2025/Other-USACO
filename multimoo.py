import copy
import sys
name = 'multimoo'
sys.stdin = open(name+'.in', 'r')
sys.stdout = open(name+'.out', 'w')
sys.setrecursionlimit(1000000000)
def pretty_print_2D(M):
  lens = [len(M[0]) for i in range(0,len(M[0]))]
  fmt = ''.join('{{:{}}}'.format(x) for x in lens)
  table = [fmt.format(*row) for row in M]
  print('\n'.join(table))

n = int(input())
grid = [[int(id) for id in input().split()] for i in range (n)]
ngrid=copy.deepcopy(grid)
id = {}
globseen=set()
edges = {}
size = {}
def dfs(i,j,k):
    if (i,j) not in globseen:
        val=grid[i][j]
        globseen.add((i,j))
        size = 1
        if i and grid[i-1][j]==val: size += dfs(i-1,j,k)
        if j and grid[i][j-1]==val: size += dfs(i,j-1,k)
        if i<n-1 and grid[i+1][j]==val: size += dfs(i+1,j,k)
        if j<n-1 and grid[i][j+1]==val: size += dfs(i,j+1,k)
        ngrid[i][j] = k
        return size
    return 0
def dfs2(e,v,s):
    global size
    if v not in s:
        s.add(v)
        sz = size[v]
        for n in e[v]:
            sz += dfs2(e,n,s)
        return sz
    return 0
k=0
for i in range (n):
    for j in range (n):
        if (i,j) not in globseen:
            k+=1
            size[k] = dfs(i, j, k)
            id[k] = grid[i][j]
ans1=0
for i in size:
    ans1=max(size[i],ans1)
print(ans1)
# pretty_print_2D(ngrid)
grid=ngrid[:]
for i in range (n):
    for j in range (n):
        val = ngrid[i][j]
        if i:
            nval=grid[i-1][j]
            if val!= nval:
                pair = (min(id[val],id[nval]),max(id[nval],id[val]))
                if pair in edges:
                    if val in edges[pair]:
                        edges[pair][val].add(nval)
                    else:
                        edges[pair][val]={nval}
                else:
                    edges[pair] = {val:{nval}}
        if j:
            nval=grid[i][j-1]
            if val!= nval:
                pair = (min(id[val],id[nval]),max(id[nval],id[val]))
                if pair in edges:
                    if val in edges[pair]:
                        edges[pair][val].add(nval)
                    else:
                        edges[pair][val]={nval}
                else:
                    edges[pair] = {val:{nval}}
        if i<n-1:
            nval=grid[i+1][j]
            if val!= nval:
                pair = (min(id[val],id[nval]),max(id[nval],id[val]))
                if pair in edges:
                    if val in edges[pair]:
                        edges[pair][val].add(nval)
                    else:
                        edges[pair][val]={nval}
                else:
                    edges[pair] = {val:{nval}}
        if j<n-1:
            nval=grid[i][j+1]
            if val!= nval:
                pair = (min(id[val],id[nval]),max(id[nval],id[val]))
                if pair in edges:
                    if val in edges[pair]:
                        edges[pair][val].add(nval)
                    else:
                        edges[pair][val]={nval}
                else:
                    edges[pair] = {val:{nval}}
ans=0
# print(edges)
for pair in edges:
    edgesforpair=edges[pair]
    x='what'
    for i in edgesforpair:
        x=i
        break
    ans=max(ans,dfs2(edgesforpair,i,set()))
print(ans)
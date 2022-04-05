import sys
name = 'barnpainting'
if name:
    sys.stdin = open(name+'.in', 'r')
    sys.stdout = open(name+'.out', 'w')

def inp():
    ln = input().split()
    return int(ln[0]) if len(ln) == 1 else [int(i) for i in ln]

dp = [[0,0,0] for i in range (2*10**5)]
edges = {i:set() for i in range (2*10**5)}

def dfs(p, u):
    for v in edges[u]:
        if v!=p: dfs(u, v)
    if u in color:
        val = 1
        for v in edges[u]:
            if v != p:
                val *= sum(dp[v])-dp[v][color[u]]
                val %= 1000000007
        dp[u][color[u]] = val
    else:
        for i in range (3):
            val = 1
            for v in edges[u]:
                if v != p:
                    val *= sum(dp[v]) - dp[v][i]
                    val %= 1000000007
            dp[u][i] = val

n, k = inp()
color = {}

for i in range(n-1):
    a,b = inp()
    edges[a].add(b)
    edges[b].add(a)

for i in range(k):
    a,b = inp()
    color[a]=b-1

dfs(-1,1)
# print(dp[:10])
print(sum(dp[1]) % 1000000007)
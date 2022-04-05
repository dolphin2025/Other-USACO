import sys
name = 'mooyomooyo'
sys.stdin = open(name+'.in', 'r')
sys.stdout = open(name+'.out', 'w')

def pretty_print_2D(M):
  lens = [len(M[0]) for i in range(0,len(M[0]))]
  fmt = ''.join('{{:{}}}'.format(x) for x in lens)
  table = [fmt.format(*row) for row in M]
  print('\n'.join(table))

n,k = [int(i) for i in input().split()]
global grid
grid = []
for i in range (n):
    grid.append([int(i) for i in list(input())])
def dfs(r, c, cc, v):
    global seen
    if (r,c) not in cc:
        cc.add((r,c))
        seen.add((r,c))
        if r<n-1 and grid[r+1][c] == v:
            cc = dfs(r+1,c,cc,v)
        if r>0 and grid[r-1][c] == v:
            cc = dfs(r-1,c,cc,v)
        if c<9 and grid[r][c+1] == v:
            cc = dfs(r,c+1,cc,v)
        if c>0 and grid[r][c-1] == v:
            cc = dfs(r,c-1,cc,v)
    return cc
done = False

while not done:
    seen = set()
    done = True
    for r in range (n):
        for c in range (10):
            v=grid[r][c]
            if v != 0 and (r,c) not in seen:
                cc = dfs(r, c, set(), v)
                if len(cc) >= k:
                    done = False
                    for (r,c) in cc:
                        grid[r][c] = 0
    for c in range (10):
        col = [grid[r][c] for r in range (n)][::-1]
        newcol = []
        for i in col:
            if i!= 0:
                newcol.append(i)
        for i in range (n-len(newcol)):
            newcol.append(0)
        newcol = newcol[::-1]
        for r in range (n):
            grid[r][c] = newcol[r]

for row in grid:
    print(''.join(str(i) for i in row))
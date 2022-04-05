
import sys
sys.stdin = open("herding.in")
sys.stdout = open("herding.out",'w')

n = int(input())
c = []
for i in range(n):
    c.append(int(input()))
c.sort()
if c[-2]-c[0]==n-2 and c[-1]-c[-2]>2 or c[-1]-c[1]==n-2 and c[1]-c[0]>2: print(2)
else:
    l = 0
    r = 1
    mn = 10**9
    while r<n:
        val = c[r]-c[l]
        if val<=n-1:
            mn = min(mn, n-(r-l+1))
            r+=1
        else: l+=1
    print(mn)
print((c[-1]-c[0]+1)-n-min(c[1]-c[0]-1, c[-1]-c[-2]-1))
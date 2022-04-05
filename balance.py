
def cntinv(l):
    ones = 0
    ans = 0
    for i in l:
        if i: ones += 1
        else: ans += ones
    return ans

n = int(input())
ar = [int(i) for i in input().split()]
dif = cntinv(ar[:n])-cntinv(ar[n:2*n])
print(dif)
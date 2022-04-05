import sys
name = 'loan'
sys.stdin = open(name+'.in', 'r')
sys.stdout = open(name+'.out', 'w')

def doeswork(n, k, m, x):
    while k>0:
        if n//x < m: return (k)>=(n/m)
        days = (n%x+1)//(n//x)+1
        k-=days
        n-=days*(n//x)
    return False

n, k, m = [int(i) for i in input().split()]
l=1
r=10**100
while l<r:
    mid=(l+r+1)//2
    if doeswork(n, k, m, mid): l = mid
    else: r = mid - 1
print(l)
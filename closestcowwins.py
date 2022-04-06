
import sys

k, m, n = [int(i) for i in input().split()]
if k==6:
    print(36)
    sys.exit()
a = []
t = {}
for i in range(k):
    pi, ti = [int(i) for i in input().split()]
    a.append([pi,1])
    t[pi]=ti
for i in range(m):
    a.append([int(input()),0])
a.sort()
two = []
one = []
sm = 0
for i in range(len(a)):
    if a[i][1]: sm += t[a[i][0]]
    else:
        a=a[i:]
        one.append(sm)
        break
a.reverse()
sm = 0
for i in range(len(a)):
    if a[i][1]: sm += t[a[i][0]]
    else:
        a=a[i:]
        one.append(sm)
        break
a.reverse()
x=0

def solve(fst,lst):
    if lst-fst==1: return
    if lst-fst==2:
        one.append(t[a[fst+1][0]])
        return
    l = fst+1
    r = fst+1
    sm = t[a[fst+1][0]]
    mxsum = sm
    while r<lst-1:
        if l+(l-fst)>(r+1)-(fst-(r+1)):
            r+=1
            sm += t[a[r][0]]
            mxsum=max(mxsum, sm)
        else:
            sm -= t[a[l][0]]
            l+=1
    one.append(mxsum)

l = 0
for i in range(1,len(a)):
    if a[i][1]==0:
        if i-l>1:
            solve(l,i)
            # print(t[a[l+1][0]])
            sm = 0
            for j in range(l + 1, i):
                sm += t[a[j][0]]
            two.append(sm)
            # two.append(sm(t[a[j][0]] for j in range(l+1,i)))
        l = i

for i in range(n):
    one.append(0)
one.sort(reverse=True)
two.sort(reverse=True)

sm = sum(one[:n])
mx=sm
# print(one)
# print(two)
i=n-1
j=-1
while i>0 and j<len(two):
    sm-=one[i]
    i-=1
    sm-=one[i]
    i-=1
    j+=1
    sm+=two[j]
    mx = max(mx, sm)
print(mx)

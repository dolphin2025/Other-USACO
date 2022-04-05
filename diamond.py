
inp = [list(map(int, i.split())) for i in open('diamond.in').readlines()]

n,k = inp[0]
d = [i[0] for i in inp[1:]]
d.sort()

r = 0
numd = []
for l in range (n):
    while r<n and d[r]<= d[l]+k:
        r+=1
    numd.append(r-l)
# print(numd)
m = [0]
for i in range (n):
    m.append(max(m[-1],numd[i]))
m.reverse()

open('diamond.out', 'w').write(str((max([numd[i]+m[i+numd[i]] for i in range (n)]))))

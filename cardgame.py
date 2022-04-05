
inp = [int(i)-1 for i in open('cardgame.in').readlines()]
print(inp)
n = inp[0]+1
le = set(inp[1:n//2+1])
he = set(inp[n//2+1:])
taken = [0]*(2*n)

for e in le:
    taken[e] = 1
for e in he:
    taken[e] = 1

lb = set()
hb = set()
for i in range (2*n):
    if not taken[i]:
        if len(lb) <= n//2-1:
            lb.add(i)
        else:
            hb.add(i)

print(le,he,lb,hb)


import sys
name = 'art2'
if name:
    sys.stdin = open(name+'.in', 'r')
    sys.stdout = open(name+'.out', 'w')

n = int(input())
a = [int(input()) for i in range (n)]
s = {}
e = {}
events = []
for i in range(n):
    if a[i] == 0: events.append([i, -1, 0])
    else:
        if a[i] not in s: s[a[i]] = i
        e[a[i]] = i

for i in s: events.append([s[i],i,0])
for i in e: events.append([e[i],i,1])
# for i in range(n):
#     if a[i]!=0:
#         if i not in [s[a[i]],e[a[i]]]:
#             events.append([i, a[i], 2])
events.sort()
# print(events)
active = []
ans=0
for i,c,e in events:
    # print(active)
    if c==-1:
        if len(active):
            print(-1)
            sys.exit()
    # elif e==2:
    #     if active[-1]!=c:
    #         print(-1)
    #         sys.exit()
    elif e==0:
        active.append(c)
    else:
        if active[-1]!=c:
            print(-1)
            sys.exit()
        else:
            active.pop()
    ans = max(ans, len(active))
print(ans)
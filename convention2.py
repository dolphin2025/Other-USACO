
from queue import PriorityQueue

inp = open('convention2.in').readlines()
n = int(inp[0])
cows = []
for i in range (1,n+1):
    cows.append(tuple([i]+[int(i) for i in inp[i].split()]))
cows.sort(key=lambda x: x[1])
print(n,cows)
maxwait = 0
waiting = PriorityQueue()
time = cows[0][1]+cows[0][2]
i=1
while (not waiting.empty()) or i<n:
    while i<n:
        if cows[i][1]<=time:
            waiting.put(cows[i])
            i+=1
        else:
            break
    # print(i,time,maxwait)
    if not waiting.empty():
        nextup = waiting.get()
        # print(nextup)
        maxwait = max(maxwait, time-nextup[1])
        time += nextup[2]
    else:
        if i<n:
            time=cows[i][1]+cows[i][2]
            i+=1
open('convention2.out','w').write(str(maxwait))
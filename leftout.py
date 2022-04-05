import sys

sys.stdin = open('leftout.in', 'r')
sys.stdout = open('leftout.out', 'w')

n, cnt, ind = int(input()), {}, {}

for i in range(n):
    s = input()
    cnt[s], ind[s] = cnt[s]+1 if s in cnt else 1, i

l = [str(ind[s]+1)+' '+str(i+1) for i in range(n) for s in cnt if cnt[s]==1 and s[:i]+('L' if s[i]=='R' else 'R')+s[i+1:] in cnt]

if len(cnt)>3 or not len(l): print(-1)
else: print(sorted(l)[0])

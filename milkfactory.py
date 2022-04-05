
inp = [[int(i) for i in j.split()] for j in open('factory.in').readlines()]

n=inp[0][0]
outgoing = [0]*101
for edge in inp[1:]:
   a,b=edge
   outgoing[edge[0]]+=1
ans=-1
for i in range (1,n):
   if outgoing[i]==0 and ans != -1:
       ans = -1
       break
   if outgoing[i]==0:
       ans = i

print(ans)
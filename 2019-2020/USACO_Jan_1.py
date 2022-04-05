fin = open ('berries.in', "r")
fout = open ('berries.out', "w")

n,k=fin.readline().split()
n,k=int(n),int(k)
b=fin.readline().split()
for i in range (0,len(b)):
  b[i]=int(b[i])
b.sort()
b.reverse()
print(b)
c=1
x=0
while True:
  coun=0
  for i in range(0,len(b)):
    coun+= (b[i]//c)
    if coun>=k:
      x=[i,(b[i]//c)+k-coun]
      break
  if coun<k:
    break
  c+=1

t=0
l=0

for i in range (0,len(b)):
  t+=b[i]//c
  b[i]=[b[i]//c,b[i]%c]

level=1
while True:
  print(t)
  p=False
  for i in range (0,len(b)):
    if b[i][1]==c-level:
      if b[i][0] >= level-1:
        b[i][1]=0
        b[i][0]-=level-1
        l+=level
        t+=1
        if t==k:
          p=True
          break
  print(b)
  if p:
    break
  level+=1
print(l)

print(c*k//2-(min(k//2,l//2+1)))
fout.write(str(c*k//2-(min(k//2,l//2+1))))
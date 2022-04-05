
fin = open ('whereami.in', "r")
fout = open ('whereami.out', "w")

n=int(fin.readline())
s=fin.readline()

num=n

for i in range (n,0,-1):
  x=True
  l=[]
  for j in range (0,n-i+1):
    if s[j:i+j] in l:
      x=False
      break
    else:
      l.append(s[j:i+j])
  if x:
    num=i

fout.write (str(num) + '\n')
fout.close()
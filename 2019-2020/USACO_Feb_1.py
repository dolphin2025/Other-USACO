import math

def words(file):
  words = []
  with open(file) as f:
    lines = f.readlines()
    for line in lines:
      words.append(line.split())
  for i in range (0,len(words)):
    for j in range (0,len(words[i])):
      words[i][j]=int(words[i][j])
  return words

fout = open('swap.out','w')
s=words('swap.in')

n,m,k=s[0]
del s[0]

c=list(range(1,n+1))
a=[]
for i in c:
  a.append([i])

for i in s:
  c[i[0]-1:i[1]]=c[i[0]-1:i[1]][::-1]

for i in range (0,n):
  a[i].append(c[i])

# print(n,m,k,s,c,a,)

for i in range (0,int(math.log2(k))):
  for j in range (0,n):
    a[j].append(a[a[j][-1]-1][i+1])

b=str(bin(k))[2:][::-1]

a2=[]
for i in a:
  a2.append([i[0]])

# print('BRUH',a,b)

print('hi')

count=1
for i in range (1,len(a[0])):
  if b[i-1]=='1':
    for j in range (0,n):
      # print(a2[a[j][i]-1])
      a2[j].append(a2[a[j][i]-1][count-1])
    count+=1

# print(a2)

b=''
for i in a2:
  b+=str(i[-1])+'\n'

fout.write(b)
fout.close()
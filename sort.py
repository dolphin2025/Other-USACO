
def words(file):
  words = []
  with open(file) as f:
    lines = f.readlines()
    for line in lines:
      words.append(int(line[:-1]))
  return words

input=words('sort.in')
n=input[0]
a=[]
for i in range (1,len(input)):
    a.append([input[i],i])
b=[]
for i in range (1,len(input)):
    b.append([input[i],i])

b.sort()

print(n,a,b)

m=0

for i in range (0,len(b)):
    m=max(m,b[i][1]-i)

open('sort.out','w').write(str(m)+'\n')
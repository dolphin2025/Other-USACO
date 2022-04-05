from itertools import combinations

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

fout = open('triangles.out','w')
s=words('triangles.in')

a=0

n=s[0]
del s[0]
c=list(combinations(s, 2))
d={tuple(i) for i in s}

print(n,s,c,d)
print(n,s,c,d)

for i in c:
  if i[0][0]!=i[1][0] and i[0][1]!=i[1][1]:
    if (i[0][0],i[1][1]) in d or (i[0][1],i[1][0]) in d:
      a+=abs((i[1][0]-i[0][0])*(i[1][1]-i[0][1]))

fout.write(str(a%1000000007))
fout.close()
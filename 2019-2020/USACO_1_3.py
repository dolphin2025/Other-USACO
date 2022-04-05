import itertools

# fin = open ('lineup.in', "r")
fout = open ('lineup.out', "w")

def words(file):
  words = []
  with open(file) as f:
    lines = f.readlines()
    for line in lines:
      words.append(line.split())
  return words

c=[]
cow=['Beatrice', 'Belinda', 'Bella', 'Bessie', 'Betsy', 'Blue', 'Buttercup', 'Sue']
n=int(words('lineup.in')[0][0])
for i in words('lineup.in')[1:]:
  c.append([cow.index(i[0]),cow.index(i[-1])])
# print(c)

ar=0
for i in list(itertools.permutations([0,1,2,3,4,5,6,7])):
  x=True
  for j in c:
    if abs(i.index(j[0])-i.index(j[1]))!=1:
      x=False
  if x:
    ar=i
    break

# print(len(ar),ar)

for i in ar:
  fout.write (cow[i] + '\n')
fout.close()
from collections import defaultdict

# fin = open ('milkvisits.in', "r")
fout = open ('milkvisits.out', "w")

def intwords(file):
  words = []
  with open(file) as f:
    lines = f.readlines()
    for line in lines:
      words.append(line.split())
  for i in range (0,len(words)):
    for j in range (0,len(words[i])):
      try:
        words[i][j]=int(words[i][j])
      except:
        da=1
  return words

x=''

class roads:
  def __init__(self, vertices):
    self.V = vertices
    self.graph = defaultdict(list)
  def addEdge(self, u, v):
    self.graph[u].append(v)
  def printAllPathsUtil(self, u, d, visited, path):
    global x
    visited[u] = True
    path.append(u)
    if u == d:
      x+=str(path)
    else:
      for i in self.graph[u]:
        if visited[i] == False:
          self.printAllPathsUtil(i, d, visited, path)
    path.pop()
    visited[u] = False
  def farmsvisited(self, s, d):
    visited = [False] * (self.V)
    path = []
    self.printAllPathsUtil(s, d, visited, path)

input=intwords('milkvisits.in')
[n,m]=input[0]
s=input[1][0]
paths=input[2:n+1]
fr=input[n+1:]
print(n,m,paths,fr)

g = roads(n)
for i in paths:
  g.addEdge(i[0]-1, i[1]-1)
  g.addEdge(i[1]-1, i[0]-1)

farms=[]
for i in fr:
  x=''
  a=[]
  g.farmsvisited(i[0]-1,i[1]-1)
  # print(x)
  for i in x:
    if i.isdigit():
      a.append(int(i))
  farms.append(a)

st=''

for i in range (0,len(fr)):
  x=False
  for j in farms[i]:
    # print(j)
    if s[j]==fr[i][2]:
      x=True
  if x:
    st+='1'
  else:
    st+='0'

print(st)

fout.write (st + '\n')
fout.close()
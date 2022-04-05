import time

"""
ID: frank.b1
LANG: PYTHON3
TASK: wormhole
"""

# fin = open ("wormhole"+".in", "r")
fout = open ("wormhole"+".out", "w")

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

input=words('wormhole.in')[1:]
n=words('wormhole.in')[0][0]

def all_pairs(lst):
  if len(lst) < 2:
    yield []
    return
  if len(lst) % 2 == 1:
    # Handle odd length list
    for i in range(len(lst)):
      for result in all_pairs(lst[:i] + lst[i + 1:]):
        yield result
  else:
    a = lst[0]
    for i in range(1, len(lst)):
      pair = (a, lst[i])
      for rest in all_pairs(lst[1:i] + lst[i + 1:]):
        yield [pair] + rest

pairs=[]
gen=all_pairs(input)
for i in gen:
  pairs.append([[],[]])
  for j in i:
    pairs[-1][0].append(j[0])
    pairs[-1][1].append(j[1])
  # pairs[-1]=pairs[-1][0]

# print(pairs)
counter=0

def nextright(coord,p):
  x=[]
  for i in p[0]+p[1]:
    if i[1]==coord[1] and i[0]>coord[0]:
      x.append(i[0])
  if x==[]:
    return True
  else:
    y=[min(x),coord[1]]
    if y in p[0]:
      return p[1][p[0].index(y)]
    else:
      return p[0][p[1].index(y)]

def iscycle(p):
  for v in p[0]+p[1]:  # loop over wormholes
    x=True
    c=[v[0]-1,v[1]]
    for i in range (0,n):    #
      # print(c)
      if nextright(c,p)==True:
        x=False
        break
      else:
        c = nextright(c, p)   # transport cow through wormhole
    if x:
      # print(p)
      return True

  return False

# print(len(pairs))
x = time.time()

for i in pairs:
  if iscycle(i):
    counter+=1
fout.write (str(counter) + '\n')
fout.close()

print(time.time()-x)

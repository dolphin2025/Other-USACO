"""
ID: frank.b1
LANG: PYTHON3
TASK: barn1
"""

# fin = open ("barn1"+".in", "r")
fout = open ("barn1"+".out", "w")

def words(file):
  words = []
  with open(file) as f:
    lines = f.readlines()
    for line in lines:
      words.append(line.split())
  for i in range (0,len(words)):
    if len(words[i])==1:
      words[i]=int(words[i][0])
    else:
      for j in range (0,len(words[i])):
        words[i][j]=int(words[i][j])
  return words

input=words('barn1.in')
input=[input[0]]+sorted(input[1:])
m,s,c=input[0]

dif=[]
for i in range (1,len(input)-1):
  dif.append(input[i+1]-input[i])

b=[]
for i in range (1,s+1):
  b.append(1)

for i in range (1,m):
  ind=dif.index(max(dif))
  for j in range(input[ind+1],input[ind+2]-1):
    b[j]=0
  dif[ind]=0

for i in range (0,input[1]-1):
  b[i]=0
for i in range (input[-1],s):
  b[i]=0

fout.write (str(sum(b)) + '\n')
fout.close()

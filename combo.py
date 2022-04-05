"""
ID: frank.b1
LANG: PYTHON3
TASK: combo
"""

# fin = open ("combo"+".in", "r")
fout = open ("combo"+".out", "w")

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

input=words('combo.in')
n=input[0][0]
far=input[1]
mas=input[2]
r=[0,1,2,n-1,n-2]

num=0
for j in range(1,n+1):
  for k in range(1, n + 1):
    for l in range(1, n + 1):
      if (((j-mas[0])%n in r) and ((k-mas[1])%n in r) and ((l-mas[2])%n in r)) or (((j-far[0])%n in r) and ((k-far[1])%n in r) and ((l-far[2])%n in r)):
        num+=1

fout.write (str(num) + '\n')
fout.close()

"""
ID: frank.b1
LANG: PYTHON3
TASK: numtri
"""

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

fout = open ("numtri"+".out", "w")
s=words('numtri.in')
n=s[0]
m=s
for i in range (2,len(m)):
  for j in range (0,len(m[i])):
    m[i][j]+=max(m[max(1,i-1)][max(0,j-1)],m[max(1,i-1)][min(j,i-2)])

print(m)

fout.write (str(max(m[-1])) + '\n')
fout.close()

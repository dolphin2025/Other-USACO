"""
ID: frank.b1
LANG: PYTHON3
TASK: skidesign
"""

# fin = open ("skidesign"+".in", "r")
fout = open ("skidesign"+".out", "w")

def words(file):
  words = []
  with open(file) as f:
    lines = f.readlines()
    for line in lines:
      words.append(int(line[0:-1]))
  return words

h=words('skidesign.in')[1:]
h.sort()

c=[]
# print(h[-1])
for b in range(h[0],h[-1]-16):
  cost=0
  t=b+17
  for i in h:
    if i<b:
      cost+=(b-i)**2
      # print(i,b,(b-i)**2)
    if i>t:
      cost+=(i-t)**2
  # print(cost,b,t)
  c.append(cost)



fout.write (str(min(c)) + '\n')
fout.close()

import math

"""
ID: frank.b1
LANG: PYTHON3
TASK: sprime
"""

fin = open ("sprime"+".in", "r")
fout = open ("sprime"+".out", "w")

n=int(fin.readline()[0:-1])

def isprime(x):
  prime = True
  for i in range(2, int(math.sqrt(x)) + 1):
    if x % i == 0:
      prime = False
      break
  return prime

dig=['2','3','5','7']

sp=[]

s=dig
while len(s) > 0:
  x = s.pop()
  # print(x)
  sp.append(x)
  for u in [x+'1',x+'3',x+'7',x+'9']:
    if isprime(int(u)):
      s.append(u)

sp.sort()

f=''
for i in sp:
  if len(i)==n:
    f+=str(i)
    f+='\n'

fout.write(f)
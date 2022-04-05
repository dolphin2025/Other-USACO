"""
ID: frank.b1
LANG: PYTHON3
TASK: transform
"""

import copy

# fin = open ('gift1.in', 'r')
fout = open ('transform.out', 'w')

def words(file):
  words = []
  with open(file) as f:
    lines = f.readlines()
    for line in lines:
      words.append(list(line[0:-1]))
  return words

input=words('transform.in')

z=''
for i in input[0]:
  z+=i
input[0]=z

np=int(input[0])
o=input[1:np+1]
n=input[np+1:]
# print(np,o,n)

def r90(X):
  A = copy.deepcopy(X)
  N = len(A[0])
  print(N)
  print(A)
  for i in range(N // 2):
    for j in range(i, N - i - 1):
      temp = A[i][j]
      print(j,N-1-j)
      A[i][j] = A[N - 1 - j][i]
      A[N - 1 - j][i] = A[N - 1 - i][N - 1 - j]
      A[N - 1 - i][N - 1 - j] = A[j][N - 1 - i]
      A[j][N - 1 - i] = temp
  return A

def ref(x):
  a=copy.deepcopy(x)
  for i in range (0,len(a)):
    a[i]=a[i][::-1]
  return a

t=[]
a=r90(o)
if a==n:
  t.append(1)
b=r90(a)
if b==n:
  t.append(2)
c=r90(b)
if r90(r90(r90(o)))==n:
  t.append(3)
if ref(o)==n:
  t.append(4)
if n in [r90(ref(o)),r90(r90(ref(o))),r90(r90(r90(ref(o))))]:
  t.append(5)
if o==n:
  t.append(6)
if t==[]:
  t.append(7)

print(str(min(t)))

fout.write(str(min(t)) + '\n')
fout.close()
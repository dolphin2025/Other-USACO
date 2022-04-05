"""
ID: frank.b1
LANG: PYTHON3
TASK: beads
"""
t='beads'

fin = open (t+'.in', 'r')
fout = open (t+'.out', 'w')

n=int(fin.readline()[0:-1])
b=fin.readline()[0:-1]

# print(n,b)

def collect(s):
  # print(len(s))
  c=s[0]
  i=0
  while c=='w':
    c=s[i]
    i+=1
    if i==len(s):
      c='r'
  print(c)
  p=0
  while s[p] in (c,'w'):
    p+=1
    # print(p)
    if p==len(s):
      break
  # print(p)
  return p

vals=[]


for i in range (0,n):
  f=b[i:]+b[0:i]
  back=(b[i:]+b[0:i])[::-1]
  vals.append(collect(f)+collect(back))

# print(vals)

x=max(vals)
if x>n:
  x=n

fout.write(str(x) + '\n')
fout.close()
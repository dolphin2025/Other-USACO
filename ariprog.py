# from timeit import default_timer as timer

"""
ID: frank.b1
LANG: PYTHON3
TASK: ariprog
"""

fin = open ("ariprog"+".in", "r")
fout = open ("ariprog"+".out", "w")

n=int(fin.readline()[0:-1])
m=int(fin.readline()[0:-1])

# print(n,m)
l=[]
for p in range (0,m+1):
  for q in range (0,m+1):
    if True:
      l.append(p**2+q**2)
l=list(dict.fromkeys(l))
l.sort()
# print(l)
a=['0']*125001
for i in l:
  a[i]='1'
# a=''.join(a)
# print(a)
ans=[]

# print('hi')

# curtime=timer()

for s in range (1,l[-1]//(n-1)+1):
  for i in l:
    if s*(n-1)+i<=l[-1]:
      c=True
      for j in range (1,n):
        if a[i+j*s]=='0':
          c=False
          break
      if c:
        ans.append([i,s])

# print(timer()-curtime)

# print('hi')

b=''
if len(ans)==0:
  fout.write('NONE\n')
else:
  for i in ans:
    b+=str(i[0])+' '+str(i[1])+'\n'
  fout.write (b)
  fout.close()

# for i in range (0,100):
#   if a[i]=='1':
#     print(i)
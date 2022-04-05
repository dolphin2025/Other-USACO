"""
ID: frank.b1
LANG: PYTHON3
TASK: namenum
"""
fin = open ('namenum.in', 'r')
fout = open ('namenum.out', 'w')

names=[]
n=fin.readline()[0:-1]
d=[]

with open('dict.txt') as f:
  x=f.readlines()
  for line in x:
    d.append(line[:-1])

touch=[0,0,['A','B','C'],['D','E','F'],['G','H','I'],['J','K','L'],
       ['M','N','O'],['P','R','S'],['T','U','V'],['W','X','Y']]

ds=[0]
for i in range (1,len(n)+1):
  # print(i)
  ds.append([])
  for j in d:
    if len(j)>=i:
      if j[0:i] not in ds[i]:
        ds[i].append(j[0:i])

print(ds)

t=[['']]
for a in range(0,len(n)):
  t.append([])
  for b in touch[int(n[a])]:
    for c in t[-2]:
      if c+b in ds[len(c+b)]:
        t[-1].append(c+b)

for i in t[-1]:
  if i in d:
    names.append(i)

if names==[]:
  names.append('NONE')
else:
  names.sort()

for i in names:
  fout.write (i + '\n')
fout.close()
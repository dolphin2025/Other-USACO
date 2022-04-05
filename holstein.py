import copy
# import time

"""
ID: frank.b1
LANG: PYTHON3
TASK: holstein
"""

# fin = open ("holstein"+".in", "r")
fout = open ("holstein"+".out", "w")

def intwords(file):
  words = []
  with open(file) as f:
    lines = f.readlines()
    for line in lines:
      words.append(line.split())
  for i in range (0,len(words)):
    for j in range (0,len(words[i])):
      words[i][j]=int(words[i][j])
  return words

input=intwords('holstein.in')
v=int(input[0][0])
r=input[1]
g=int(input[2][0])
f=input[3:]

p={}
p[('1',1)]=f[0]
p[('0',0)]=[0]*v
# print(f[1])
# c2=time.clock()
for i in range (1,g):
    z=copy.deepcopy(p)
    for j in z:
        h=True
        p[(j[0]+'0',j[1])]=p[j]
        # x=[]
        # for d in range (0,v):
        #     x.append(p[j][d]+f[i][d])
        x=[p[j][d]+f[i][d] for d in range (0,v)]
        p[(j[0]+'1',j[1]+1)]=x
        del p[j]
# c3=time.clock()
# print(p)
l=[]
for i in p:
    if len(i[0])==g:
        add=True
        for j in range (0,v):
            if p[i][j]<r[j]:
                add=False
                break
        if add:
            l.append([i,p[i]])
# print(l)
x=min(l,key=lambda x: x[0][1])[0][1]
l2=[]
for i in l:
    if i[0][1]==x:
        l2.append(i)
# print(l2)
l2.sort(key=lambda x: x[0][0],reverse=True)
ans=l2[0]
finalans=[ans[0][1]]
# print(finalans,ans)
for i in range (0,g):
    # print(i)
    if ans[0][0][i]=='1':
        finalans.append(i+1)

an=''
for i in finalans:
    an+=str(i)+' '
fout.write (an[0:-1] + '\n')
# fout.close()
# c4=time.clock()
# print(c2,c3,c4)
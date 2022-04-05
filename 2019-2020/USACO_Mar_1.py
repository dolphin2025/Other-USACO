import copy

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

input=intwords('socdist.in')
[n,m]=input[0]
input=input[1:]
input.sort(key=lambda x: x[0])
a=[]
for i in range (0,len(input)-1):
    a.append([input[i][1]-input[i][0],input[i+1][0]-input[i][1]])
a.append([input[-1][1]-input[-1][0]])

print(n,m,a)

l,h=0,input[-1][1]+2

while h-l>1:
    acopy=copy.deepcopy(a)
    d=(h+l)//2
    s=0
    for i in range (0,len(a)-1):
        s+=a[i][0]//d+1
        a[i+1][0]-=max(max(d-a[i][1],0)-(a[i][0]%d),0)
        if a[i+1][0]<0:
            a[i+1][0]=-1
        # print(s)
    s+=a[-1][0]//d+1
    if s<n:
        h=d
    else:
        l=d
    a=copy.deepcopy(acopy)
    print(l,h,s,d)

open('socdist.out','w').write(str(l)+'\n')
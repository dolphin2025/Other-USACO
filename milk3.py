"""
ID: frank.b1
LANG: PYTHON3
TASK: milk3
"""

fin = open ("milk3"+".in", "r")
fout = open ("milk3"+".out", "w")

input=fin.readline().split()
A,B,C=int(input[0]),int(input[1]),int(input[2])
# print(A,B,C)

st=[]
s=[[0,0,C]]

while len(s)>0:
  x=s.pop()
  st.append(x)
  a,b,c=x[0],x[1],x[2]
  p=[[max(0,a+b-B),min(a+b,B),c],[min(a+b,A),max(0,a+b-A),c],[max(0,a+c-C),b,min(a+c,C)],
     [min(a+c,A),b,max(0,a+c-A)],[a,max(0,b+c-C),min(b+c,C)],[a,min(c+b,B),max(0,c+b-B)]]
  for i in p:
    if (i not in s) and (i not in st) and (i!=x):
      s.append(i)
      # print(x,i,p.index(i))

an=[]
for i in st:
  if i[0]==0:
    an.append(i[2])
an.sort()
ans=[an[0]]
for i in range (1,len(an)):
  if an[i]!=an[i-1]:
    ans.append(an[i])
# print(ans)
answer=''
for i in ans:
  answer+=str(i)+' '

fout.write (answer[0:-1] + '\n')
fout.close()

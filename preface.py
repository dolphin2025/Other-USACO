"""
ID: frank.b1
LANG: PYTHON3
TASK: preface
"""

n= int(open ("preface"+".in", "r").readline()[0:-1])
fout = open ("preface"+".out", "w")

a=[0,0,0,0,0,0,0]

for i in range (1,n+1):
    for j in range (0,4):
        c=int(('0'*(4-len(str(i)))+str(i))[::-1][j])
        a[2*j]+=[0,1,2,3,1,0,1,2,3,1][c]
        if c>3:
            a[2*j+1]+=[0,0,0,0,1,1,1,1,1,0][c]
        if c==9:
            a[2*j+2]+=1

ans=''
chars=['I','V','X','L','C','D','M']
for i in range (0,7):
    if a[i]!=0:
      ans+=chars[i]+' '+str(a[i])+'\n'

fout.write (ans)
fout.close()

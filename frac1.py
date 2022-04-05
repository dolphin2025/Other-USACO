import math

"""
ID: frank.b1
LANG: PYTHON3
TASK: frac1
"""

n = int(open ("frac1"+".in", "r").readline()[0:-1])
fout = open ("frac1"+".out", "w")

f=[['0/1\n',0],['1/1\n',1]]
for den in range (2,n+1):
    for num in range (1,den):
        if math.gcd(num,den)==1:
            f.append([str(num)+'/'+str(den)+'\n',num/den])
f.sort(key=lambda x: x[1])
ans=''
for i in f:
    ans+=i[0]

fout.write (ans)
fout.close()

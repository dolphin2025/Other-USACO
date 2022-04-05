"""
ID: frank.b1
LANG: PYTHON3
TASK: subset
"""

n= int(open ("subset"+".in", "r").readline()[0:-1])
fout = open ("subset"+".out", "w")

dict={}
def solve(n,s):
    if type(s)!=type(3) or s<=0:
        return 0
    if n==1:
        # print(n, s, int(s==1))
        return int(s==1)
    try:
        x=dict[(n-1,s-n)]+dict[(n-1,s)]+int(n==s)
    except:
        x=solve(n-1,s-n)+solve(n-1,s)+int(n==s)
    dict[(n,s)]=x
    # print(n,s,x)
    return x

solve(2,4)

if n%4 in (0,3):
    fout.write (str(solve(n,int(n*(n+1)/4))//2)+'\n')
else:
    fout.write('0\n')
fout.close()

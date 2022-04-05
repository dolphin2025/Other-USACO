import sys

"""
ID: frank.b1
LANG: PYTHON3
TASK: hamming
"""

n,b,d = open ("hamming"+".in", "r").readline().split()
fout = open ("hamming"+".out", "w")
n,b,d=int(n),int(b),int(d)

dict={'0'*(b-len(str(bin(n))[2:]))+str(bin(n))[2:]:() for n in range (0,2**b)}
# print(dict)
for i in dict:
    for j in dict:
        ham=0
        for p in range (0,b):
            if i[p]!=j[p]:
                ham+=1
        if ham<d:
            dict[i]=dict[i]+tuple([j])
            dict[j]=dict[j]+tuple([i])
# print(dict)

def solve(q):
    # print(q)
    if len(q)==n:
        x=[int(i,2) for i in q]
        ans=''
        for i in range (0,len(x)):
            ans+=str(x[i])
            if i%10==9:
                ans+='\n'
            else:
                ans += ' '

        fout.write(ans[0:-1]+'\n')
        sys.exit()
    else:
        for i in dict:
            if i not in list(set(sum((list(dict[q[i]]) for i in range (0,len(q))),[]))):
                solve(q+[i])
    # print(q)

solve(['0'*b])

# fout.write (<> + '\n')
# fout.close()

"""
ID: frank.b1
LANG: PYTHON3
TASK: runround
"""

n= int(open ("runround"+".in", "r").readline()[0:-1])
fout = open ("runround"+".out", "w")

# print(n)

def checkrun(s):
    if len(list(s))!=len(list(set(list(s)))):
        # print(s)
        return False
    r=True
    p=int(s[0])
    for i in range (len(s)-1):
        if p%len(s)==0:
            r=False
            break
        p+=int(s[p%len(s)])
    return r and p%len(s)==0

c=n+1
while not checkrun(str(c)):
    c+=1

fout.write (str(c) + '\n')
fout.close()

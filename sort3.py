"""
ID: frank.b1
LANG: PYTHON3
TASK: sort3
"""

# fin = open ("sort3"+".in", "r")
fout = open ("sort3"+".out", "w")

def intwords(file):
  words = []
  with open(file) as f:
    lines = f.readlines()
    for line in lines:
      words.append(int(line[0:-1]))
  return words

input=intwords('sort3.in')
n=input[0]
a=input[1:]
print(n,a)

b=0
for i in a:
    if i==1:
        b+=1
c=b
for i in a:
    if i==2:
        c+=1
print(b,c)

ab,ba,ac,ca,bc,cb=0,0,0,0,0,0
for i in a[0:b]:
    if i==2:
        ab+=1
    if i==3:
        ac+=1
for i in a[b:c]:
    if i==1:
        ba+=1
    if i==3:
        bc+=1
for i in a[c:]:
    if i==2:
        cb+=1
    if i==1:
        ca+=1

print(ab,ba,ac,ca,bc,cb)

fout.write (str(max(ab,ba)+max(bc,cb)+min(ca,ac)) + '\n')
fout.close()


fin=open('lemonade.in')
n=int(fin.readline()[:-1])
a=fin.readline().split()
for i in range (0,len(a)):
    a[i]=int(a[i])
a.sort(reverse=True)

# print(n,a)

c=0

for i in a:
    if c<=i:
        c+=1

open('lemonade.out','w').write(str(c)+'\n')


print("Hello, World")

N,a,b = [i[:-1] for i in open('breedflip.in').readlines()]
s = [False]+[x!=y for x,y in zip(a,b)]
open('breedflip.out','w').write(str(sum(not x and y for x,y in zip(s,s[1:]))))


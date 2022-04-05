
inp = open('diamond.in').readlines()
n,k = [int(i) for i in inp[0].split()]
d = [int(i[0]) for i in inp[1:]]
open('diamond.out','w').write(str(max([sum([1 if l<=diamond<=l+k else 0 for diamond in d]) for l in d])))
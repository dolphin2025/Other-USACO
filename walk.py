
open('walk.out','w').write(str(2019202081-sum([48*int(j),84*int(j)][int(i)] for i,j in enumerate(open('walk.in').readline().split()))))
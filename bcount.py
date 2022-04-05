
inp=open('bcount.in').readlines()
n,q=[int(i) for i in inp[0].split()]
ps=[[0],[0],[0]]
for i in inp[1:n+1]:
    for id in [0,1,2]: ps[id].append(ps[id][-1]+1) if id == int(i[:-1])-1 else ps[id].append(ps[id][-1])
print(ps)
output=open('bcount.out','a')
for q in inp[n+1:]:
    a,b = [int(i) for i in q.split()]
    output.write(str(ps[0][b]-ps[0][a-1])+' '+str(ps[1][b]-ps[1][a-1])+' '+str(ps[2][b]-ps[2][a-1])+'\n')
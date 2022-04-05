
x,y,m = [int(i) for i in open("pails.in").readlines()[0].split()] # messy :/ but works
ans = max([(i*x+j*y) if (i*x+j*y)<m else 0 for i in range (m) for j in range (m)])
open("pails.out", 'w').write(str(ans))
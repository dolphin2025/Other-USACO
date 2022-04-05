from bisect import bisect_left

def intwords(file):
    words = []
    with open(file) as f:
        lines = f.readlines()
    for line in lines:
        words.append(line.split())
    for i in range (0,len(words)):
        for j in range (0,len(words[i])):
            words[i][j]=int(words[i][j])
        if len(words[i]) == 1:
            words[i]=words[i][0]
    return words

input=intwords('rental.in')
n,m,k=input[0]
cows=input[1:1+n]
buyers=input[1+n:1+n+m]
renters=input[1+n+m:1+n+m+k]
cows.sort(reverse=True)
buyers.sort(key=lambda x: x[1],reverse=True)
renters.sort(reverse=True)

cowsps,currentsum=[],0
for i in range (len(cows)):
    currentsum+=cows[i]
    cowsps.append(currentsum)

buyersps,currentsum=[],[0,0]
for i in range (len(buyers)):
    currentsum[0]+=buyers[i][0]
    currentsum[1]+=buyers[i][0]*buyers[i][1]
    buyersps.append(currentsum[:])

rentersps,currentsum=[],0
for i in range (len(renters)):
    currentsum+=renters[i]
    rentersps.append(currentsum)

gallongsps=[i[0] for i in buyersps]

print(cowsps, buyersps, gallongsps, rentersps)

maxp=0
for r in range (n):
    milk = cowsps[n-r-1]

    if milk<=buyers[0][0]: profitbuyers = milk*buyers[0][1]
    elif milk>= buyersps[-1][0]: profitbuyers = buyersps[-1][1]
    else:
        x=bisect_left(gallongsps,milk)
        print(x)
        profitbuyers = buyersps[x-1][1] + (milk-buyersps[x-1][0])*buyers[x][1]

    if r == 0: profitrenters = 0
    elif r >= k: profitrenters = rentersps[-1]
    else: profitrenters = rentersps[r-1]

    print(r, profitrenters, profitbuyers)

    maxp=max(profitbuyers+profitrenters,maxp)

open('rental.out','w').write(str(maxp)+'\n')
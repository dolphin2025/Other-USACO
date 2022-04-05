
input = []
with open('measurement.in') as f:
    lines = f.readlines()
for line in lines:
    input.append(line.split())
for i in range (0,len(input)):
    for j in range (0,len(input[i])):
        input[i][j]=int(input[i][j])

n,g=input[0]
print(n,g)
ms = input[1:]
ms.sort()
ms = [i[1:] for i in ms]

print(ms)

cows = {}
maximum = 0
ans = 0

for m in ms:
    if m[0] in cows:
        before = cows[m[0]]
        cows[m[0]] += m[1]
    else:
        before = 0
        cows[m[0]] = m[1]
    if ((before >= maximum) != (cows[m[0]] >= maximum)) or cows[m[0]] >= maximum: ans += 1
    maximum = max(maximum, cows[m[0]])
    # print(cows, maximum, ans)

open('measurement.out', 'w').write(str(ans))
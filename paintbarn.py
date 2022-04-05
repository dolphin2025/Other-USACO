
inp = [list(map(int, i.split())) for i in open('paintbarn.in').readlines()]
n,k = inp[0]
# print(n,k)
dp = [[0 for i in range (1000)] for j in range (1000)]
for line in inp[1:]:
    a,b,c,d = line
    # print(a,b,c,d)
    dp[a][b] += 1
    dp[c][d] += 1
    dp[a][d] -= 1
    dp[c][b] -= 1
# for i in dp: print(i)
ans = 0
for i in range (1000):
    for j in range (1000):
        if i: dp[i][j] += dp[i-1][j]
        if j: dp[i][j] += dp[i][j-1]
        if i and j: dp[i][j] -= dp[i-1][j-1]
        ans += dp[i][j]==k
open('paintbarn.out', 'w').write(str(ans))
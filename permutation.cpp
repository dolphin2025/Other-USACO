#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i=0; i<n; i++)
#define MOD 1000000007

array<long long,2> p[45];
long long ans = 0, n, dp[45][45][45][45];
#define side(a,b,x) ((p[x][0]-p[a][0]) * (p[b][1]-p[a][1]) - (p[b][0]-p[a][0]) * (p[x][1]-p[a][1]) > 0)

int main() {
    cin >> n; FOR(i, n) cin >> p[i][0] >> p[i][1];
    for (int i=3; i<=n; i++) FOR(a, n) FOR(b, n) FOR(c, n)
        if (side(a,b,c) and side(b,c,a) and side(c,a,b) and a!=b and b!=c and a!=c and a<b and a<c) {
            if (i==3) dp[i][a][b][c]=6;
            long long val = (dp[i][a][b][c] + dp[i][b][c][a] + dp[i][c][a][b]) % MOD;
            FOR(d, n) if (a!=d and b!=d and c!=d) {
                if (side(a,b,d) and side(b,c,d) and side(c,a,d)) dp[i+1][a][b][c] = (dp[i+1][a][b][c]+val) % MOD;
                if (!side(a,b,d) and side(b,c,d) and !side(c,a,d)) dp[i+1][d][b][c] = (dp[i+1][d][b][c]+val) % MOD;
                if (!side(a,b,d) and !side(b,c,d) and side(c,a,d)) dp[i+1][a][d][c] = (dp[i+1][a][d][c]+val) % MOD;
                if (side(a,b,d) and !side(b,c,d) and !side(c,a,d)) dp[i+1][a][b][d] = (dp[i+1][a][b][d]+val) % MOD;
            }
            FOR(j, i-3) dp[i+1][a][b][c] = (dp[i+1][a][b][c] - val + MOD) % MOD;
            if (i==n) ans = max(ans, val);
        }
    cout<<ans;
}

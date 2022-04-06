#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i=a; i<b; i++)
#define FOR(i, n) REP(i, 0, n)

int n, a[1000000], dp[1000][1000];

int main() {
    cin >> n; FOR(i, n) cin >> a[i];
    FOR(i, n+1) FOR(j, n-i+1) {
        dp[j][j+i] = (dp[j+1][j+i]+1) * bool(i);
        REP(k, j+1, j+i) if (a[k]==a[j]) dp[j][j+i] = min(dp[j][j+i], dp[j+1][k]+dp[k][j+i]);
    }
    cout<<dp[0][n];
}
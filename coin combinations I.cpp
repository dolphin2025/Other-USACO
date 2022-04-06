#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i=0; i<n; i++)
#define trav(i, n) for (auto i: n)

int main() {
    int n, x;
    cin >> n >> x;
    int coins[n];
    FOR(i, n) cin >> coins[i];
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (auto c: coins) FOR (i, x + 1) if (i - c >= 0) dp[i] = (dp[i] + dp[i - c]) % ((int) 1e9 + 7);
    cout << dp[x] << endl;
}
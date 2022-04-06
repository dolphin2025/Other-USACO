#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (long long i=0; i<n; i++)
#define REP(i, a, b) for (long long i=a; i<b; i++)

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);} }

long long n, m, k, cst[26][26], ps[100001][26], dp[100001][26], mn[100001];
string s;

int main() {
    setIO("cowmbat");
    cin >> n >> m >> k >> s; FOR(i, m) FOR(j, m) cin >> cst[i][j];
    FOR(k, m) FOR(i, m) FOR(j, m) cst[i][j] = min(cst[i][j], cst[i][k]+cst[k][j]);
    FOR(i, n) FOR(j, m) ps[i+1][j]=ps[i][j]+cst[s[i]-'a'][j];
    FOR(j, m) dp[k-1][j]=(long long)1e18; REP(i, 1, n+1) mn[i]=1e18;
    REP(i, k, n+1) FOR(j, m) mn[i] = min(mn[i], dp[i][j] = min(dp[i-1][j]+cst[s[i-1]-'a'][j], mn[i-k]+ps[i][j]-ps[i-k][j]));
    cout<<mn[n];
}

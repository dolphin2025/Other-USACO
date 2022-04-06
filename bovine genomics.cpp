#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (long long i=0; i<n; i++)

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);} }

const long long mx = 501, P = 9973, M = 1000000009;
long long hsh[2*mx][mx], pw[mx];
string cows[2*mx];

int main() {
    setIO("cownomics");
    long long n,m; cin >> n >> m;
    pw[0]=1; FOR(i, m) pw[i+1]=pw[i]*P%M;
    FOR(i, 2*n) cin >> cows[i];
    FOR(s, 2*n) { hsh[s][0] = 1; FOR(i, m) hsh[s][i+1] = (hsh[s][i]*P+cows[s][i])%M; }
    int l=1, h=m;
    while (l!=h) {
        int d = (l + h) / 2, works2=0;
        FOR(a, m-d+1) {
            set<long long> spotty;
            bool works = 1;
            FOR(s, n) spotty.insert((hsh[s][a + d] - hsh[s][a] * pw[d] + M * M) % M);
            FOR(s, n) if (spotty.count((hsh[s + n][a + d] - hsh[s + n][a] * pw[d] + M * M) % M)) works = 0;
            if (works) works2=1;
        }
        if (works2) h=d;
        else l=d+1;
    }
    cout<<l;
}


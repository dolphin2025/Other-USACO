#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

long long dp[1500][10005];

int main() {
    setIO("exercise");
    long long n, m; cin >> n >> m;
    vector<long long> p;
    for (long long i=2; i<=n; i++) {
        long long prime = 1;
        for (long long j=2; j<i; j++) if (i%j==0) prime = 0;
        if (prime) p.push_back(i);
    }
    dp[0][0]=1;
    for (long long i=0; i<p.size(); i++) {
        for (long long s=0; s<=n; s++) {
            dp[i+1][s]=dp[i][s];
            long long pow = p[i];
            while (s-pow>=0) {
                dp[i+1][s]+=dp[i][s-pow]*pow;
                dp[i+1][s]%=m;
                pow*=p[i];
                pow%=m;
            }
        }
    }
    long long ans = 0;
    for (long long i=0; i<=n; i++) {
        ans += dp[p.size()][i];
        ans%=m;
    }
    cout << ans;
}
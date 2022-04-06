#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i=0; i<n; i++)

int cnt[1000][1000], dp[1 << 20];

int main() {
    string s; cin >> s;
    FOR(i, s.size()) cnt[s[i]][s[i + 1]]++;
    set<char> c; for (auto i: s) c.insert(i);
    vector<char> c2; for (auto i: c) c2.push_back(i);
    dp[0] = 1;
    for (int i = 1; i < 1 << c.size(); i++) {
        dp[i] = 1e9;
        FOR(j, c.size())
            if (1 << j & i) {
                int x = 0;
                FOR(k, c.size()) if (1 << k & (i - (1 << j))) x += cnt[c2[j]][c2[k]];
                dp[i] = min(dp[i], dp[i - (1 << j)] + x);
            }
    }
    int ans = dp[(1 << c.size()) - 1];
    for (auto i: c) if (cnt[i][i]) ans += cnt[i][i];
    cout << ans;
}
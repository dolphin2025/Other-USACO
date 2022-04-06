#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);} }

int n, q;
map<int,set<vector<int>>> edges;
int ans; int u; int k;

int solve(unordered_set<int> &seen) {
    if (!seen.count(u)) {
        seen.insert(u);
        ans++;
        for (auto i: edges[u]) {
            if (i[1] >= k) {
                u = i[0];
                solve(seen);
            }
        }
    }
}

int main() {
    setIO("mootube");
    cin >> n >> q;
    for (int i=0; i<n-1; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        edges[a].insert({b,c});
        edges[b].insert({a,c});
    }
    for (int i=0; i<q; i++) {
        cin >> k >> u;
        ans = 0;
        unordered_set<int> seen;
        solve(seen);
        cout << ans-1 << "\n";
    }
}
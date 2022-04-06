#include <bits/stdc++.h>

using namespace std;
#define REP(i, a, b) for (int i=a; i<b; i++)
#define FOR(i, n) REP(i, 0, n)

const int mx = 1e6;
int globalvis[mx], ans[mx], nxt[mx], pos[mx];

int main() {
    long long n, k, m;
    cin >> n >> k >> m;
    int rem = m % k, quo = m / k;
    FOR(i, n) pos[i] = i;
    vector<int> vis[n][2];
    FOR(i, n) vis[i][0].push_back(i), vis[i][1].push_back(i);
    REP(r, 1, k + 1) {
        int a, b; cin >> a >> b; a--; b--;
        vis[pos[a]][r > rem].push_back(b);
        vis[pos[b]][r > rem].push_back(a);
        swap(pos[a], pos[b]);
    }
    FOR(i, n) nxt[pos[i]] = i;
    FOR(i, n) if (!globalvis[i]) {
            globalvis[i] = 1;
            vector<int> cyc = {i};
            while (nxt[cyc.back()] != cyc[0]) globalvis[nxt[cyc.back()]] = 1, cyc.push_back(nxt[cyc.back()]);
            if (quo >= cyc.size()) {
                set<int> s;
                for (auto v: cyc) FOR(j, 2) for (auto p: vis[v][j]) s.insert(p);
                for (auto v: cyc) ans[v] = s.size();
            } else {
                map<int, int> s;
                FOR(v, quo) FOR(j, 2) for (auto p: vis[cyc[v]][j]) s.count(p) ? s[p]++ : s[p] = 1;
                for (auto p: vis[cyc[quo]][0]) s.count(p) ? s[p]++ : s[p] = 1;
                FOR(v, cyc.size()) {
                    ans[cyc[v]] = s.size();
                    for (auto p: vis[cyc[(v + quo) % cyc.size()]][1]) s.count(p) ? s[p]++ : s[p] = 1;
                    for (auto p: vis[cyc[(v + quo + 1) % cyc.size()]][0]) s.count(p) ? s[p]++ : s[p] = 1;
                    FOR(j, 2) for (auto p: vis[cyc[v]][j]) s[p] == 1 ? s.erase(p) : s[p]--;
                }
            }
        }
    FOR(i, n) cout << ans[i] << endl;
}

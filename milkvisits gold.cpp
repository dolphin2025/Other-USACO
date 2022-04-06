#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i=0; i<n; i++)

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);} }

const int mx = 2e5;
bool ans[mx];
vector<int> edges[mx];
int timer = 0;
int st[mx], en[mx];
int seen[mx];
int seen2[mx];
int pos[mx];
stack<int> colorstack[mx];
vector<array<int, 3>> queries[mx];

void dfs(int v) {
    st[v] = timer++;
    seen[v] = 1;
    for (auto i: edges[v]) if (!seen[i]) dfs(i);
    en[v] = timer++;
}

bool anc(int u, int v) {
    return st[u]<=st[v] and en[v]<=en[u];
}

int main() {
    setIO("milkvisits");
    int n,m; cin >> n >> m;
    int type[mx]; FOR(i, n) cin >> type[i];
    FOR(i, n-1) {
        int a,b; cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    FOR(i, m) {
        int a,b,t; cin >> a >> b >> t;
        a--;b--;
        queries[a].push_back({i,b,t});
        queries[b].push_back({i,a,t});
    }
    dfs(0);
    stack<int> s;
    vector<int> path;
    s.push(0);
    path.push_back(0);
    colorstack[type[0]].push(0);
    while (!s.empty()) {
        int u = s.top();
        if (seen2[u]) {
            s.pop();
            path.pop_back();
            colorstack[type[u]].pop();
        }
        else {
            seen2[u]=1;
            colorstack[type[u]].push(u);
            pos[u]=path.size();
            path.push_back(u);
            for (int v: edges[u]) if (!seen2[v]) s.push(v);
            for (auto [i, v, t]: queries[u]) {
                if (!colorstack[t].empty()) {
                    if (pos[colorstack[t].top()]==path.size()-1 or !anc(path[pos[colorstack[t].top()]+1],v)) {
                        ans[i]=1;
                    }
                }
            }
        }
    }
    FOR(i, m) cout << ans[i];
}
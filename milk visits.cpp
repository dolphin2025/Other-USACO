#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);} }

int n,m;
const int maxn = 1e5;
string brand;
vector<int> edges[maxn];
vector<int> cc(maxn, -1);

void dfs(int u, int c) {
    cc[u] = c;
    for (auto i: edges[u]) if (cc[i]==-1 and brand[u]==brand[i]) dfs(i, c);
}

int main() {
    setIO("milkvisits");
    cin >> n >> m;
    cin >> brand;
    for (int i=1; i<n; i++) {
        int a,b; cin >> a >> b;
        a-=1; b-=1;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i=0; i<n; i++) if (cc[i]==-1) dfs(i, i);
    for (int i=0; i<m; i++) {
        int a,b; char s; cin >> a >> b >> s;
        a-=1; b-=1;
        if (cc[a]==cc[b]) cout<<(brand[cc[a]]==s);
        else cout<<1;
    }
}
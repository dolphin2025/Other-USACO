#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

const int mx=1e5+5;
vector<int> adj[mx];

int dfs(int p, int x, int k) {
    if (adj[x].size()==1) return 1;
    int sum = 1;
    multiset<int> s;
    for (auto i: adj[x]) if (i!=p) {
        int i2 = dfs(x, i, k);
        if (i2==-1) return -1;
        sum += i2;
        sum %= k;
        if (i2) s.insert(i2);
    }
    int cnt = 0;
    while (s.size()) {
        int a = *s.begin();
        s.erase(s.begin());
        if (s.count(k-a)) s.erase(s.find(k-a));
        else cnt++;
        if (cnt==2) return -1;
    }
    return sum;
}

int main() {
    setIO("deleg");
    int n; cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    int p, x;
    for (int i=0; i<n; i++) if (adj[i].size()==1) p = i, x = adj[i][0];
    cout<<1;
    for (int k=2; k<=n-1; k++) cout<<(((n-1)%k==0) and (dfs(p, x, k)!=-1));
}

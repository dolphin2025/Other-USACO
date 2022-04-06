#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i=0; i<n; i++)

int n,m;
vector<int> c[1000000];

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);} }

vector<int> solve(int x) {
    vector<int> edges[100000];
    int id[100000]{};
    priority_queue<int, vector<int>, greater<int>> q;
    vector<int> order;
    FOR(i, x) {
        FOR(j, c[i].size()-1) {
            edges[c[i][j]].push_back(c[i][j+1]);
            id[c[i][j+1]]++;
        }
    }
    FOR(i, n) if (!id[i]) q.push(i);
    while (q.size()) {
        int u = q.top(); q.pop();
        order.push_back(u);
        for(auto v: edges[u]) {
            id[v]--;
            if (!id[v]) q.push(v);
        }
    }
    return order;
}

int main() {
    setIO("milkorder");
    cin >> n >> m;
    FOR(i, m) {
        int num; cin >> num;
        FOR(j, num) {
            int x; cin >> x; c[i].push_back(x-1);
        }
    }
    int l=0, h=m;
    while (h-l) {
        int mid = (h+l+1)/2;
        if (solve(mid).size()==n) l=mid;
        else h = mid-1;
    }
    vector<int> ans = solve(l);
    FOR(i, n) {
        if (i) cout<<" ";
        cout<<ans[i]+1;
    }
}
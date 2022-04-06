#include <bits/stdc++.h>

using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

const int maxn = 1e5;
int n, m;
vector<int> cow;
vector<pair<int,int>> edges[maxn];

bool works(int x) {
    bool visited[maxn];
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            stack<int> s;
            s.push(i);
            vector<int> av, bv;
            while (!s.empty()) {
                int u = s.top();
                s.pop();
                av.push_back(u);
                bv.push_back(cow[u]);
                for (auto &[v, w]: edges[u]) {
                    if(w >= x && !visited[v]) {
                        visited[v] = true;
                        s.push(v);
                    }
                }
            }
            sort(av.begin(), av.end());
            sort(bv.begin(), bv.end());
            if (av != bv) return false;
        }
    }
    return true;
}

int main() {
    setIO("wormsort");
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        cow.push_back(x);
    }
    if (is_sorted(begin(cow), end(cow))) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    int l = 0;
    int r = 1e9;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (works(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l;
}
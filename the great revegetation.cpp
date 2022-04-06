#include <bits/stdc++.h>

using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);}
}

int n,m;
map<int,set<pair<int,int>>> graph;
vector<int> a;
set<int> seen;
string ans(1,'1');

void dfs(int p, int v) {
    if (a[p]==v or a[p]==2) {
        if (seen.find(p) != seen.end()) return;
        a[p] = v;
        seen.insert(p);
    }
    else {
        cout << 0;
        exit(0);
    }
    for (auto vec: graph[p]) {
        int c = vec.first;
        int q = vec.second;
        if (c) dfs(q, not v);
        else dfs(q, v);
    }
}

int main() {
//    setIO("revegetate");
    cin >> n >> m;
    for (int i = 0; i<n; i++) a.push_back(2);
    for (int i = 0; i<m; i++) {
        int one, two;
        char clause;
        cin >> clause >> one >> two;
        if (clause == 'D') {
            graph[one-1].insert({1, two-1});
            graph[two-1].insert({1, one-1});
        }
        else {
            graph[one-1].insert({0, two-1});
            graph[two-1].insert({0, one-1});
        }
    }
    for (int p = 0; p<n; p++) {
        if (seen.find(p) == seen.end()) {
            ans += '0';
            dfs(p,1);
        }
    }
    cout << ans;


}
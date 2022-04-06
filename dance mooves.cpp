#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i=0; i<n; ++i)

int n, k, a, b, seen[200000];

int main() {
    cin >> n >> k;
    vector<set<int>> beento(n);
    vector<int> pos(n), graph(n), ans(n);
    FOR(i, n) pos[i]=i, beento[i].insert(i);
    FOR(i, k) {
        cin >> a >> b;
        a--; b--;
        beento[pos[a]].insert(b);
        beento[pos[b]].insert(a);
        swap(pos[a],pos[b]);
    }
    FOR(i, n) graph[pos[i]] = i;
    FOR(i, n) if (!seen[i]) {
            set<int> runval = beento[i], run = {i};
            seen[i] = 1;
            for (int j=graph[i]; j!=i; j=graph[j]) {
                run.insert(j); seen[j] = 1;
                for (auto v: beento[j]) runval.insert(v);
            }
            for (auto v: run) ans[v] = runval.size();
        }
    for (auto v: ans) cout << v << endl;
}
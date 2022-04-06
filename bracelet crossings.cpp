#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i=a; i<b; i++)
#define FOR(i, n) REP(i, 0, n)

int main() {
    int t; cin >> t; FOR(tc, t) {
        int n, m; cin >> n >> m;
        vector<int> status(n, 0);
        vector<vector<int>> rel(n, vector<int>(n, 0));
        int ans=1;
        FOR(line, m) {
            vector<int> o[n];
            int k; cin >> k; FOR(j, k) {
                int a; cin >> a; a--;
                o[a].push_back(j);
            }
            FOR(i, n) {
                if (o[i].size()) {
                    FOR(j, i) if (o[j].size()) {
                        if (o[i][0]<o)
                    }
                    if (status[i]==2) ans=0;
                    status[i]=1;
                }
                else {
                    if (status[i]==1) status[i]=2;
                }
            }
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i=a; i<b; ++i)
#define FOR(i, n) REP(i, 0, n)

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("berries");
    int n, k; cin >> n >> k;
    int a[n]; FOR(i, n) cin >> a[i];
    int ans = 0;
    REP(mx, 1, 1000) {
        int cnt = 0;
        vector<int> baskets;
        for (auto i: a) {
            cnt+=i/mx;
            baskets.push_back(i%mx);
        }
        if (cnt>k) ans=max(ans, mx*k/2);
        else {
            FOR(i, cnt) baskets.push_back(mx);
            sort(begin(baskets),end(baskets));
            reverse(begin(baskets),end(baskets));
            int newans = 0;
            REP(i, k/2, min(k,(int)baskets.size()-1)) newans+=baskets[i];
            ans=max(ans,newans);
        }
    }
    cout<<ans<<endl;
}

#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (long long i=a; i<b; ++i)
#define FOR(i, n) REP(i, 0, n)

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("pairup");
    int n; cin >> n;
    set<array<long long, 2>> c;
    long long ans = 0;
    FOR(i, n) {
        long long a, b; cin >> a >> b;
        c.insert({b,a});
    }
    while (c.size()>1) {
        array<long long, 2> l = *c.begin(), r = *c.rbegin();
        c.erase(r);
        c.erase(l);
        if (l[1]>r[1]) c.insert({l[0],l[1]-r[1]});
        if (l[1]<r[1]) c.insert({r[0],r[1]-l[1]});
        ans = max(ans, l[0]+r[0]);
    }
    if (c.size()) ans = max(ans, (*c.begin())[0]/2);
    cout << ans;
}
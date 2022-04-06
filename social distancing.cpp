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
long long n,m; set<array<long long,2>> iv;
long long num(long long d) {
    long long ans = 0, cur = (*iv.begin())[0];
    while (cur<=(*iv.rbegin())[1]) {
        ans++;
        cur+=d;
        if ((cur>(*(iv.rbegin()))[1])) break;
        if ((*(--(iv.lower_bound({cur+1,-1}))))[1]<cur) cur=(*iv.lower_bound({cur+1,-1}))[0];
    }
    return ans;
}

int main() {
    setIO("socdist");
    cin >> n >> m; FOR(i, m) {long long a,b; cin >>a>>b; iv.insert({a,b});}
    long long l=0, r=1e18;
    while (l!=r) {
//        cout<<l<<' '<<r<<endl;
        long long mid = (l+r+1)/2;
        if (num(mid)>=n) l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
}

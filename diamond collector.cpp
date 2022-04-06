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

const int mx = 1e5;
int n, k, l=0, r=0, ans=0, a[mx], front[mx], back[mx], mxfront[mx], mxback[mx];

int main() {
//    setIO("diamond");
    cin >> n >> k; FOR(i, n) cin >> a[i];
    sort(a, a+n);
    while (l!=n-1) {
        if (r!=n-1 and a[r+1]<=a[l]+k) r++;
        else l++;
        front[l] = max(front[l], r-l+1);
        back[r] = max(back[r], r-l+1);
    }
    mxback[0] = back[0]; REP(i, 1, n-1) mxback[i]=max(mxback[i-1], back[i]);
    mxfront[n-1] = front[n-1]; for (int i = n-2; i>=0; i--) mxfront[i]=max(mxfront[i+1], front[i]);
    FOR(i, n-1) ans = max(ans, mxback[i]+mxfront[i+1]);
    cout<<ans;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i=a; i<b; ++i)
#define FOR(i, n) REP(i, 0, n)

int main() {
    int n; cin >> n;
    int a[n]; FOR(i, n) cin >> a[i], a[i]--;
    int ans=0;
    FOR(i, n) ans = max(ans, a[i]-i);
    cout<<ans<<endl;
}

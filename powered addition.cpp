#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (long long i=0; i<n; i++)

int main() {
    long long t; cin >> t;
    FOR(_, t) {
        long long n; cin >> n;
        long long mx; cin >> mx;
        long long ans = 0;
        FOR(i, n-1) {
            long long x; cin >> x;
            long long v = mx-x;
            if (v>0) {
                FOR(k, 1000) {
                    if (1<<k > v) {
                        ans = max(ans, k);
                        break;
                    }
                }
            }
            mx = max(mx, x);
        }
        cout<<ans<<endl;
    }
}
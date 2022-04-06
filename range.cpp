#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (long long i=0; i<n; i++)

long long bit[6942069];

int main() {
    long long n,q; cin >> n >> q;
    long long ar[n]; FOR(i, n) cin >> ar[i];
    FOR(i, q) {
        long long t; cin >> t;
        if (t==1) {
            long long a,b,u; cin >> a >> b >> u;
            b+=1;
            for(; a<=n; a+=a&-a) bit[a] += u;
            for(; b<=n; b+=b&-b) bit[b] -= u;
        }
        else {
            long long p; cin >> p;
            long long s=0;
            for(long long k=p; k; k -= k&-k) s += bit[k];
            cout << ar[p-1] + s << endl;
        }
    }
}
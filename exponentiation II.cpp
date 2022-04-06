#include <bits/stdc++.h>
using namespace std;

long long modpow(long long x, long long n, long long m) {
    assert(n >= 0);
    x %= m;
    long long ans = 1;
    while (n > 0) {
        if (n % 2) ans = ans * x % m;
        x = x * x % m;
        n /= 2;
    }
    return ans;
}

int main() {
    long long n; cin >> n;
    for (long long i=0; i<n; i++) {
        long long a,b,c; cin >> a>>b>>c;
        cout<<modpow(a,modpow(b,c,1e9+6),1e9+7)<<endl;
//            cout<<modpow(a,b,1e9+7)<<endl;
    }
//    cout<<modpow(2,1,3);
}
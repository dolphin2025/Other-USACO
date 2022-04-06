#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(long long i=0; i<n; i++)
long long MOD = 1e9+7;

long long modpow(long long x, long long n, long long m) {
    assert(n >= 0);
    x %= m;
    long long ans = 1;
    while (n) {
        if (n % 2) ans = ans * x % m;
        x = x * x % m;
        n /= 2;
    }
    return ans;
}

int main() {
    long long num=1, sum=1, prod=1, numforprod=1;
    long long n; cin >> n;
    FOR (i, n) {
        long long x,k; cin >> x >> k;
        num = num*(k+1)%MOD;
        sum = sum*(modpow(x,k+1,MOD)-1)%MOD*(modpow(x-1,MOD-2,MOD))%MOD;
        prod = modpow(prod,k+1,MOD)%MOD*modpow(modpow(x,k*(k+1)/2,MOD),numforprod,MOD)%MOD;
        numforprod = numforprod*(k+1)%(MOD-1);
    }
    cout<<num<<' '<<sum<<' '<<prod;
}
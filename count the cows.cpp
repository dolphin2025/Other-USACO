#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (long long i=0; i<n; i++)

vector<long long> convert(long long x) {
    vector<long long> b;
    for (; x; x/=3) b.push_back(x%3);
    return b;
}

long long cnt(int d[], int x[]) {
    long long carry=0;
    long long nocarry=1;
    long long val, carryval;
    long long vals[3];
    FOR(k, 40) {
        long long r=40-1-k;
        long long newcarry = 0, newnocarry = 0;
        vals[0]=0;
        vals[1]=0;
        vals[2]=0;
        if (d[r]>=0) vals[d[r]]=1;
        else FOR(i, 3) vals[i]=1;
        FOR(j, 3) if (vals[j]) {
            val=x[r]+j;
            carryval=0;
            if (val>=3) {
                val-=3;
                carryval=1;
            }
            if (val%2==j%2) {
                if (carryval) newcarry+=nocarry;
                else newnocarry+=nocarry;
            }
            val=x[r]+j+1;
            carryval=0;
            if (val>=3) {
                val-=3;
                carryval=1;
            }
            if (val%2==j%2) {
                if (carryval) newcarry+=carry;
                else newnocarry+=carry;
            }
        }
        carry = newcarry;
        nocarry = newnocarry;
    }
    return nocarry;
}

long long ans(long long di, long long xi) {
    if (di<0) return 0;
    long long n=0;
    vector<long long> dv = convert(di);
    vector<long long> xv = convert(xi);
    int d[40], x[40];
    FOR(i, 40) {
        if (i<dv.size()) d[39-i]=dv[i];
        else d[39-i]=0;
        if (i<xv.size()) x[39-i]=xv[i];
        else x[39-i]=0;
    }
    int nd[40];
    FOR(i, 40) {
        if (d[i]) {
            FOR(j, i) {
                nd[j]=d[j];
            }
            nd[i]=0;
            for (int j=i+1; j<40; j++) {
                nd[j]=-1;
            }
            n+=cnt(nd,x);
        }
        if (d[i]==2) {
            FOR(j, i) {
                nd[j]=d[j];
            }
            nd[i]=1;
            for (int j=i+1; j<40; j++) {
                nd[j]=-1;
            }
            n+=cnt(nd,x);
        }
    }
    return n+cnt(d,x);
}

int main() {
    long long q;
    cin >> q;
    FOR(i, q) {
        long long d, x, y;
        cin >> d >> x >> y;
        if (y > x) swap(x, y);
        cout << ans(y + d, x - y) - ans(y - 1, x - y) << endl;
    }
}
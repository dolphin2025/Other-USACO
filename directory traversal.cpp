#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (long long i=0; i<n; i++)

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);} }

const long long mx = 2e5;
long long len[mx], topsum[mx], bottomsum[mx], numbelow[mx];
vector<long long> edges[mx];

void dfsbottom(long long u) {
    if (edges[u].size()==0) numbelow[u]=1;
    if (edges[u].size()==0) bottomsum[u]=-1;
    for (auto v: edges[u]) {
        dfsbottom(v);
        numbelow[u] += numbelow[v];
        bottomsum[u] += bottomsum[v]+(numbelow[v])*(len[v]+1);
    }
}

void dfstop(long long p, long long u, long long n) {
    if (p!=-1) {
        topsum[u] = topsum[p]+(n - numbelow[p])*3 + bottomsum[p]-bottomsum[u] + 3*(numbelow[p]-numbelow[u]) - (len[u]+1)*(numbelow[u]);
    }
    for (auto v: edges[u]) {
        if (v!=p) dfstop(u,v,n);
    }
}

int main() {
    setIO("dirtraverse");
    long long n; cin >> n;
    int cnt=0;
    FOR(i, n) {
        string s; cin >> s;
        long long f; cin >> f;
        len[i] = s.size();
        if (f) {
            FOR(j, f) {
                long long x;
                cin >> x;
                x--;
                edges[i].push_back(x);
            }
        }
        else {
            cnt++;
        }
    }
    dfsbottom(0);
    dfstop(-1,0,cnt);
    long long ans=1e18;
    FOR(i, n) ans=min(ans,bottomsum[i]+topsum[i]);
    cout<<ans;
}

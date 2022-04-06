#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (long long i=0; i<n; i++)
#define trav(i, n) for (auto i: n)

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);} }
const int MAXN = 1e6;
long long gothrough[MAXN];

int main() {
    setIO("shortcut");
    long long n,m,t; cin >> n >> m >> t;
    long long cows[MAXN];
    FOR(i, n) cin >> cows[i];
    vector<pair<long long,long long>> edges[MAXN];
    FOR(i, m) {
        long long a,b,c; cin >> a >> b >> c;
        a-=1; b-=1;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
    }
    vector<long long> pa(MAXN, 1e18);
    vector<long long> dist(MAXN, 1e18);
    dist[0]=0;
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
    pq.push({0,0});
    while (pq.size()) {
        auto [d,u] = pq.top(); pq.pop();
        if (dist[u]!=d) continue;
        for (auto [v,w]: edges[u]) {
            if (d+w<dist[v] or d+w==dist[v] and u<pa[v]) {
                pq.push({dist[v]=d+w,v});
                pa[v]=u;
            }
        }
    }
    FOR(i, n) {
        long long j=i;
        while (j!=0) {
            gothrough[j]+=cows[i];
            j=pa[j];
        }
    }
    long long ans=0;
    FOR(i, n) {
        ans=max(ans,gothrough[i]*(dist[i]-t));
    }
    cout<<ans;
}

#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (long long i=0; i<n; i++)
#define trav(i, n) for (auto i: n)

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);} }

const long long maxn = 1e5;
const long long inf = 1e18;

int main() {
    setIO("");
    long long n,m; cin >> n >> m;
    vector<pair<long long,long long>> edges[maxn];
    FOR(i, m) {
        long long a,b,c; cin >> a >> b >> c;
        a--; b--;
        edges[a].push_back({b,c});
    }
    vector<long long> dist(maxn, inf);
    dist[0]=0;
    vector<long long> num(maxn, 0);
    num[0]=1;
    vector<long long> minf(maxn, 0);
    vector<long long> maxf(maxn, 0);
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
    pq.push({0,0});
    while(size(pq)) {
        auto [d,u] = pq.top(); pq.pop();
        if (dist[u]!=d) continue;
        for (auto [v,w]: edges[u]) {
            if (d+w<dist[v]) {
                dist[v]=d+w;
                minf[v]=minf[u]+1;
                maxf[v]=maxf[u]+1;
                num[v]=num[u];
                num[v] %= (long long)(1e9+7);
                pq.push({d+w,v});
            }
            else if (d+w==dist[v]) {
                minf[v]=min(minf[u]+1,minf[v]);
                maxf[v]=max(maxf[u]+1,maxf[v]);
                num[v]+=num[u];
                num[v] %= (long long)(1e9+7);
            }
        }
    }
    cout<<dist[n-1]<<' '<<num[n-1]<<' '<<minf[n-1]<<' '<<maxf[n-1]<<endl;
}

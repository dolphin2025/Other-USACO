#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (long long i=0; i<n; i++)
#define trav(i, n) for (auto i: n)

const long long inf = 1e9;

int main() {
    long long n,m; cin >> n >> m;
    vector<long long> edges[n];
    FOR(i, m) {
        long long a,b; cin >> a >> b;
        a-=1; b-=1;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    long long mincycle = inf;
    FOR(s,n) {
        queue<long long> q;
        q.push(s);
        vector<long long> dist(n,inf);
        dist[s] = 0;
        while (size(q)) {
            long long u=q.front(); q.pop();
            trav(v, edges[u]) {
                if (dist[v] == inf) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
                else if (dist[v]>=dist[u] and dist[u]+dist[v]!=1) mincycle=min(mincycle,dist[u]+dist[v]+1);
            }
        }
    }
    cout<<(mincycle==inf ? -1 : mincycle);
}
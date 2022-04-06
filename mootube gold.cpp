#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i=0; i<n; i++)
#define trav(i, n) for (auto i: n)
void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);} }
int pa[200000], sz[200000];
int get(int x) { return x==pa[x] ? x : pa[x]=get(pa[x]);}

void unite(int a, int b) {
    a = get(a), b = get(b);
    if (a==b) return;
    if (sz[a]>sz[b]) swap(a,b);
    sz[b]+=sz[a];
//    sz[a]=b;
    pa[a]=b;
}

int main() {
    setIO("mootube");
    int n,q; cin >> n >> q;
    vector<vector<int>> edges;
    FOR(i,n-1) {
        int a,b,c; cin >> a >> b >> c;
        a-=1;b-=1;
        edges.push_back({c,a,b});
    }
    vector<vector<int>> queries;
    FOR(i, q) {
        int a,b; cin >> a >> b;
        b-=1;
        queries.push_back({a,b,i});
    }
    FOR(i, n) {
        pa[i]=i;
        sz[i]=1;
    }
    sort(begin(edges),end(edges));
    reverse(begin(edges),end(edges));
    sort(begin(queries),end(queries));
    reverse(begin(queries),end(queries));
    int ans[q];
    int pointer=0;
    trav(i, queries) {
        while (pointer<n-1 and edges[pointer][0]>=i[0]) {
            unite(edges[pointer][1],edges[pointer][2]);
            pointer++;
        }
//        FOR(j, n) cout<<sz[j]<<' '<<pa[j]<<endl;
//        cout<<endl;
        ans[i[2]]=sz[get(i[1])]-1;
    }
    trav(i, ans) cout<<i<<endl;
}
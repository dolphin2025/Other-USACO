//#include <bits/stdc++.h>
//
//using namespace std;
//
//void setIO(string name = "") {
//    cin.tie(0)->sync_with_stdio(0);
//    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);}
//}
//
//set<int> seen;
//set<vector<int>> moonets;
//map<int,vector<int>> cows;
//map<int,set<int>> edges;
//
//vector<int> dfs(int u, vector<int> m) {
//    if (seen.find(u) == seen.end()) {
//        seen.insert(u);
//        m = {min(m[0],cows[u][0]),max(m[1],cows[u][0]),min(m[2],cows[u][1]),max(m[3],cows[u][1])};
//        for (auto v: edges[u]) {
//            if (seen.find(v) == seen.end()) {
//                m = dfs(v,m);
//            }
//        }
//    }
//    return m;
//}
//
//int main() {
//    setIO("fenceplan");
//    int n,m;
//    cin >> n >> m;
//    for (int i=1; i<n+1; i++) {
//        int x,y;
//        cin >> x >> y;
//        cows[i] = {x,y};
//    }
//    for (int i=0; i<m; i++) {
//        int f,s;
//        cin >> f >> s;
//        edges[f].insert(s);
//        edges[s].insert(f);
//    }
//    for (int i=1; i<n+1; i++) {
//        if (!seen.count(i)) {
//            moonets.insert(dfs(i, {cows[i][0],cows[i][0],cows[i][1],cows[i][1]}));
//        }
//    }
//    long long ans = 2*pow(10,18);
//    for (auto i: moonets) {
//        long long thing = (i[1]-i[0])+(i[3]-i[2]);
//        ans = min(ans,thing);
//    }
//    cout << 2*ans;
//}

#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100000

int N;
int x[MAXN], y[MAXN];
int cid[MAXN];
int minl[MAXN];
int maxr[MAXN];

bool cmp(int a,int b)
{
    if(x[a]==x[b]) return y[a]<y[b];
    return x[a]<x[b];
}


int main()
{
//    freopen("moop.in","r",stdin);
//    freopen("moop.out","w",stdout);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> x[i] >> y[i];
        cid[i] = i;
    }
    sort(cid,cid+N,cmp);
    minl[0] = y[cid[0]];
    for(int i=1;i<N;i++)
        minl[i] = min(minl[i-1], y[cid[i]]);
    maxr[N-1] = y[cid[N-1]];
    for(int i=N-2;i>=0;i--)
        maxr[i] = max(maxr[i+1], y[cid[i]]);
    int ans = 1;
    for(int i=0;i<N-1;i++)
        if(minl[i] > maxr[i+1])
            ans++;
    cout << ans << '\n';
}
//#include <iostream>
//#include <fstream>
//#include <algorithm>
//using namespace std;
//#define MAX_N 7500
//
//int N, K, visited[MAX_N+1];
//long long D[MAX_N+1];
//
//// Prim/Jarnik MST algorithm
//void jarnik(int source)
//{
//    for (int i=1; i<=N; i++) D[i] = 2019201997;
//    for (int iter=0; iter<N; iter++) {
//        int min_i = 0;
//        for (int i=1; i<=N; i++)
//            if (!visited[i] && (min_i==0 || D[i] < D[min_i])) min_i = i;
//        visited[min_i] = 1;
//        for (int j=1; j<=N; j++)
//            if (!visited[j])
//                D[j] = min(D[j], (2019201913LL*min(min_i,j)+2019201949LL*max(min_i,j)) % 2019201997LL);
//    }
//}
//
//int main(void)
//{
//    ifstream fin ("walk.in");
//    fin >> N >> K;
//    ofstream fout ("walk.out");
//    jarnik(1);
//    sort (D+1,D+N+1);
//    fout << D[N+1-K] << "\n";
//    return 0;
//}

#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);} }

const long long inf = 1e18;
const long long MOD = 2019201997;
long long dbetween(long long x, long long y) {
    return (2019201913*(min(x,y)+1)%MOD+2019201949*(max(x,y)+1))%MOD;
}

int main() {
    setIO("walk");
    cin.tie(0)->sync_with_stdio(0);
    long long n,k; cin >> n >> k;
    vector<long long> dist(n, inf);
    dist[0]=0;
    vector<bool> visited(n, 0);
    vector<long long> edges;
    while (find(begin(visited),end(visited),0)!=end(visited)) {
//        long long u = dist[find(begin(dist),end(dist),min(begin(dist),end(dist)))-begin(dist)];
        long long m = inf;
        for (long long i=0; i<n; i++) {
            if (not visited[i]) m = min(dist[i],m);
        }
        long long u;
        for (long long i=0; i<n; i++) {
            if (not visited[i] and dist[i]==m) u=i;
        }
        edges.push_back(dist[u]);
        visited[u]=1;
        for (long long v=0; v<n; v++) {
            if (!visited[v]) dist[v]=min(dist[v],dbetween(u,v));
        }
    }
    sort(begin(edges),end(edges));
    cout<<edges[edges.size()-k+1];
}
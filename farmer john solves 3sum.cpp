#include <bits/stdc++.h>
using namespace std;

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

#include <ext/pb_ds/assoc_container.hpp> // for gp_hash_table
using namespace __gnu_pbds;

int N,Q;
long long ans[5000][5000];
vector<int> A;

int main() {
    setIO("threesum");
    cin >> N >> Q;
    A.resize(N); for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) {
        gp_hash_table<int,int> g({},{},{},{},{1<<13});
        // initialize with capacity that is a power of 2
        for (int j = i+1; j < N; ++j) {
            int res = -A[i]-A[j];
            auto it = g.find(res);
            if (it != end(g)) ans[i][j] = it->second;
            g[A[j]] ++;
        }
    }
    for (int i = N-1; i >= 0; --i) for (int j = i+1; j < N; ++j)
            ans[i][j] += ans[i+1][j]+ans[i][j-1]-ans[i+1][j-1];
    for (int i = 0; i < Q; ++i) {
        int a,b; cin >> a >> b;
        cout << ans[a-1][b-1] << "\n";
    }
}//#include <bits/stdc++.h>
//using namespace std;
//#define FOR(i, n) for (long long i=0; i<n; i++)
//#define REP(i, a, b) for (long long i=a; i<b; i++)
//
//void setIO(string name = "") {
//    cin.tie(0)->sync_with_stdio(0);
//    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);} }
//
//const long long mx = 5001;
//const long long mx2 = 2000001;
//long long a[mx];
//long long ans[mx][mx], cnt[mx2*2];
//
//int main() {
//    setIO("threesum");
//    long long n,q; cin >> n >> q;
//    FOR(i, n) cin >> a[i];
////    FOR(i, n-2) {
////        if (i) cnt[a[i-1]]--;
////        REP(j, i+1, n-1) {
////            cnt[a[j]+2000000]++;
////            ans[i][j+1] = cnt[-a[i]-a[j+1]+2000000];
////        }
////    }
//    REP(sz, 2, n) {
//        FOR(i, n-sz) {
//            if (i) {
//                cnt[a[i+sz-1]+mx2]++;
//                cnt[a[i]+mx2]--;
//            }
//            else {
//                REP(j, n-sz+1, n-1) cnt[a[j]+mx2]--;
//                REP(j, i+1, i+sz) cnt[a[j]+mx2]++;
//            }
//            ans[i][i+sz] = ans[i][i+sz-1]+ans[i+1][i+sz]-ans[i+1][i+sz-1] + cnt[-a[i]-a[i+sz]+mx2];
//        }
//    }
//    FOR(i, q) {
//        long long x,y; cin >> x >> y;
//        cout<<ans[x-1][y-1]<<endl;
//    }
//}

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define FOR(i, n) for (long long i=0; i<n; i++)

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);} }

const long long maxn = 2e5;
long long a[maxn];
vector<long long> ind[maxn];
long long ans[maxn];
long long seg[2*maxn];

void incr(long long p) {
    seg[p += maxn]++;
    for (p/=2; p; p/=2) seg[p] = seg[2*p]+seg[2*p+1];
}

long long query(long long l, long long r) {
    long long s = 0;
    for (l+=maxn, r+=maxn; l<=r; l/=2, r/=2) {
        if (l%2) s+=seg[l++];
        if (!(r%2)) s+=seg[r--];
    }
    return s;
}

int main() {
    setIO("haircut");
    long long n; cin >> n;
    tree<pair<long long,long long>, null_type, less<pair<long long,long long>>, rb_tree_tag, tree_order_statistics_node_update> t;
    long long num = 0;
    FOR(i, n) {
        cin >> a[i];
        ind[a[i]].push_back(i);
        num += i-t.order_of_key({a[i],i}); // or no +1
//        cout<<i<<t.order_of_key(a[i]+1)<<endl;
        t.insert({a[i],i});
    }
//    long long num2 =0;
//    FOR(i, n) {
//        FOR(j, i) {
//            if (a[i]<a[j]) num2++;
//        }
//    }
//    cout<<num<<endl;
//    cout<<num2<<endl;
    for (long long i=n; i>=0; i--) {
        for (auto j: ind[i]) num-=query(0, j);
        for (auto j: ind[i]) incr(j);
        ans[i] = num;
    }
    FOR(i, n) cout<<ans[i]<<endl;
}
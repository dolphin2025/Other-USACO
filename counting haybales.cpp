#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define ub upper_bound
#define lb lower_bound
#define f first
#define s second
#define mp make_pair
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define inp(n) int n; cin >> n
#define inpv(v, n) vi v(n); FOR(i, n) cin >> v[i]

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(name)) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);}
}

int main() {
    setIO("haybales");
    inp(n); inp(q);
    inpv(v, n);
    sort(all(v));
    FOR (i, q) {
        inp(a); inp(b);
        cout << ub(all(v),b)-lb(all(v),a) << endl;
    }
}
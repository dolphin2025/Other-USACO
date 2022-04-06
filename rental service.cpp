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
#define FOR(i, n) for(int i = 0; i < n; i++)

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(name)) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);}
}

int main() {
    setIO("rental");
    ll n, m, k;
    cin >> n >> m >> k;
    vi cows;
    FOR(i, n) {
        ll cowgallons;
        cin >> cowgallons;
        cows.pb(cowgallons);
    }
    sort(all(cows), greater<ll>());
    vector<pi> buyers;
    FOR(i, m) {
        pi buyerdetails;
        cin >> buyerdetails.f >> buyerdetails.s;
        buyers.pb(buyerdetails);
    }
    sort(all(buyers), [](const pi& x, const pi& y){return x.s > y.s; });
    vi renters;
    FOR(i, k) {
        ll renterdetails;
        cin >> renterdetails;
        renters.pb(renterdetails);
    }
    sort(all(renters), greater<ll>());
    vi cowsps;
    ll currentsum = 0;
    FOR(i, n) {
        currentsum += cows[i];
        cowsps.pb(currentsum);
    }
    vector<pi> buyersps;
    pi csum {0, 0};
    FOR(i, m) {
        csum.f += buyers[i].f;
        csum.s += buyers[i].f*buyers[i].s;
        buyersps.pb(csum);
    }
    vi rentersps;
    currentsum = 0;
    FOR(i, k) {
        currentsum += renters[i];
        rentersps.pb(currentsum);
    }
    vi gallonsps;
    for(auto i: buyersps) gallonsps.pb(i.f);
    ll maxp=0;
    ll profitbuyers;
    ll profitrenters;
    FOR(r, n) {
        ll milk = cowsps[n-r-1];

        if (milk<=buyers[0].f)
//            profitbuyers = buyersps[0].s;
            profitbuyers = milk*buyers[0].f;
        else if (milk >= buyersps[m-1].f) profitbuyers = buyersps[m-1].s;
        else {
            ll x = ub(all(gallonsps), milk) - gallonsps.begin();
//            cout << "dis x" << x << endl;
            profitbuyers = buyersps[x-1].s + (milk-buyersps[x-1].f)*buyers[x].s;
        }

        if (r == 0) profitrenters = 0;
        else if (r >= k) profitrenters = rentersps[k-1];
        else profitrenters = rentersps[r-1];

//        cout << r << endl << profitrenters << endl << profitbuyers << endl << endl;

        maxp = max(profitrenters+profitbuyers,maxp);
    }
    cout << maxp << '\n';
}
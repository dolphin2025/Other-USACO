#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair
#define FOR(i, n) for (int i = 0; i < n; i++)

void setIO(const string &name = "") {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
//    setIO("word");
    int n, k;
    cin >> n >> k;
    int ccount = 0;
    string x;
    FOR(i, n) {
        cin >> x;
        if (x.length() + ccount > k) {
            cout << "\n" << x;
            ccount = x.length();
        } else {
            (i != 0) ? cout << ' ' << x : cout << x;
            ccount += x.length();
        }
    }
    cout << endl;
}
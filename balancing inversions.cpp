#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

long long inv(vector<long long> v) {
    long long ones = 0, ans = 0;
    for (auto i: v) {
        if (i) ones++;
        else ans += ones;
    }
    return ans;
}

long long n, t=0, ans = 1e18, a[300000];

void solve(set<long long> l0, set<long long> l1, set<long long> r0, set<long long> r1, long long dif, bool dir) {
    long long swaps = 0;
    if (dir) {
        while (l1.size() and r0.size()) {
            long long x = *l1.rbegin();
            l1.erase(x);
            long long y = *r0.begin();
            r0.erase(y);
            dif-=(n-x-y-1)+n-t;
            swaps += y-x+n;
            ans = min(ans, swaps + abs(dif));
        }
    } else {
        while (r1.size() and l0.size()) {
            long long x = *l0.rbegin();
            l0.erase(x);
            long long y = *r1.begin();
            r1.erase(y);
            dif += (n-x-y-1)+n-t;
            swaps += y - x + n;
            ans = min(ans, swaps + abs(dif));
        }
    }
}
int main() {
    setIO("balance");
    cin >> n;
    for (long long i=0; i<2*n; i++) cin >> a[i];
    vector<long long> left, right;
    set<long long> l1, l0, r1, r0;
    for (long long i=0; i<n; i++)  left.push_back(a[i]);
    for (long long i=n; i<2*n; i++)  right.push_back(a[i]);
    for (auto i: a) if (i) t++;
    for (long long i = 0; i < 2 * n; i++) {
        if (a[i]) {
            if (i < n) l1.insert(i);
            else r1.insert(i - n);
        } else {
            if (i < n) l0.insert(i);
            else r0.insert(i - n);
        }
    }
    long long dif = inv(left) - inv(right);
    ans = abs(dif);
    solve(l0, l1, r0, r1, dif, 1);
    solve(l0, l1, r0, r1, dif, 0);
    cout<<ans<<endl;
}

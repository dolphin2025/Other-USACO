#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i=0; i<n; i++)

const int mx = 3e5;
long long ans=0, n, bit[mx], cows[mx], l[mx];

int qry(int k) {
    int sum = 0;
    for (k++; k; k -= k & -k) sum += bit[k];
    return sum;
}

int main() {
    cin >> n; FOR(i, n) cin >> cows[i];
    vector<vector<int>> ind(n), lind(n);
    FOR(i, n) ind[cows[i]-1].push_back(i);
    for (auto lst: ind) for (int i = int(lst.size()) - 1; i > 0; i--) l[lst[i]] = lst[i - 1] + 1;
    vector<int> r(n, n - 1);
    for (auto lst: ind) FOR(i, int(lst.size())-1) r[lst[i]] = lst[i + 1] - 1;
    FOR(i, n) lind[l[i]].push_back(i);
    FOR(i, n-1) {
        for (auto x: lind[i]) for (x++; x <= mx; x += x & -x) bit[x]++;
        ans += qry(r[i]) - qry(i);
    }
    cout << ans;
}


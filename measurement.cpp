#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);} }

int main() {
    setIO("measurement");
    int n,g; cin >> n >> g;
    multiset<int> vals;
    map<int,int> output;
    vals.insert(0);
    vector<vector<int>> ms;
    for (int i=0; i<n; i++) {
        int a,b,c; cin >> a >> b >> c;
        ms.push_back({a,b,c});
    }
    sort(ms.begin(),ms.end(),[](const vector<int>& x, const vector<int>& y) { return x[0] < y[0]; });
    int max = 0;
    int ans = 0;
    for (auto i: ms) {
        if (output.count(i[1]) ==0) {
            output[i[1]] = 0;
            vals.insert(0);
        }
        int before1 = vals.count(max);
        bool before = output[i[1]]==max;
        vals.erase(vals.lower_bound(output[i[1]]));
        output[i[1]] += i[2];
        vals.insert(output[i[1]]);
        max = *vals.rbegin();
        int after1 = vals.count(max);
        bool after = output[i[1]]==max;
        ans += (before!=after) or (before1!=after1);
    }
    cout<<ans;

}
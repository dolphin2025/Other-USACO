#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);} }

long long modthing = (1e+9)+7;

int main() {
    setIO("triangles");
    int n; cin >> n;
    vector<vector<int>> pts; pts.resize(n);
    for (int i=0; i<n; i++) cin >> pts[i][0] >> pts[i][1];

    map<vector<int>,int> latsum, vertsum;
    map<int,vector<int>> horilines, vertlines;

    for (auto i: pts) vertlines[i[0]].push_back(i[1]);
    for (auto i: pts) horilines[i[1]].push_back(i[0]);

    for (auto i: horilines) sort(i.second.begin(), i.second.end());
    for (auto i: vertlines) sort(i.second.begin(), i.second.end());

    for (auto i: horilines) {
        int sum = 0;
        int len = i.second.size();
        for (auto v: i.second) sum += v-i.second[0];
        latsum[{i.second[0], i.first}] = sum;
        for (int ind = 1; ind<len;ind++) {
            sum += (i.second[ind]-i.second[ind-1])*(2*ind-len);
            latsum[{i.second[ind], i.first}] = sum;
        }
    }

    for (auto i: vertlines) {
        int sum = 0;
        int len = i.second.size();
        for (auto v: i.second) sum += v-i.second[0];
        vertsum[{i.first, i.second[0]}] = sum;
        for (int ind = 1; ind<len;ind++) {
            sum += (i.second[ind]-i.second[ind-1])*(2*ind-len);
            vertsum[{i.first, i.second[ind]}] = sum;
        }
    }

    long long ans = 0;
    for (auto i: latsum) {
        long long a = i.second;
        long long b = vertsum[i.first];
        ans += a*b;
        ans = ans%modthing;
    }
    cout << ans<<endl;
}
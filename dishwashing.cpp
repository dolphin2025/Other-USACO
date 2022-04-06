#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);} }

int main() {
    setIO("dishes");
    int n; cin >> n;
    int topdone = 0;
    vector<vector<int>> p;
    int x; cin >> x;
    p.push_back({x});
    int ans = 1;
    for (int i=1; i<n; i++) {
        int x; cin >> x;
        if (x<topdone) {
            cout<<ans;
            return 0;
        }
        int l=0, h=p.size()-1;
        while (h-l) {
            int mid = (l + h)/2;
            if (x>p[mid][0]) l = mid+1;
            else h = mid;
        }
        if (x<p[l][0]) {
            while (p[l].back()<x) {
                if (topdone > p[l].back()) {
                    cout<<ans;
                    return 0;
                }
                topdone = p[l].back();
                p[l].pop_back();
            }
            p[l].push_back(x);
        }
        else p.push_back({x});
        ans++;
    }
    cout<<ans;
}
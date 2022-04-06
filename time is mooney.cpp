#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);} }

const int maxn = 3000;
int maxmoney[maxn][maxn];

int main() {
    setIO("time");
    vector<int> edges[maxn];
    int n,m,c; cin >> n >> m >> c;
    int money[maxn];
    for (int i=0; i<n; i++) cin >> money[i];
    for (int i=0; i<m; i++) {
        int a,b; cin >> a >> b;
        a-=1; b-=1;
        edges[a].push_back(b);
    }
    for (int i=0; i<n; i++) for (int t=0; t<maxn; t++) maxmoney[i][t]=-1e9;
    maxmoney[0][0]=0;
    for (int t=1; t<maxn; t++) {
        for (int x=0; x<n; x++) {
            for (auto i: edges[x]) {
                if (maxmoney[i][t-1]!=-1e9) {
                    maxmoney[x][t]=max(maxmoney[x][t],maxmoney[i][t-1]+money[x]);
                }
            }
        }
    }
    int ans=0;
    for (int t=1; t<maxn; t++) ans=max(ans,maxmoney[0][t]-c*t*t);
    cout<<ans;
}
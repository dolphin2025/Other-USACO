#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i=a; i<b; i++)
#define FOR(i, n) REP(i, 0, n)

int main() {
    int t, n, k; cin >> t >> n >> k;
    int inp[n][2], ans=0;
    vector<vector<array<int,2>>> chains;
    chains.push_back({});
    FOR(i, n) {
        cin >> inp[i][0] >> inp[i][1];
        if (chains.back().size() and inp[i][0]>chains.back().back()[0]+k) chains.push_back({});
        chains.back().push_back({inp[i][0],inp[i][1]});
    }
    if (t==1) {
        for (auto v: chains) if (v.size()%2) {
            int m=1e9;
            FOR(j, v.size()) {
                if (j%2==0 or v[j-1][0]+k>=v[j+1][0]) m=min(m, v[j][1]);
            }
            ans += m;
        }
        cout<<ans<<endl;
    }
    else {
        for (auto v: chains) {
            vector<array<int,2>> dp(v.size(),{0,0});
            vector<int> back(v.size(),-1);
            set<array<int,2>> s;
            FOR(i, v.size()) {
                if (s.upper_bound({v[i][0] - k, -1}) == s.begin()) back[i] = -1;
                else back[i] = (*(--s.upper_bound({v[i][0] - k, -1})))[1];
                s.insert({v[i][0],i});
            }
// my sol //////////////////////////////////////////////////////////////////////////////////////////////////////
//            dp[0][0]=v[0][1];
//            REP(i, 1, v.size()) FOR(p, 2) {
//                    if (back[i]==-1) dp[i][p]=dp[i-1][!p];
//                    if (back[i]==-1 and i%2==p) dp[i][p]=max(dp[i][p],v[i][1]);
//                    if (back[i]!=-1) dp[i][p]=max(dp[i-1][!p],dp[back[i]][(i-back[i]-1+p)%2]+v[i][1]);
//                }
// official sol ///////////////////////////////////////////////////////////////////////////////////////////////
            dp[0][1] = v[0][1];
            REP(i, 1, v.size()) FOR(p, 2) {
                    dp[i][p] = dp[i-1][p];
                    if (back[i]!=-1) dp[i][p] = max(dp[i][p], dp[back[i]][!p]+v[i][1]);
            }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            FOR(i, v.size()) {
//                cout<<dp[i][0]<<' '<<dp[i][1]<<endl;
            }
            ans+=dp[v.size()-1][v.size()%2];
//            cout<<endl;
        }
        cout<<ans<<endl;
    }
}

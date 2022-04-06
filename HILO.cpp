#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i=a; i<b; i++)
#define FOR(i, n) REP(i, 0, n)

const int maxn = 3e5;
int a[maxn];
vector<int> ntoh[maxn], htol[maxn], lton[maxn];

int main() {
    int n; cin >> n;
    FOR(i, n) cin >> a[i];
    FOR(i, n) htol[a[i]].push_back(i);
    set<int> s1={a[0]};
    set<array<int,2>> s={{0,1}};
    REP(i, 1, n) {
        if (s1.lower_bound(a[i])!=s1.end()) lton[*s1.lower_bound(a[i])].push_back(i);
        if (s1.upper_bound(a[i])!=s1.begin()) ntoh[*s1.lower_bound(a[i])].push_back(i);
        else s.insert({i,1});
    }
    int ans = 0;
    cout<<0<<endl;
    REP(x, 1, n+1) {
        for (auto i: ntoh[x]) {
            auto lb = s.lower_bound({i,0});
            if (lb!=s.end() and (*lb)[1]==0) ans++;
            auto ub = s.upper_bound({i,0});
            if (ub!=s.begin() and lb!=s.end() and (*ub)[1] and (*lb)[1]==0) ans--;
            s.insert({i,1});
        }
        for (auto i: htol[x]) {
            auto lb = s.lower_bound({i,1});
            lb--;
            if ((*lb)[1]) ans++;
            lb++;
            lb++;
            if ((*lb)[1]==0) ans--;
            lb--;
            s.erase(lb);
            s.insert({i,0});
        }
        for (auto i: lton[x]) {
            s.erase({i,0});
            auto lb = s.lower_bound({i,0});
            auto ub = s.upper_bound({i,0});
            if (ub!=s.begin() and (*ub)[1]) ans--;
            if (ub!=s.begin() and lb!=s.end() and (*ub)[1] and (*lb)[1]==0) ans++;
        }
        cout<<ans<<endl;
    }
}

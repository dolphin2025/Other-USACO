#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i=0; i<n; i++)
#define REP(i, a, b) for (int i=a; i<b; i++)

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);} }

const int mx = 1<<20;
int ans[mx], sz[mx], seg[2*mx];

void upd(int i, int v) {
    i+=mx;
    seg[i] = max(seg[i],v);
    for (i/=2; i; i/=2) seg[i]=max(seg[2*i],seg[2*i+1]);
}

int best(int i) { 
    int bst=0;
    for (i+=mx; i; i/=2) if (i%2==0) bst=max(bst, seg[i--]);
    return bst;
}

int main() {
    setIO("boards");
    int n, p; cin >> n >> p;
    map<int,int> pos;
    vector<array<int,3>> pts;
    vector<int> ys;
    FOR(i, p) {
        int a,b,c,d; cin >> a >>b>>c>>d;
        sz[i+1]=c-a+d-b;
        pts.push_back({a,b,i+1});
        pts.push_back({c,d,-i-1});
        ys.push_back(b);
        ys.push_back(d);
    }
    ys.push_back(n);
    sort(ys.begin(),ys.end());
    FOR(i, ys.size()) pos[ys[i]]=i;
    pts.push_back({n,n,p+1});
    sort(begin(pts), end(pts));
    for(auto [x, y, i]: pts) {
        if (i>0) {
            ans[i] = best(pos[y]);
        }
        else {
            upd(pos[y], ans[-i]+sz[-i]);
        }
    }
    cout<<2*n-ans[p+1];
}
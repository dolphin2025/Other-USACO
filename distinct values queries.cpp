#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i=0; i<n; i++)

const int maxn = 2e5+1;
int bit[2*maxn+1];
void add(int p, int v) { for(;p<maxn;p+=p&-p) bit[p]+=v;}
int sum(int r) {
    int s=0;
    for(; r; r-=r&-r) s+=bit[r];
    return s;
}

int main() {
    int n,q; cin >> n >> q;
    int ar[maxn]; FOR(i, n) cin >> ar[i];
    vector<vector<int>> queries;
    FOR(i, q) {
        int l,r; cin >> l >> r;
        l--; r--;
        queries.push_back({r,l,i});
    }
    int ans[maxn];
    sort(begin(queries),end(queries));
    map<int,int> lastseen;
    int ind = 0;
    FOR(end, n) {
        if (lastseen.count(ar[end])) add(lastseen[ar[end]]+1, -1);
        add(end+1, 1);
        lastseen[ar[end]]=end;
        while (ind<q and queries[ind][0]<=end) {ans[queries[ind][2]]=sum(queries[ind][0]+1)-sum(queries[ind][1]);
            ind++;
        }
    }
    FOR(i, q) cout<<ans[i]<<endl;
}
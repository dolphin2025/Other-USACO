#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);} }

int n; char grid[20][20]; vector<vector<int>> pcls;
set<vector<int>> seen, nosir;

void dfs(int r1,int r2,int c1,int c2, int i, int j) {
    if (!seen.count({i,j})) {
        seen.insert({i,j});
        if (i>r1 and grid[i][j]==grid[i-1][j]) dfs(r1,r2,c1, c2,i-1, j);
        if (j>c1 and grid[i][j]==grid[i][j-1]) dfs(r1,r2,c1, c2,i, j-1);
        if (i<r2-1 and grid[i][j]==grid[i+1][j]) dfs(r1,r2,c1, c2,i+1, j);
        if (j<c2-1 and grid[i][j]==grid[i][j+1]) dfs(r1,r2,c1, c2,i, j+1);
    }
}

void check(int r1,int r2,int c1,int c2) {
    seen.clear();
    map<char,int> rcount;
    for (int i=r1; i<r2; i++) {
        for (int j=c1; j<c2; j++) {
            if (not seen.count({i,j})) {
                if (rcount.count(grid[i][j])) rcount[grid[i][j]] += 1;
                else rcount[grid[i][j]] = 1;
                dfs( r1, r2, c1, c2, i, j);
            }
        }
    }
    vector<int> counts;
    for (auto i: rcount) {
        counts.push_back(i.second);
    }
    sort(begin(counts), end(counts));
    if (counts.size()==2 and counts[0]==1 and counts[1]>1) {
//        if (counts[1]>2) cout << r1<<r2<<c1<<c2<<endl;
        pcls.push_back({r1,r2,c1,c2});
    }
}

int main() {
//    setIO("where");
    cin >> n;
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        for (int j=0; j<n; j++) {
            grid[i][j]=s[j];
        }
    }
    for (int nr1=0; nr1<n; nr1++)
        for (int nr2=nr1+1; nr2<=n; nr2++)
            for (int nc1=0; nc1<n; nc1++)
                for (int nc2=nc1+1; nc2<=n; nc2++)
                    check(nr1,nr2,nc1,nc2);
    int ans=0;
//    cout<<pcls.size()<<endl;
    for (auto p2: pcls) {
//        cout<<p2[0]<<p2[1]<<p2[2]<<p2[3]<<endl;
        int works=1;
        for (auto p1: pcls) {
//            cout<<p1[0]<<p1[1]<<p1[2]<<p1[3]<<endl;
            if (p2[0]>=p1[0] and p2[1]<=p1[1] and p2[2]>=p1[2] and p2[3]<=p1[3]) {
                if (p1!=p2) works=0;
            }
        }
        if (works==1) ans += 1;
    }
    cout<<ans;
}
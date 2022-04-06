#include <bits/stdc++.h>
using namespace std;

const int maxn = 201;
int ps[maxn+2][maxn+2], r1m[maxn], r2m[maxn], c1m[maxn], c2m[maxn];

int main() {
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    int n,k; cin >> n >> k;
    for (int i=0; i<n; i++) {
        int a,b,c,d; cin >> a >> b >> c >> d;
        a++; b++; c++; d++;
        a++; b++; c++; d++;
        ps[a][b]++;
        ps[a][d]--;
        ps[c][b]--;
        ps[c][d]++;
    }
    for (int i=0; i<maxn; i++) for (int j=0; j<maxn; j++) ps[i+1][j+1] = ps[i+1][j+1] + ps[i][j+1] + ps[i+1][j] - ps[i][j];
    int ans2 = 0;
    for (int i=0; i<maxn; i++) for (int j=0; j<maxn; j++)  if (ps[i][j]==k) ans2++;
    for (int i=2; i<=maxn; i++) for (int j=2; j<=maxn; j++) {
            if (ps[i][j]==k-1) ps[i][j]=1;
            else {
                if (ps[i][j]==k) ps[i][j]=-1;
                else ps[i][j]=0;
            }
        }
    for (int i=0; i<maxn; i++) for (int j=0; j<maxn; j++) ps[i+1][j+1] = ps[i+1][j+1] + ps[i][j+1] + ps[i+1][j] - ps[i][j];
    vector<array<int,5>> rs;
    rs.reserve(maxn*maxn*maxn);
    for (int r1=1; r1<maxn; r1++) {
        for (int r2=r1; r2<maxn; r2++) {
            int run = 0;
            int c1=1;
            for (int c2=1; c2<maxn; c2++) {
                run += ps[r2][c2] - ps[r1-1][c2] - ps[r2][c2-1] + ps[r1-1][c2-1];
                rs.push_back({r1,r2,c1,c2,run});
                if (run<0) {
                    run = 0;
                    c1 = c2;
                }
                rs.push_back({r1,r2,c1,c2,run});
            }
        }
    }
    for (auto r: rs) {
        r1m[r[0]]=max(r1m[r[0]],r[4]);
        r2m[r[1]]=max(r2m[r[1]],r[4]);
        c1m[r[2]]=max(c1m[r[2]],r[4]);
        c2m[r[3]]=max(c2m[r[3]],r[4]);
    }
    int mr1[maxn];
    int run = 0;
    for (int i=maxn-1; i>=0; i--) {
        run = max(run,r1m[i]);
        mr1[i] = run;
    }
    int mr2[maxn];
    run = 0;
    for (int i=0; i<maxn; i++) {
        run = max(run,r2m[i]);
        mr2[i] = run;
    }
    int mc1[maxn];
    run = 0;
    for (int i=maxn-1; i>=0; i--) {
        run = max(run,c1m[i]);
        mc1[i] = run;
    }
    int mc2[maxn];
    run = 0;
    for (int i=0; i<maxn; i++) {
        run = max(run,c2m[i]);
        mc2[i] = run;
    }
    int ans = 0;
    for (int hline = 1; hline<maxn; hline++) ans = max(mr1[hline]+mr2[hline-1],ans);
    for (int vline = 1; vline<maxn; vline++) ans = max(mc1[vline]+mc2[vline-1],ans);
    cout<<ans+ans2<<endl;
    int x = 0;
    for (int i=0; i<1600000; i++) x = max(x,i);
    cout<<x;
}
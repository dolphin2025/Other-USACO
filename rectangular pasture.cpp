#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    vector<vector<long long>> pts;
    vector<long long> xs;
    vector<long long> ys;
    for (long long i=0; i<n; i++) {
        long long x,y;
        cin >> x >> y;
        pts.push_back({x,y});
        xs.push_back(x);
        ys.push_back(y);
    }
    sort(begin(xs), end(xs));
    sort(begin(ys), end(ys));
    set<vector<long long>> spts;
    for (auto &i: pts) {
        i[0] = find(begin(xs),end(xs),i[0]) - xs.begin() + 1;
        i[1] = find(begin(ys),end(ys),i[1]) - ys.begin() + 1;
        spts.insert(i);
    }
    long long ps[n+1][n+1];
    for (long long i=0; i<=n; i++) {
        for (long long j=0; j<=n; j++) {
            long long x=spts.count({i,j});
            if (i) x+=ps[i-1][j];
            if (j) x+=ps[i][j-1];
            if (i and j) x-=ps[i-1][j-1];
            ps[i][j]=x;
        }
    }
//    for (long long i=0; i<=n; i++) {
//        for (long long j = 0; j <= n; j++) {
//            cout << ps[i][j];
//        }
//        cout<<endl;
//    }
    long long ans=0;
    for (auto a: pts) {
        for (auto b: pts) {
            if (a[1]>b[1]) {
                ans+=(ps[n][a[1]]-ps[max(a[0],b[0])-1][a[1]]-ps[n][b[1]-1]+ps[max(a[0],b[0])-1][b[1]-1]) *
                        (ps[min(a[0],b[0])][a[1]]-ps[min(a[0],b[0])][b[1]-1]);
            }
        }
    }
    cout<<ans+n+1;
}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4;
int dp[maxn][maxn];

int main() {
    string a,b; cin >> a >> b;
//    memset(dp, 1, sizeof(dp[0][0]) * maxn * maxn);
    for (int i=0; i<maxn; i++) for (int j=0; j<maxn; j++) dp[i][j]=1e9;
//    cout<<dp[5][3]<<endl;
    dp[0][0]=0;
    int n=a.size(),m=b.size();
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=m; j++) {
            if (i) dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
            if (j) dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
            if (i and j) dp[i][j]=min(dp[i][j],dp[i-1][j-1]+int(a[i-1]!=b[j-1]));
        }
    }
//    for (int i=0; i<10; i++) {
//        for (int j=0; j<10; j++) cout<<dp[i][j];
//        cout<<endl;
//    }
    cout<<dp[n][m];
}
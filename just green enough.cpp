#include <bits/stdc++.h>
using namespace std;

long long n;
bool ok[500][500];

long long numrects() {
    long long ans = 0;
    for (long long i=0; i<n; i++) {
        vector<bool> all1 (n, true);
        for (long long j=i; j<n; j++) {
            long long run = 0;
            for (long long k=0; k<n; k++) {
                all1[k] = ok[j][k]&all1[k];
                if (all1[k]) ans += ++run;
                else run=0;
            }
        }
    }
    return ans;
}

int main() {
    cin >> n;
    long long grid[500][500];
    for (long long i=0; i<n; i++) for (long long j=0; j<n; j++) cin >> grid[i][j];
    for (long long i=0; i<n; i++) for (long long j=0; j<n; j++) ok[i][j] = grid[i][j] >= 100;
    long long ans = numrects();
    for (long long i=0; i<n; i++) for (long long j=0; j<n; j++) ok[i][j] = grid[i][j] >= 101;
    cout << ans-numrects() << endl;
}
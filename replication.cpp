#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i=a; i<b; i++)
#define FOR(i, n) REP(i, 0, n)

const int mx = 1005;
int n, d, f[mx][mx], b[mx][mx], bitb[2*mx][mx], bitf[2*mx][mx], visited[mx][mx];
char g[mx][mx];

void updb(int i, int j, int v) {
    int row=n+i-j;
    int x = j+1;
    for (x; x<mx; x+=x&-x) bitb[row][x]+=v;
}
void updf(int i, int j, int v) {
    int row=i+j;
    int x = j+1;
    for (x; x<mx; x+=x&-x) bitf[row][x]+=v;
}
int sumb(int i, int j) {
    int row=n+i-j;
    int x = j;
    int sum = 0;
    for (; x; x-=x&-x) sum += bitb[row][x];
    return sum;
}
int sumf(int i, int j) {
    int row=i+j;
    int x = j;
    int sum = 0;
    for (; x; x-=x&-x) sum += bitf[row][x];
    return sum;
}

int main() {
    cin >> n >> d;
    queue<array<int, 3>> q;
    FOR(i, n) {
        string s;
        cin >> s;
        FOR(j, n) {
            if (s[j] == 'S') q.push({i, j, 0});
            g[i][j] = s[j];
        }
    }
    REP(row, -(n-1), n) {
        int i=0, j=0;
        if (row>0) i+=row;
        if (row<0) j-=row;
        while (i<n and j<n) {
            b[i+1][j+1]=b[i][j]+(g[i][j]=='#');
            i++; j++;
        }
    }
    REP(r, 0, 2*n-1) {
        int row = r;
        int i=0, j=0;
        while (i<n and row) {
            i++; row--;
        }
        while (j<n and row) {
            j++; row--;
        }
        while (i>0 and j<n) {
            f[i-1][j+1]=f[i][j]+(g[i][j]=='#');
            i--;
            j++;
        }
    }
    while (q.size()) {
        auto [i, j, day] = q.front(); q.pop();
        if (visited[i][j] and day%(d+1)) continue;
        visited[i][j] = 1;
        int sz = day/(d+1);
        updb(i, j+sz, -1); updb(i-sz-1, j-1, 1);
        updb(i+sz, j, -1); updb(i-1, j-sz-1, 1);
        updf(i-sz, j, -1); updf(i+1, j-sz-1, 1);
        updf(i, j+sz, -1); updf(i+sz+1, j-1, 1);
        if ((day+1)%(d+1)==0) {
            sz++;
            if (b[i+1][j+sz+1]-b[i-sz][j]==0 and b[i+sz+1][j+1]-b[i][j-sz]==0 and f[i-sz-1][j+1]-f[i][j-sz]==0 and f[i-1][j+sz+1]-f[i+sz][j]==0) q.push({i,j,day+1});
        }
        else {
            int x=i, y=j;
            i=x+1, j=y;
            if (b[i+1][j+sz+1]-b[i-sz][j]==0 and b[i+sz+1][j+1]-b[i][j-sz]==0 and f[i-sz-1][j+1]-f[i][j-sz]==0 and f[i-1][j+sz+1]-f[i+sz][j]==0) q.push({i,j,day+1});
            i=x-1, j=y;
            if (b[i+1][j+sz+1]-b[i-sz][j]==0 and b[i+sz+1][j+1]-b[i][j-sz]==0 and f[i-sz-1][j+1]-f[i][j-sz]==0 and f[i-1][j+sz+1]-f[i+sz][j]==0) q.push({i,j,day+1});
            i=x, j=y+1;
            if (b[i+1][j+sz+1]-b[i-sz][j]==0 and b[i+sz+1][j+1]-b[i][j-sz]==0 and f[i-sz-1][j+1]-f[i][j-sz]==0 and f[i-1][j+sz+1]-f[i+sz][j]==0) q.push({i,j,day+1});
            i=x, j=y-1;
            if (b[i+1][j+sz+1]-b[i-sz][j]==0 and b[i+sz+1][j+1]-b[i][j-sz]==0 and f[i-sz-1][j+1]-f[i][j-sz]==0 and f[i-1][j+sz+1]-f[i+sz][j]==0) q.push({i,j,day+1});
        }
    }
    int cnt = 0;
    FOR(i, n) {
        FOR(j, n) {
            if (sumb(i, j) or sumf(i, j)) cnt++;
        }
    }
    cout<<cnt;
}

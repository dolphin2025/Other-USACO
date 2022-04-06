#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i=0; i<n; i++)

const int maxn = 50005;
int breed[maxn], n, k, cansend[50][50], prv[maxn][50], nxt[maxn][50];

int main() {
    cin >> n >> k;
    FOR(i, n) cin >> breed[i], breed[i]--;
    FOR(i, k) {
        string s; (cin >> s);
        FOR(j, k) cansend[i][j] = s[j] - '0';
    }
    FOR(i, n) FOR(j, 50) prv[i][j] = -1, nxt[i][j] = -1;
    FOR(i, n - 1) FOR(j, 50) prv[i + 1][j] = prv[i][j], prv[i + 1][breed[i]] = i;
    for (int i = n - 1; i; i--) FOR(j, 50) nxt[i - 1][j] = j==breed[i] ? i : nxt[i][j];
    vector<int> dst(n, 1e9); dst[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; pq.push({0, 0});
    while (pq.size()) {
        auto[d, u] = pq.top(); pq.pop();
        if (dst[u] != d) continue;
        FOR(b, 50) {
            for (auto v: {prv[u][b], nxt[u][b]})
                if (v != -1 and abs(u - v) + d < dst[v] and cansend[breed[u]][breed[v]])
                    pq.push({dst[v] = dst[u] + abs(u - v), v});
            if (abs(n - 1 - u) + d < dst[n - 1] and cansend[breed[u]][breed[n - 1]])
                pq.push({dst[n - 1] = dst[u] + abs(n - 1 - u), n - 1});
        }
    }
    cout << (dst[n - 1] != 1e9 ? dst[n - 1] : -1);
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (long long i=a; i<b; ++i)
#define FOR(i, n) REP(i, 0, n)

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("cowcode");
    string s; cin >> s;
    long long k = s.size();
    long long x; cin >> x; x--;
    long long n = k; while (x > n) n <<= 1;
    for (; n != k; n /= 2) {
        if (x > n/2) x -= (n / 2 + 1);
        else if (x==n/2) x--;
    }
    cout << s[x];
}
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (long long i=0; i<n; i++)
#define REP(i, a, b) for (long long i=a; i<b; i++)

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);} }

long long n, a, b, ans, m=1000000007, e[1000000];

int main() {
    setIO("help");
    cin >> n;
    FOR(i, n) {
        cin >> a >> b;
        e[a-1]=b-1;
    }
    priority_queue<long long, vector<long long>, greater<long long>> ends;
    FOR(i, 2*n) {
        if (e[i]) {
            while (ends.size() and ends.top()<i) ends.pop();
            long long b=2, x=1;
            for (long long p = n-1-ends.size(); p; p/=2, b=b*b%m) if (p&1) x = x * b % m;
//            cout<<n-1-ends.size()<<endl;
//            cout<<x<<endl;
            ans += x;
            ends.push(e[i]);
        }
//        else ends.push(i);
    }
    cout << ans % m;N
}
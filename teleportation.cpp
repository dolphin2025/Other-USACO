#include <bits/stdc++.h> // see C++ Tips & Tricks
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin); // see Input & Output
        freopen((name+".out").c_str(), "w", stdout);
    }
}
int main() {
    setIO("teleport");
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << min({abs(a-b),abs(a-c)+abs(d-b),abs(a-d)+abs(c-b)}) << endl;
}
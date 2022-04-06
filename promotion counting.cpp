#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

void setIO(const string &name = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("promote");
    int f, l;
    int b = 0, s = 0, g = 0;
    cin >> f >> l;
    cin >> f >> l;
    b += l - f;
    cin >> f >> l;
    b += l - f;
    s += l - f;
    cin >> f >> l;
    b += l - f;
    s += l - f;
    g += l - f;
    cout << b << endl << s << endl << g << endl;
}

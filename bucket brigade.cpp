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
#define FOR(i, n) for (int i = 0; i < n; i++)

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
//    ifstream cin("buckets.in");
//    ofstream cout("buckets.out");
//    int bx, by, lx, ly, rx, ry;
//    string line;
//    for (int i = 0; i < 10; i ++) {
//        cin >> line;
//        size_t found = line.find('B');
//        if (found!=string::npos) {
//            bx = found;
//            by = i;
//        }
//        found = line.find('L');
//        if (found!=string::npos) {
//            lx = found;
//            ly = i;
//        }
//        found = line.find('R');
//        if (found!=string::npos) {
//            rx = found;
//            ry = i;
//        }
//    }
//    //cout<<bx<<" "<<rx<<" "<<lx<<endl;
//    //cout<<by<<" "<<ry<<" "<<ly<<endl;
//    if (bx==rx&&rx==lx && (by<ry&&ry<ly || ly<ry&&ry<by)) cout << abs(by - ly) + 1;
//    else if (by==ry&&ry==ly && (bx<rx&&rx<lx || lx<rx&&rx<bx)) cout << abs(bx - lx) + 1;
//    else cout << abs(bx - lx) + abs(by - ly) - 1;

    setIO("buckets");
    string line;
    FOR(i, 10) {
        cin >> line;
        FOR(j, 10) {
            if (line[j] == 'B') int b[2] = {i, j};
            if (line[j] == 'R') int r[2] = {i, j};
            if (line[j] == 'L') int l[2] = {i, j};
        }
    }
    if (r[0] ==)
}
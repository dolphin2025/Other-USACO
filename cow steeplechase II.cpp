#include <bits/stdc++.h>
typedef long long LL;

using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);} }

struct Point { LL x, y; int segindex; };
struct Segment { Point p, q; int index; };

bool operator< (Point p1, Point p2) { return p1.x==p2.x ? p1.y<p2.y : p1.x<p2.x; }

// Intersection testing (here, using a standard "cross product" trick)
int sign(LL x) { if (x==0) return 0; else return x<0 ? -1 : +1; }
int operator* (Point p1, Point p2) { return sign(p1.x * p2.y - p1.y * p2.x); }
Point operator- (Point p1, Point p2) { Point p = {p1.x-p2.x, p1.y-p2.y}; return p; }
bool isect(Segment &s1, Segment &s2)
{
    Point &p1 = s1.p, &q1 = s1.q, &p2 = s2.p, &q2 = s2.q;
    return ((q2-p1)*(q1-p1)) * ((q1-p1)*(p2-p1)) >= 0 && ((q1-p2)*(q2-p2)) * ((q2-p2)*(p1-p2)) >= 0;
}

int main() {
//    setIO("cowjump");
    vector<vector<int>> segs;
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        vector<int> seg = {0,0,0,0};
        cin >> seg[0] >> seg[1] >> seg[2] >> seg[3];
        segs.push_back(seg);
    }
    cout << 0;
}
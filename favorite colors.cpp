////#include <bits/stdc++.h>
////using namespace std;
////#define FOR(i, n) for (int i=0; i<n; i++)
////
////const int mx = 3e5;
////int sz[mx], p[mx], ei[mx], color[mx];
////set<int> e[mx];
////
////int get(int x) {
////    if (p[x]!=x) p[x]=get(p[x]);
////    return p[x];
////}
////
////void unite(set<int> s) {
//////    for(auto i: s) cout<<i+1;
//////    cout<<endl;
////    if (s.size()<2) return;
////    vector<int> sv;
////    for(auto i: s) sv.push_back(i);
////    FOR(i, s.size()-1) {
////        int x=get(sv[i]), y=get(sv[i+1]);
////        if (x!=y) {
////            if (sz[x]>sz[y]) swap(x, y);
////            p[x]=y; sz[y]+=sz[x];
////            if (e[ei[x]].size()>e[ei[y]].size()) {
////                for (auto v: e[ei[y]]) e[ei[x]].insert(v);
////                ei[y]=ei[x];
////            }
////            else {
////                for (auto v: e[ei[x]]) e[ei[y]].insert(v);
////            }
////        }
////    }
////    unite(e[ei[get(*s.rbegin())]]);
////}
////
////void setIO(string name = "") {
////    cin.tie(0)->sync_with_stdio(0);
////    if (name.size()) {
////        freopen((name + ".in").c_str(), "r", stdin);
////        freopen((name + ".out").c_str(), "w", stdout);}
////}
////
////int main() {
////    setIO("fcolor");
////    int n,m; cin >> n >> m;
////    FOR(i, m) {
////        int a, b; cin >> a >> b; a--; b--;
////        e[a].insert(b);
////    }
////    FOR(i, n) {
////        p[i]=i;
////        ei[i]=i;
////    }
////    for (auto s: e) unite(s);
////    int x = 0;
////    FOR(i, n) {
////        if (color[get(i)]==0) color[get(i)]=++x;
////        cout<<color[get(i)]<<endl;
////    }
////}
////
//
//#include <bits/stdc++.h>
//using namespace std;
//#define FOR(i, n) for (int i=0; i<n; i++)
//
//const int mx = 3e5;
//int sz[mx], p[mx], color[mx];
//vector<int> e[mx];
//
//queue<int> q;
//
//int get(int x) { return p[x]==x ? x : p[x]=get(p[x]); }
//int cnt, cnt2;
//void unite(int x, int y) {
////    cnt++;
////    cout<<cnt<<endl;
////    cout<<x+1<<y+1<<endl;
//    x = get(x), y = get(y);
////    cout<<x+1<<y+1<<endl;
//    if (x==y) return;
//    cnt2++;
//    cout<<' '<<cnt2<<endl;
////    if (sz[x]>sz[y]) swap(x, y);
////    p[x]=y; sz[y]+=sz[x];
////    if (e[ei[x]].size()>e[ei[y]].size()) {
////        for (auto v: e[ei[y]]) e[ei[x]].push_back(v);
////        ei[y]=ei[x];
////    }
////    else {
////        for (auto v: e[ei[x]]) e[ei[y]].push_back(v);
////    }
////    FOR(i, (int)(e[ei[y]].size())-1) {
////        unite(e[ei[y]][i], e[ei[y]][i+1]);
////    }
//    if (sz[x]>sz[y]) swap(x, y);
//    p[x]=y; sz[y] += sz[x]+1;
//    for (auto v: e[x]) e[y].push_back(v);
////    if (e[x].size()) unite(e[y][e[y].size()-e[x].size()-1],e[y][e[y].size()-e[x].size()]);
//    FOR(i, int(e[y].size())-1) unite(e[y][i], e[y][i+1]);
//}
//
//void setIO(string name = "") {
////    cin.tie(0)->sync_with_stdio(0);
//    if (name.size()) {
////        cout<<0<<endl;
//        freopen((name + ".in").c_str(), "r", stdin);
////        cout<<0<<endl;
////        freopen((name + ".out").c_str(), "w", stdout);
////        cout<<0<<endl;
//    }
//}
//
//int main() {
////    cout<<0<<endl;
//    setIO("4");
//    int n, m; cin >> n >> m;
//    FOR(i, m) {
//        int a, b; cin >> a >> b;
//        e[a-1].push_back(b-1);
//    }
//    FOR(i, n) p[i] = i;
//    for (auto s: e) FOR(i, int(s.size())-1) unite(s[i], s[i+1]);
//    int x = 0;
//    FOR(i, n) {
//        if (!color[get(i)]) color[get(i)] = ++x;
//        cout << color[get(i)] << endl;
//    }
//}


#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i=0; i<n; i++)

const int mx = 3e5;
int sz[mx], p[mx], color[mx];
vector<int> e[mx];

queue<int> q;

int get(int x) { return p[x]==x ? x : p[x]=get(p[x]); }

void unite(int x, int y) {
//    cout<<x+1<<y+1<<endl;
    x = get(x), y = get(y);
//    cout<<x+1<<y+1<<endl;
    if (x==y) return;
//    if (sz[x]>sz[y]) swap(x, y);
//    p[x]=y; sz[y]+=sz[x];
//    if (e[ei[x]].size()>e[ei[y]].size()) {
//        for (auto v: e[ei[y]]) e[ei[x]].push_back(v);
//        ei[y]=ei[x];
//    }
//    else {
//        for (auto v: e[ei[x]]) e[ei[y]].push_back(v);
//    }
//    FOR(i, (int)(e[ei[y]].size())-1) {
//        unite(e[ei[y]][i], e[ei[y]][i+1]);
//    }
    if (sz[x]>sz[y]) swap(x, y);
    p[x]=y; sz[y] += sz[x]+1;
    for (auto v: e[x]) e[y].push_back(v);
    while (e[y].size()>1) {
        int l = e[y].back(); e[y].pop_back();
        unite(l, e[y].back());
    }
}

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);}
}

int main() {
    setIO("fcolor");
    int n, m; cin >> n >> m;
    FOR(i, m) {
        int a, b; cin >> a >> b;
        e[a-1].push_back(b-1);
    }
    FOR(i, n) p[i] = i;
    FOR(v, n) while (e[v].size()>1) {
        int l = e[v].back(); e[v].pop_back();
            unite(l, e[v].back());
    }
    int x = 0;
    FOR(i, n) {
        if (!color[get(i)]) color[get(i)] = ++x;
        cout << color[get(i)] << endl;
    }
}
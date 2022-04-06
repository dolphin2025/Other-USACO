#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> E;
    vector<vector<int>> N;
    for (int i=0; i<n; i++) {
        char a; int b,c;
        cin >> a >> b >> c;
        if (a=='N') N.push_back({b,c,i});
        else E.push_back({b,c,i});
    }
    sort(begin(N), end(N), [](const vector<int> &a, const vector<int> &b){return a[0]<b[0];});
    sort(begin(E), end(E), [](const vector<int> &a, const vector<int> &b){return a[1]<b[1];});
    vector<int> blame(n,0);
    vector<bool> alive(n,1);
    for (auto north: N) {
        for (auto east: E) {
            if (east[0]<north[0] and north[1]<east[1] and alive[north[2]] and alive[east[2]]) {
                if (north[0]-east[0]>east[1]-north[1]) {
                    blame[north[2]] += blame[east[2]] + 1;
                    alive[east[2]] = 0;
//                    cout << north[2]+1 << east[2]+1 <<endl;
                }
                if (north[0]-east[0]<east[1]-north[1]) {
//                    cout << east[2]+1 << north[2]+1 <<endl;
                    alive[north[2]] = 0;
                    blame[east[2]] += blame[north[2]] + 1;
                }
            }
        }
    }
    for (auto i: blame) cout<<i<<endl;
}

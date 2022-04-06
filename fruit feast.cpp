#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);} }

int main() {
    setIO("feast");
    int t,a,b; cin >> t >> a >> b;
    vector<bool> nodrink(t, 0);
    vector<bool> drink(t, 0);
    nodrink[0]=1;
    for (int i=0; i<=t; i++) {
        if (i-a>=0 and nodrink[i-a]) nodrink[i]=1;
        if (i-a>=0 and drink[i-a]) drink[i]=1;
        if (i-b>=0 and nodrink[i-b]) nodrink[i]=1;
        if (i-b>=0 and drink[i-b]) drink[i]=1;
        if (nodrink[i]) drink[i/2]=1;
    }
    for (int i=0; i<=t; i++) {
        if (i-a>=0 and drink[i-a]) drink[i]=1;
        if (i-b>=0 and drink[i-b]) drink[i]=1;
    }
    for (int i=t; i>=0; i--) {
        if (nodrink[i] or drink[i]) {
            cout << i;
            break;
        }
    }
}
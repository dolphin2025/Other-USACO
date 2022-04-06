#include "bits/stdc++.h"
using namespace std;

int divisors[1000001];

int main() {
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        for (int d=1; d*d<=x; d++) {
            if (x%d==0) {
//                cout<<x<<' '<<x/d<<endl;
                divisors[d]++;
                if (x/d!=d) divisors[x/d]++;
            }
        }
    }
//    for (auto i: divisors) cout << i;
    for (int i=1000000; i; i--) {
//        cout<<i<<' '<<divisors[i]<<endl;
        if (divisors[i]>1) {
            cout << i;
            break;
        }
    }
}
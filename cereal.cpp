#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);} }

int main() {
    setIO("cereal");
    int n,m; cin >> n >> m;
    int f[n];
    int s[n];
    for (int i=0; i<n; i++) {
        int a,b; cin >> a >> b;
        f[i]=a-1;
        s[i]=b-1;
    }
    vector<int> ans;
    int num=0;
    vector<int> took(m, n);
    for (int i=n-1; i>=0; i--) {
        num++;
        if (took[f[i]]!=n) {
            int cereal = f[i];
            int cow = took[cereal];
            while (cow!=n) {
                if (f[cow]==cereal) {
                    if (took[s[cow]]>cow) {
                        cereal=s[cow];
                        int ncow=took[s[cow]];
                        took[s[cow]]=cow;
                        cow=ncow;
                    }
                    else {
                        num--;
                        break;
                    }
                }
                else {
                    num--;
                    break;
                }
            }
        }
        took[f[i]]=i;
        ans.push_back(num);
    }
    for (int i=n-1; i>=0; i--) cout << ans[i] << endl;
}

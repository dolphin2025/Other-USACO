#include <bits/stdc++.h>
using namespace std;

vector<int> numstrokes(int n, string s) {
    vector<int> list = {0};
    int num = 0;
    set<char> letters;
    for (int i=0; i<n; i++) {
        char c = s[i];
        if (!letters.count(c)) {
            num+=1;
            letters.insert(c);
        }
        set<char> nletters;
        for (auto l: letters) if (l<=c) nletters.insert(l);
        letters = nletters;
        list.push_back(num);
    }
    return list;
}

int main() {
    int n,q; cin >> n >> q;
    string s; cin >> s;
    vector<int> strokes = numstrokes(n, s);
    string ns;
    for (int i=n-1; i>=0; i--) {
        ns+=s[i];
    }
    vector<int> nstrokes = numstrokes(n, ns);
    for (int i=0; i<q; i++) {
        int a, b; cin >> a >> b;
        cout<<strokes[a-1]+nstrokes[n-b]<<endl;
    }
//    cout<<0;
}

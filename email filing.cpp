#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < n; ++i)

string solve() {
    int m, n, k; cin >> m >> n >> k;
    int start = 0, end = k, fold = 0;
    vector<int> emails(n), cnt(m, 0), del(n, 0); vector<set<int>> active(m); stack<int> toremove;
    for (auto &i: emails) cin >> i, i--, cnt[i]++;
    FOR(i, end) {
        if (emails[i] < k) {
            del[i] = 1; cnt[emails[i]]--;
            if (end++ == n) return "YES";
        } else active[emails[i]].insert(i);
    }
    while (1) {
        while (toremove.size()) {
            int remove = toremove.top(); toremove.pop();
            del[remove] = 1; active[emails[remove]].erase(remove); cnt[emails[remove]]--;
            if (end==n) {
                for (; del[start]; start--) if (start<=0) return "YES";
                active[emails[start]].insert(start);
                if (emails[start] >= fold and emails[start] < fold + k and !del[start]) toremove.push(start);
            }
            else {
                active[emails[end]].insert(end);
                if (emails[end] >= fold and emails[end] < fold + k and !del[end]) toremove.push(end); end++;
            }
        }
        if (!cnt[fold] and fold+k!=m) for (auto i: active[fold++ + k]) toremove.push(i);
        else {
            if (end == n) return "NO";
            active[emails[end]].insert(end);
            if (emails[end] >= fold and emails[end] < fold + k and !del[end]) toremove.push(end); end++;
            while (del[start]) start++; active[emails[start]].erase(start); start++;
        }
    }
}

int main() {
    int t; cin >> t; while(t--) cout << solve() << endl;
}

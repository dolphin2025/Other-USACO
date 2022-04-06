#include <bits/stdc++.h>

using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);}
}

int main() {
    setIO("convention2");
    int n;
    cin >> n;
    vector<vector<int>> cows;
    for (int i=1; i<n+1; i++) {
        int s, e;
        cin >> s >> e;
        cows.push_back({-i, s, e});
    }
    sort(cows.begin(), cows.end(), [](const vector<int>& x, const vector<int>& y) {return x[1]<y[1];});
    int maxwait=0, i=1, time=cows[0][1]+cows[0][2];
    priority_queue<vector<int>> waiting;
    vector<int> nextup;
    while ((!waiting.empty()) or i<n) {
        while (i<n) {
            if (cows[i][1]<=time) {
                waiting.push(cows[i]);
                i++;
            }
            else break;
        }
        if (!waiting.empty()) {
            nextup = waiting.top();
            waiting.pop();
            maxwait = max(maxwait, time-nextup[1]);
            time += nextup[2];
        }
        else if (i<n){
                time=cows[i][1]+cows[i][2];
                i++;
        }
    }
    cout << maxwait;
}

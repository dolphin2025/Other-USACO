#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define ub upper_bound
#define lb lower_bound
#define f first
#define s second
#define mp make_pair
#define FOR(i, n) for(int i = 0; i < n; ++i)

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(name)) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);}
}

struct event {
    int lifeguard;
    int time;
    bool start;
};

int main() {
    setIO("lifeguards");
    int n;
    cin >> n;
    vector<event> events;
    set<int> OnDuty;
    int timeAlone[n];
    for(auto& a: timeAlone) a = 0;
    int totalTime = 0;
    int st, end;
    event startevent, endevent;
    FOR(i, n) {
        cin >> st >> end;
        startevent.lifeguard = i;
        startevent.time = st;
        startevent.start = true;
        endevent.lifeguard = i;
        endevent.time = end;
        endevent.start = false;
        events.pb(startevent);
        events.pb(endevent);
    }
    sort(begin(events), events.end(),[](const event& x, const event& y) {return x.time < y.time; });
    int currentTime = events[0].time;
//    for (auto i: events) {
//        cout << i.lifeguard << i.time << i.start << endl;
//    }
    for (auto i: events) {
//        cout << i.lifeguard << i.time << i.start << endl;
        if (OnDuty.size() > 0) {
            totalTime += i.time - currentTime;
        }
        if (OnDuty.size() == 1) {
            timeAlone[*OnDuty.begin()] += i.time - currentTime;
        }

        if (i.start) OnDuty.insert(i.lifeguard);
        else OnDuty.erase(i.lifeguard);
        currentTime = i.time;
//        for (auto l: OnDuty) cout << l << endl;
//        cout << currentTime << totalTime << endl;
//        for (auto l: timeAlone) cout << l << endl;
    }
    
    cout << totalTime - *min_element(timeAlone, timeAlone+n);
}

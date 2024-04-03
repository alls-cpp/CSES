// https://cses.fi/paste/77925c013c154e428796ca/
#include <bits/stdc++.h>
#ifdef ALE
	#include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
	#define dbg(...)
#endif
using namespace std;

#define int long long
void solve() {
    int n; cin >> n;
    vector<int> v;
    bool flag = true;
    for (int i = 1; i <= n; i+=2) v.push_back(i);
    for (int i = 2; i <= n; i+=2) v.push_back(i);
    for (int i = 1; flag && i < n; i++) {
        if (abs(v[i - 1] - v[i]) == 1) {
            flag = false;
        }
    }
    if (flag) {
        for (auto _ : v) cout << _ << ' ';
        return;
    }
    v = {};
    for (int i = 2; i <= n; i+=2) v.push_back(i);
    for (int i = 1; i <= n; i+=2) v.push_back(i);
    for (int i = 1; i < n; i++) {
        if (abs(v[i -1] - v[i]) == 1) {
            cout << "NO SOLUTION\n"; return;
        }
    }
    for (auto _ : v) cout << _ << ' ';
}
 
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    for (int TEST_CASE = 1; TEST_CASE <= t; TEST_CASE++) {
        solve();
    }
}

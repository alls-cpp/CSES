// https://cses.fi/paste/822d9a9f61cd5f6d8796a3/
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
    vector<int> v(n); for (auto &_ : v) cin >> _;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans += max(0ll, -v[i] + v[i - 1]);
        v[i] = max(v[i], v[i - 1]);
        dbg(v, ans);
    }
    cout << ans;
}
 
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    for (int TEST_CASE = 1; TEST_CASE <= t; TEST_CASE++) {
        dbg(TEST_CASE);
        solve();
    }
}

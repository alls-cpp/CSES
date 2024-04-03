// https://cses.fi/paste/787d5c07427cb8b287967c/
#include <bits/stdc++.h>
#ifdef ALE
	#include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
	#define dbg(...)
#endif
using namespace std;

void solve() {
    string s; cin >> s;
    s.push_back('_');
    int ans = 1;
    for (int i = 1, tmp = 1; i < (int)s.size(); i++, tmp++) {
        if (s[i - 1] != s[i]) {
            ans = max(ans, tmp);
            tmp = 0;
        }
    }
    cout << ans << '\n';
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

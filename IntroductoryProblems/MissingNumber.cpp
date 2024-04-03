// https://cses.fi/paste/2536ad018a9abc05879651/
#include <bits/stdc++.h>
#ifdef ALE
	#include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
	#define dbg(...)
#endif
using namespace std;

void solve() {
    long long n; cin >> n;
    long long ans = n * (n + 1) / 2;
    while (--n) {
        int _; cin >> _; ans -= _;
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

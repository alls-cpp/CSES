// https://cses.fi/paste/5d97804eddea8792879644/
#include <bits/stdc++.h>
#ifdef ALE
	#include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
	#define dbg(...)
#endif
using namespace std;

void solve() {
    long long n; cin >> n;
    while (n != 1) {
        cout << n << ' ';
        if (n % 2 == 0) n /= 2;
        else n = n * 3 + 1;
    }
    cout << 1 << '\n';
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

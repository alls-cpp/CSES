// https://cses.fi/paste/470febacae4eb09287fd1d/
#include <bits/stdc++.h>
#ifdef ALE
	#include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
	#define dbg(...)
#endif
using namespace std;

void solve() {
    int n; cin >> n;
    set<int> sett;
    while (n--) {
        int tmp; cin >> tmp; sett.insert(tmp);
    }
    cout << sett.size();
}
 
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    for (int TEST_CASE = 1; TEST_CASE <= t; TEST_CASE++) {
        dbg(TEST_CASE);
        solve();
    }
}

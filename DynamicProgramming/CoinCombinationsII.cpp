// https://cses.fi/paste/34c34e0a47dd7be78d5e20/
#include <bits/stdc++.h>
#ifdef ALE
#include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
#define dbg(...)
#endif
using namespace std;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
	int mod = 1e9 + 7;
	int n, x; cin >> n >> x;
	vector<int> v(n); for (auto &_ : v) cin >> _;
	vector<int> dp(x + 1);
	dp[0] = 1;
	for (auto val : v) {
		for (int i = val; i <= x; i++) {
			dp[i] += dp[i - val];
			dp[i] %= mod;
		}
	}
	cout << dp[x] << '\n';
}

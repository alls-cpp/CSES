// https://cses.fi/paste/614eba2d8a91e91f8d5e0d/
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
	for (int i = 1; i <= x; i++) {
		for (auto val : v) if (val <= i) {
			dp[i] += dp[i - val];
			dp[i] %= mod;
		}
	}
	cout << dp[x] << '\n';
}

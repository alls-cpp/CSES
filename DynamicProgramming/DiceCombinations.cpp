// https://cses.fi/paste/7c2258cfd14656628d5d86/
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
	int n; cin >> n;
	vector<int> dp(n + 1);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; i - j >= 0 && j <= 6; j++) {
			dp[i] += dp[i - j];
			dp[i] %= mod;
		}
	}
	cout << dp[n] << '\n';
}

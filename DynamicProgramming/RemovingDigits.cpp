// https://cses.fi/paste/331a82163e1063a38d5e60/
#include <bits/stdc++.h>
#ifdef ALE
#include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
#define dbg(...)
#endif
using namespace std;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> dp(n + 1, 1e9);
	dp[n] = 0;
	for (int i = n; i >= 0; i--) if (i == n || dp[i] != 1e9) {
		string s = to_string(i);
		for (auto c : s) {
			dp[i - (c - '0')] = min(dp[i - (c - '0')], dp[i] + 1);
		}
	}
	cout << dp[0] << '\n';
}

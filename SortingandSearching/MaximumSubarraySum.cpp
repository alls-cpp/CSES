// https://cses.fi/paste/b57808ba0067dd818b2e1a/
#include <bits/stdc++.h>
#ifdef ALE
	#include "/home/userland/CompetitiveProgramming/Library/debug.h"
#else
	#define dbg(...)
#endif
using namespace std;
/*
4 8
2 7 5 1
*/
#define int long long
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> v(n); for (auto &_ : v) cin >> _;
	vector<int> pref(n + 1);
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + v[i - 1];
	}
	int ans = v[0], minn = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, pref[i + 1] - minn);
		minn = min(minn, pref[i + 1]);
	}
	cout << ans << '\n';
}

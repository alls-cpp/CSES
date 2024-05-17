// https://cses.fi/paste/2411c51cb72041718b31ad/
#include <bits/stdc++.h>
#ifdef ALE
	#include "/home/userland/CompetitiveProgramming/Library/debug.h"
#else
	#define dbg(...)
#endif
using namespace std;
#define int long long
/*
5
1 4 5 100 100
*/
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> v(n); for (auto &_ : v) cin >> _;
	sort(v.begin(), v.end());
	int ans = accumulate(v.begin(), v.end(), 0LL);
	vector<int> pref(n + 1);
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + v[i - 1];
	}
	dbg(v);
	int miao = 0;
	for (int i = 0; i < n; i++) {
		dbg(i);
		int tmp_ans = 0;
		if (i != 0) {
			miao += (v[i] - v[i - 1]) * i;
			tmp_ans += miao;
		}
		dbg(tmp_ans);
		if (i != n - 1) {
			tmp_ans += pref[n] - pref[i + 1] - v[i] * (n - 1 - i);
		}
		dbg(tmp_ans);
		ans = min(tmp_ans, ans);
	}
	cout << ans << endl;
}

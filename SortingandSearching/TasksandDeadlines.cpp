// https://cses.fi/paste/ac2a0ef4f08a9b898cb85f/
#include <bits/stdc++.h>
#ifdef ALE
	#include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
	#define dbg(...)
#endif
using namespace std;
#define int long long
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	int ans = 0;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> v[i] >> tmp;
		ans += tmp;
	}
	sort(v.begin(), v.end());
	vector<int> pref(n + 1);
	for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + v[i];
	cout << ans - accumulate(pref.begin(), pref.end(), 0LL) << '\n';
}

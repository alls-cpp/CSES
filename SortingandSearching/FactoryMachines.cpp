// https://cses.fi/paste/ff0b82f56a2bca0f8cb62e/
#include <bits/stdc++.h>
#ifdef ALE
	#include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
	#define dbg(...)
#endif
using namespace std;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
	int n, k; cin >> n >> k;
	vector<long long> v(n); for (auto &_ : v) cin >> _;
	long long l, h;
	l = 0, h = LONG_LONG_MAX;
	while (l + 1 < h) {
		long long m = (l - h) / 2 + h;
		long long ans = 0;
		for (int i = 0; ans < k && i < n; i++)
			ans += m / v[i];
		if (ans < k) l = m;
		else h = m;
	}
	cout << h << '\n';
}

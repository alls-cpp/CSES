// https://cses.fi/paste/a75eb28360520cd28b7599/
#include <bits/stdc++.h>
#ifdef ALE
	#include "/home/userland/CompetitiveProgramming/Library/debug.h"
#else
	#define dbg(...)
#endif
using namespace std;
#define int long long
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> a(n); for (auto &_ : a) cin >> _;
	sort(a.begin(), a.end());
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum + 1 < a[i]) break;
		sum += a[i];
	}
	cout << sum + 1 << endl;
}

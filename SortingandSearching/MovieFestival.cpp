// https://cses.fi/paste/116d52a05458086b8b2cf3/
#include <bits/stdc++.h>
#ifdef ALE
	#include "/home/userland/CompetitiveProgramming/Library/debug.h"
#else
	#define dbg(...)
#endif
using namespace std;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<pair<int, int>> v(n); for (auto &[a, b] : v) cin >> a >> b;
	sort(v.begin(), v.end());
	set<pair<int, int>> st;
	for (auto [a, b] : v) {
		st.insert({b, a});
	}
	int ans = 0, index = 0;
	while (!st.empty()) {
		dbg(st);
		ans++;
		auto [b, a] = *st.begin();
		while (index < n && v[index].first < b) {
			st.erase({v[index].second, v[index].first});
			index++;
		}
	}
	cout << ans << '\n';
}

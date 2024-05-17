// https://cses.fi/paste/63c2e2aee12411418cb4f1/
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
	// start, end, idx
	vector<pair<int, int>> v(n);
	// start, idx
	set<pair<int, int>> s;
	vector<int> ans(n);
	for (int i = 0; i < n; i++) { cin >> v[i].first >> v[i].second; s.insert({v[i].first, i}); }
	int i;
	for (i = 1; !s.empty(); i++) {
		ans[s.begin()->second] = i;
		auto x = v[s.begin()->second].second;
		s.erase(s.begin());
		auto it = s.upper_bound({x + 1, -1});
		while (it != s.end()) {
			ans[it->second] = i;
			x = v[it->second].second;
			s.erase(it);
			it = s.upper_bound({x + 1, -1});
		}
	}
	cout << i - 1 << '\n';
	for (auto x : ans) cout << x << ' ';
}

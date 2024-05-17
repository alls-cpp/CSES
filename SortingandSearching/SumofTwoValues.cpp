// https://cses.fi/paste/f285729c980f24f38b2d66/
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
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
	int n, x; cin >> n >> x;
	set<pair<int, int>> st;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		st.insert({a, i});
	}
	for (auto [a, i] : st) {
		int v = 0;
		if (x - a == a) v = i;
		auto it = st.upper_bound({x - a, v});
		if (it == st.end() || it->first != x - a) continue;
		cout << i << ' ' << it->second << '\n';
		return 0;
	}
	cout << "IMPOSSIBLE\n";
}

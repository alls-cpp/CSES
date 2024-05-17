// https://cses.fi/paste/38df47f8789550b78b2aef/
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
	map<int, int> mapp;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		mapp[a]++;
		mapp[b]--;
	}
	int ans = 0, tmp_ans = 0;
	for (auto [a, b] : mapp) {
		tmp_ans += b;
		ans = max(ans, tmp_ans);
	}
	cout << ans << '\n';
}

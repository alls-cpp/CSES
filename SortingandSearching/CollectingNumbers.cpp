// https://cses.fi/paste/6491a735e23c61508b763f/
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
	unordered_set<int> st;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (st.count(a[i] - 1) == 0)
			ans++;
		st.insert(a[i]);
	}
	cout << ans << endl;
}

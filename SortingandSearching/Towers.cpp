// https://cses.fi/paste/f086ea44279c0cad8c667d/
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
	vector<int> a(n); for (auto &_ : a) cin >> _;
	multiset<int> st;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		auto it = st.upper_bound(a[i]);
		if (it == st.end()) {
			ans++;
			st.insert(a[i]);
		} else {
			st.erase(it);
			st.insert(a[i]);
		}
	}
	cout << ans << endl;
}

// https://cses.fi/paste/da28c5f0cfe33fe08c87b9/
#include <bits/stdc++.h>
#ifdef ALE
	#include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
	#define dbg(...)
#endif
using namespace std;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
	int x, n; cin >> x >> n;
	set<int> lights = {0, x};
	multiset<int> ans = {x};
	while (n--) {
		int a; cin >> a;
		auto it = lights.upper_bound(a);
		int r = *it, l = *(--it);
		ans.erase(ans.lower_bound(r - l));
		ans.insert(a - l);
		ans.insert(r - a);
		lights.insert(a);
		cout << *ans.rbegin() << ' ';
	}
}

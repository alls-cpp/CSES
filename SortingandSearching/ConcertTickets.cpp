// https://cses.fi/paste/b763b518f936e38e8b2a79/
#include <bits/stdc++.h>
#ifdef ALE
	#include "/home/userland/CompetitiveProgramming/Library/debug.h"
#else
	#define dbg(...)
#endif
using namespace std;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	multiset<int> sett;
	for (int i = 0; i < n; i++) {
		int _; cin >> _; sett.insert(_);
	}
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		auto it = sett.upper_bound(a);
		if (it == sett.begin()) {
			cout << "-1\n";
			continue;
		}
		it--;
		cout << *it << '\n';
		sett.erase(it);
	}
}

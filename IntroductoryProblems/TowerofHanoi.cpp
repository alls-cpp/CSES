// https://cses.fi/paste/a927af63dad4ab6d881d24/
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
    vector<pair<int, int>> ans;
    auto f = [&](auto&& f, int nn, int start, int mid, int end) -> void {
        if (nn == 0) return;
        f(f, nn - 1, start, end, mid);
        ans.push_back({start, end});
        f(f, nn - 1, mid, start, end);
    };
    f(f, n, 1, 2, 3);
    cout << ans.size() << '\n';
    for (auto [a, b] : ans) cout << a << ' ' << b << '\n';
}

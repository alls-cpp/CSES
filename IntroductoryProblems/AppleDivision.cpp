// https://cses.fi/paste/096a4134bf3faf7187e6a2/
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
    vector<int> v(n); for (auto &_ : v) cin >> _;
    long long ans = accumulate(v.begin(), v.end(), 0LL);
    for (long long i = 0; i <= (1 << n); i++) {
        long long a, b; a = b = 0;
        for (long long j = 0; j < n; j++) {
            if (i & (1 << j)) a += v[j];
            else b += v[j];
        }
        ans = min(ans, abs(a - b));
    }
    cout << ans;
}

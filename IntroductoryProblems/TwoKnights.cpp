// https://cses.fi/paste/6d3c5ed546dca168879800/
#include <bits/stdc++.h>
#ifdef ALE
	#include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
	#define dbg(...)
#endif
using namespace std;

#define int long long
void solve() {
    int n; cin >> n;
    vector<int> dp{0, 0, 6, 28};
    for (int i = 1; i <= n; i++) {
        if (i < 4) {
            cout << dp[i] << '\n';
            continue;
        }
        int ans = (i - 4) * (i - 4)     * (i * i - 9);
        ans     += 4 * (i - 4)          * (i * i - 7);
        ans     += 4                    * (i * i - 5);
        ans     += 4 * (i - 4)          * (i * i - 5);
        ans     += 8                    * (i * i - 4);
        ans     += 4                    * (i * i - 3);
        cout << ans / 2 << '\n';
    }
}
 
int32_t main() {cin.tie(0)->sync_with_stdio(0); solve();}

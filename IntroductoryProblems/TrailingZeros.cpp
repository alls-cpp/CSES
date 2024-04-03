// https://cses.fi/paste/3612778bf4c7c28e87994d/
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
    int ans = 0;
    for (int i = 5; n / i != 0; i *= 5) {
        ans += n / i;
    }
    cout << ans << '\n';
}
 
int32_t main() {cin.tie(0)->sync_with_stdio(0); solve();}

// https://cses.fi/paste/9e16f99da48e1805879917/
#include <bits/stdc++.h>
#ifdef ALE
	#include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
	#define dbg(...)
#endif
using namespace std;

#define int long long
void solve() {
    int mod = 1e9 + 7;
    int n; cin >> n;
    int base = 2;
    int ans = 1;
    while (n != 0) {
        dbg(n, ans, base);
        if (n % 2 == 1) ans *= base;
        base *= base;
        n /= 2ll;
        ans %= mod;
        base %= mod;
    }
    cout << ans << '\n';
}
 
int32_t main() {cin.tie(0)->sync_with_stdio(0); solve();}

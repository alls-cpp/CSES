// https://cses.fi/paste/4927a3bf05b55eb1879a37/
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
    while (n--) {
        int l, r; cin >> l >> r;
        if (l - 2 * r <= 0 &&
            (l - 2 * r) % 3 == 0 &&
            r + 2 * ((l - 2 * r) / 3) >= 0) {
            cout << "YES\n";
            continue;
        }
        swap(l, r);
        if (l - 2 * r <= 0 &&
            (l - 2 * r) % 3 == 0 &&
            r + 2 * ((l - 2 * r) / 3) >= 0) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
}
 
int32_t main() {cin.tie(0)->sync_with_stdio(0); solve();}

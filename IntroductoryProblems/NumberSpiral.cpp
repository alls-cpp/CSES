// https://cses.fi/paste/efdc48af752641f8879796/
#include <bits/stdc++.h>
#ifdef ALE
	#include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
	#define dbg(...)
#endif
using namespace std;

#define int long long
void solve() {
    int q; cin >> q;
    while (q--) {
        int n, m; cin >> n >> m;
        if (n > m) {
            if (n % 2 == 1) {
                n--;
                cout << n * n + m;
            } else {
                cout << n * n - m + 1;
            }
        } else {
            if (m % 2 == 0) {
                m--;
                cout << m * m + n;
            } else {
                cout << m * m - n + 1;
            }
        }
        cout << '\n';
    }
}
 
int32_t main() {cin.tie(0)->sync_with_stdio(0); solve();}

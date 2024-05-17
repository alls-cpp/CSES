// https://cses.fi/paste/b36971a4592e5b4b8b0ea5/
#include <bits/stdc++.h>
#ifdef ALE
	#include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
	#define dbg(...)
#endif
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto &_ : a) cin >> _;
    for (auto &_ : b) cin >> _;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i, j, ans;
    i = j = ans = 0;
    while (i < n && j < m) {
        if (abs(a[i] - b[j]) <= k) {
            ans++;
            i++;
            j++;
        } else if (b[j] < a[i]) {
            j++;
        } else {
            i++;
        }
    }
    cout << ans << endl;
}

// https://cses.fi/paste/c7612801dc71c7498b0fcf/
#include <bits/stdc++.h>
#ifdef ALE
	#include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
	#define dbg(...)
#endif
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x; cin >> n >> x;
    vector<int> a(n); for (auto &_ : a) cin >> _;
    sort(a.begin(), a.end());
    int i = 0, j = n - 1, ans = 0;
    while (i <= j) {
        if (a[j] + a[i] <= x)
            i++;
        ans++;
        j--;
    }
    cout << ans << endl;
}

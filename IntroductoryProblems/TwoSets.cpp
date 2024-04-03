// https://cses.fi/paste/9ba9f41a005a08058798c8/
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
    if (n % 4 == 1 ||
        n % 4 == 2) {
        cout << "NO\n"; return;
    }
    vector<int> v1, v2;
    bool flag = (n % 4 == 0);
    for (int i = 1; i <= n / 2; i++) {
        if (i % 2 == 1) {
            v1.push_back(i);
            v1.push_back(n - i + flag);
        } else {
            v2.push_back(i);
            v2.push_back(n - i + flag);
        }
    }
    if (!flag) {
        v2.push_back(n);
    }
    cout << "YES\n";
    cout << v1.size() << '\n';
    for (auto _ : v1) cout << _ << ' ';
    cout << '\n';


    cout << v2.size() << '\n';
    for (auto _ : v2) cout << _ << ' ';
    cout << '\n';
}
 
int32_t main() {cin.tie(0)->sync_with_stdio(0); solve();}

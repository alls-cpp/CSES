// https://cses.fi/paste/b82e947b0479b5ef879a76/
#include <bits/stdc++.h>
#ifdef ALE
	#include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
	#define dbg(...)
#endif
using namespace std;

#define int long long
void solve() {
    string s; cin >> s;
    map<char, int> mapp;
    for (auto _ : s) mapp[_]++;
    string aa = "_";
    string ans = "";
    dbg(mapp);
    for (auto [a, b] : mapp) {
        if (b % 2 == 1) {
            if (aa != "_") {
                cout << "NO SOLUTION\n";
                return;
            }
            aa = a;
        }
        ans += string(b/2, a);
    }
    ans = ans + (aa != "_" ? aa : "") + string(ans.rbegin(), ans.rend());
    cout << ans << '\n';
}
 
int32_t main() {cin.tie(0)->sync_with_stdio(0); solve();}

// https://cses.fi/paste/fa72aa1ada7b62aa87d40e/
#include <bits/stdc++.h>
#ifdef ALE
	#include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
	#define dbg(...)
#endif
using namespace std;
/*
 f(n):
    if n == 1:
        {0, 1}
    ans = {}
    pref = f(n - 1)
    for (s : pref)
        ans.append(s + '0')
    for (s : pref.reverse)
        ans.append(s + '1')
    return ans
*/
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> ans{0, 1};
    for (int i = 2; i <= n; i++) {
        vector<int> new_ans;
        for (auto s : ans) new_ans.push_back(s << 1);
        reverse(ans.begin(), ans.end());
        for (auto s : ans) new_ans.push_back((s << 1) + 1);
        ans = new_ans;
    }
    for (auto s : ans) cout << bitset<16>(s).to_string().substr(16 - n) << '\n';
}

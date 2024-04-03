// https://cses.fi/paste/1136ac9b4804ac8587e294/
#include <bits/stdc++.h>
#ifdef ALE
	#include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
	#define dbg(...)
#endif
using namespace std;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    sort(s.begin(), s.end());
    vector<int> fact(9, 1);
    for (int i = 1; i < 10; i++) fact[i] = i * fact[i - 1];
    int ans = fact[s.size()];
    map<char, int> mapp;
    for (auto c : s) mapp[c]++;
    for (auto [a, b] : mapp) ans /= fact[b];
    cout << ans << '\n';
    do {
        cout << s << '\n';
    } while(next_permutation(s.begin(), s.end()));
}

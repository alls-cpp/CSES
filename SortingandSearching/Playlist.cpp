// https://cses.fi/paste/b042fc8ac1f394918b7b54/
#include <bits/stdc++.h>
#ifdef ALE
	#include "/home/userland/CompetitiveProgramming/Library/debug.h"
#else
	#define dbg(...)
#endif
using namespace std;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
unordered_map<long long, int, custom_hash> st;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> a(n); for (auto &_ : a) cin >> _;
	a.push_back(a.back());
	int ans = 0, idx = 0;
	for (int i = 0; i < n + 1; i++) {
		if (st.find(a[i]) != st.end()) { 
			ans = max(ans, i - idx);
			for (int j = idx; j < st[a[i]]; j++) {
				st.erase(a[j]);
			}
			idx = st[a[i]] + 1;
		}
		st[a[i]] = i;
	}
	cout << ans << endl;
}

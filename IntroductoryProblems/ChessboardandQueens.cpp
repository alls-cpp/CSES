// https://cses.fi/paste/f2c417f0f015b0a2881af9/
#include <bits/stdc++.h>
#ifdef ALE
	#include "/home/alls/CompetitiveProgramming/Library/debug.h"
#else
	#define dbg(...)
#endif
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<vector<bool>> used(8, vector<bool>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c; cin >> c;
            if (c == '*') used[i][j] = true;
        }
    }
    vector<bool> cols(8), prim(15), sec(15);
    int ans = 0;
    auto f = [&](auto &&f, int i = 0) -> void {
        for (int j = 0; j < 8; j++) if (used[i][j] == false) {
            if (cols[j] + prim[i - j + 7] + sec[i + j] == 0) {
                if (i == 7) {
                    ans++;
                } else {
                    cols[j] = prim[i - j + 7] = sec[i + j] = true;
                    f(f, i + 1);
                    cols[j] = prim[i - j + 7] = sec[i + j] = false;
                }
            }
        }
    };
    f(f);
    cout << ans;
}

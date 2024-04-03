// https://cses.fi/paste/cf7f22da610f7afd87f736/
#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<int> v{0};
    for (int i = 9, idx = 1; idx < 18; i *= 10, idx++) v.push_back(idx * i + v.back());
    vector<int> pow10{1};
    for (int i = 0; i < 19; i++) pow10.push_back(pow10.back() * 10);
    int q; cin >> q;
    while (q--) {
        int k; cin >> k; k--;
        int digits = lower_bound(v.begin(), v.end(), k + 1) - v.begin();
        int n = pow10[digits - 1] + (k - v[digits - 1]) / digits;
        cout << to_string(n)[(k - v[digits - 1]) % digits] << '\n';
    }
}

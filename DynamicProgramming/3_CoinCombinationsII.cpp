#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int mxN = 100, mxX = 1e6, M = 1e9+7;
int n, x, c[mxN + 1];
ll dp[mxX + 1];

int main() {

#ifdef ALE
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> x;

    for(int i = (0); i < (n); ++i) {
    	cin >> c[i];
    }

    dp[0] = 1;

    	for(int j = (0); j < (n); ++j)
    for(int i = (1); i <= (x); ++i)
    		if(i >= c[j])
    			dp[i] = (dp[i] + dp[i - c[j]]) % M;
    cout << dp[x];
}
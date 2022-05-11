#include <bits/stdc++.h>

using namespace std;

using ll = long long;
void fast_io() {ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

const int mxN = 1e6, M = 1e9+7;
int t, n;
ll dp[mxN+1][3];

int main() {
    fast_io();

    // freopen("input.txt", "r", stdin);

	cin >> t;
	dp[1][0] = 2;

	for(int i = (2); i < (mxN + 1); ++i) {
		ll somma=((dp[i-1][0] + dp[i-1][1])%M + dp[i-1][2])%M;
		dp[i][0] = (2*somma)%M;
		dp[i][1] = (dp[i-1][0]/2 + dp[i-1][1])%M;
		dp[i][2] = (3*((dp[i-1][2] + dp[i-1][0]/2)%M))%M;
	}

	while(t--) {
		cin >> n;
		ll res = ((dp[n][0] + dp[n][1])%M + dp[n][2])%M;
		cout << res << endl;
	}
}
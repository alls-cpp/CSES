#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mxN = 1e3, mxX = 1e5;
int n, x, h[mxN], s[mxN], dp[mxN + 1][mxX + 1];

int main() {
	cin >> n >> x;

	for(int i = (0); i < (n); ++i)
		cin >> h[i];
	for(int i = (0); i < (n); ++i)
		cin >> s[i];

	for(int i = (1); i <= (n); ++i)
		for(int j = (1); j <= (x); ++j) {
			if(h[i - 1] <= j)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - h[i - 1]] + s[i - 1]);
			else
				dp[i][j] = dp[i - 1][j];
		}

	cout << dp[n][x];
}
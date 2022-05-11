#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mxN = 1e3, M = 1e9+7;
int n, dp[mxN][mxN];
string grid[mxN];

int main() {

#ifdef ALE
    freopen("input.txt", "r", stdin);
#endif

    cin >> n;

    for(int i = (0); i < (n); ++i)
    	cin >> grid[i];

    dp[0][0] = 1;
    for(int i = (0); i < (n); ++i) {
    	for(int j = (0); j < (n); ++j) {
            if(j)
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % M;
            if(i)
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % M;
            if(grid[i][j] == '*')
                dp[i][j] = 0;
        }
    }

    cout << dp[n-1][n-1];
}
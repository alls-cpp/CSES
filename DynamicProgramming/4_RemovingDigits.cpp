#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mxN = 1e6;
int n, dp[mxN + 1];

int main() {

#ifdef ALE
    n = 27;
#else
    cin >> n;
#endif

    for(int i = (1); i < (n + 1); ++i) {
    	dp[i] = 1e9;
    	int j = i;
    	while(j) {
    		dp[i] = min(dp[i], dp[i - j%10] + 1);
    		j /= 10;
    	}
    }

    cout << dp[n];
}
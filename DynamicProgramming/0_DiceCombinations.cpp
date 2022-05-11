#include <bits/stdc++.h>

using namespace std;

int main() {
    const int M = 1e9 + 7;
    int n;
    cin >> n;

    vector<long long> dp(n + 1);
    dp[0] = 1;

    for (int i = (1); i <= (n); ++i)
        for(int k = 1; k <= min(6, i); k++)
            dp[i] = (dp[i] + dp[i - k]) % M;


    cout << dp[n];
}
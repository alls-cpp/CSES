#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
MEMO
map<int, int> memo = {};


int solve(int k) {
    if(memo.count(k)) return memo[k];
    if(k < 0) return -1;
    if(k == 0) return 0;
    
    int Min = 1e6 + 1;

    for (int i = (0); i < (n); ++i){
        int tmp = solve(k - v[i]);
        if(tmp != -1)
            Min = min(Min, tmp);
    }

    if(Min == 1e6 + 1)
        memo[k] = -1;
    else
        memo[k] = Min + 1;

    return memo[k];
}

*/

const int mxN = 100, mxX = 1e6;
int n, x, c[mxN + 1];
ll dp[mxX + 1];

int main() {
    
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    #endif
    
    cin >> n >> x;
    for (int i = (0); i < (n); ++i)
        cin >> c[i];

    for (int i = (1); i < (x + 1); ++i){
        dp[i] = 1e9;

        for (int j = (0); j < (n); ++j)
            if(i >= c[j])
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
    }

    if(dp[x] == 1e9)
        cout << "-1";
    else
        cout << dp[x];
}
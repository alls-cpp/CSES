#include <bits/stdc++.h>

#ifdef ALE
#include "/home/alls/Library/debug.h"
#else
#define dbg(...)
#endif
 
using namespace std;

using ll = long long;
using ld = long double;

using pi = pair<int, int>;
using pll = pair<ll, ll>;
 
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vpi = vector<pi>;
using vpll = vector<pll>;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define feach(i, x) for (auto& i : x)
 
#define SZ(x) (int)(x).size()
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define MP make_pair
#define make_unique(x) {sort(ALL(x)); x.erase(unique(ALL(x)), x.end());}
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng) 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const long double eps = 5e-8;
const char nl = '\n';
 
///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////
 
void solve() {
	int n, x; cin >> n >> x;
	vi v(n); feach(i, v) cin >> i;
	sort(ALL(v));
	int res, i, j;
	res = 0, i = 0, j = n-1;
	while(i <= j) {
		if(v[i]+v[j] <= x)
			++i;
		++res;
		--j;
	}
	cout << res;
}
 
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    while (t--) {
        #ifdef ALE
            cout << "\e[36m" << "------------------------------\n" << "\e[39m";
        #endif
        solve();
    }
}


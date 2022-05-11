#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#ifdef ALE
#define debug(x) cerr << #x << " = ", _print(x), cerr << endl
#else
#define debug(x)
#endif
 
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
template<class T> using V = vector<T>;
template<typename T> using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template<typename K, typename V> using ordered_map = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
 
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i, a, b) for (int i = (a); i >= b; i--)
#define feach(a, x) for (auto& a : x)
 
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define pb push_back
 
 
void _print(int x) {cerr << x;}
void _print(ll x) {cerr << x;}
void _print(unsigned long long x) {cerr << x;}
void _print(double x) {cerr << x;}
void _print(ld x) {cerr << x;}
void _print(bool x) {cerr << (x ? "true" : "false");}
void _print(char x) {cerr << x;}
void _print(string x) {cerr << x;}
 
template <class T1, class T2> void _print(pair<T1, T2> p) {cerr << "("; _print(p.first); cerr << " "; _print(p.second); cerr << ")";}
template <class T> void _print(vector<T> v) {cerr << "[ "; for (T x : v) {_print(x); cerr << " ";} cerr << "]";}
template <class T> void _print(set<T> s) {cerr << "{ "; for (T x : s) {_print(x); cerr << " ";} cerr << "}";}
template <class T> void _print(multiset<T> s) {cerr << "{ "; for (T x : s) {_print(x); cerr << " ";} cerr << "}";}
template <class T> void _print(ordered_set<T> s) {cerr << "{ "; for (T x : s) {_print(x); cerr << " ";} cerr << "}";}
template <class T1, class T2> void _print(map<T1, T2> m) {cerr << "{ "; for (auto x : m) {_print(x); cerr << " ";} cerr << "}";}
 
const int MOD = 1000000007;
const char nl = '\n';
 
/* ---------- Code here ---------- */
 
void solve() {
    int n; cin >> n;
    ll x[n];
    FOR(i, 0, n) cin >> x[i];
    ll res = 0;
    FOR(i, 1, n)
        if(x[i] < x[i-1]) {
            res += x[i-1] - x[i];
            x[i] = x[i-1];
        }
    cout << res;
}
 
/* ---------- Main here ---------- */
 
int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
        #ifdef ALE
            cout << "------------------------------\n";
        #endif
    }
}
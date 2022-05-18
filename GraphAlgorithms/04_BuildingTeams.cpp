#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#ifdef ALE
#define db(x) cout << #x << " = ", _print(x), cout << nl
#else
#define db(x)
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
#define make_unique(x) {sort(all(x)); x.erase(unique(all(x)), x.end());}
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng) 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void _print(int x) {cout << x;}
void _print(ll x) {cout << x;}
void _print(unsigned long long x) {cout << x;}
void _print(double x) {cout << x;}
void _print(ld x) {cout << x;}
void _print(bool x) {cout << (x ? "true" : "false");}
void _print(char x) {cout << x;}
void _print(string x) {cout << x;}
template<class T> using V = vector<T>;
template<typename T> using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template<typename K, typename V> using ordered_map = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <class T1, class T2> void _print(pair<T1, T2> p) {cout << "("; _print(p.first); cout << " "; _print(p.second); cout << ")";}
template <class T> void _print(vector<T> v) {cout << "[ "; for (T x : v) {_print(x); cout << " ";} cout << "]";}
template <class T> void _print(set<T> s) {cout << "{ "; for (T x : s) {_print(x); cout << " ";} cout << "}";}
template <class T> void _print(multiset<T> s) {cout << "{ "; for (T x : s) {_print(x); cout << " ";} cout << "}";}
template <class T> void _print(ordered_set<T> s) {cout << "{ "; for (T x : s) {_print(x); cout << " ";} cout << "}";}
template <class T1, class T2> void _print(map<T1, T2> m) {cout << "{ "; for (auto x : m) {_print(x); cout << " ";} cout << "}";}
 
const int MOD = 1000000007;
const long double eps = 5e-8;
const char nl = '\n';
 
///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////
 
void solve() {
	int n, m; cin >> n >> m;
	vvi graph(n);
	FOR(i, 0, m) {
		int a, b; cin >> a >> b; --a, --b;
		graph[a].PB(b);
		graph[b].PB(a);
	}
	vector<int> color(n);
	queue<int> q;
	color[0] = 1;
	q.push(0);
A:
	while(!q.empty()) {
		int tmp = q.front();
		q.pop();
		feach(i, graph[tmp]) {
			if(color[i] == color[tmp]) {
				cout << "IMPOSSIBLE";
				return;
			} else if(color[i] == 0) {
				if(color[tmp] == 1)
					color[i] = 2;
				else
					color[i] = 1;
				q.push(i);
			}
		}
	}
	FOR(i, 0, n)
		if(color[i] == 0) {
			color[i] = 1;
			q.push(i);
			goto A;
		}
	feach(i, color)
		cout << i << " ";
}
 
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    while (t--) {
        #ifdef ALE
            cout << "------------------------------\n";
        #endif
        solve();
    }
}

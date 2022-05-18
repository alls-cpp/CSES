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
 
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define pb push_back
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
	char mat[n][m];
	queue<pi> q;
	pi start, end;

	FOR(i, 0, n) {
		FOR(j, 0, m) {
			cin >> mat[i][j]; 
			if(mat[i][j] == 'A')
				start = {i, j};
			else if(mat[i][j] == 'B')
				end = {i, j};
		}
	}

	q.push(start);
	while(!q.empty()) {
		pi tmp = q.front();
		q.pop();
		int i=tmp.first, j=tmp.second;

		if(i-1>=0 && mat[i-1][j]=='B') { 
			mat[i-1][j] = 'D';
			break;
		}
		if(j-1>=0 && mat[i][j-1]=='B') { 
			mat[i][j-1] = 'R';
			break;
		}
		if(i+1<n && mat[i+1][j]=='B') { 
			mat[i+1][j] = 'U';
			break;
		}
		if(j+1<m && mat[i][j+1]=='B') { 
			mat[i][j+1] = 'L';
			break;
		}


		if(i-1>=0 && mat[i-1][j]=='.') {
			q.push({i-1, j});
			mat[i-1][j] = 'D';  
		}
 
		if(j-1>=0 && mat[i][j-1]=='.') {
			q.push({i, j-1});
			mat[i][j-1] = 'R';
		}
 
		if(i+1<n && mat[i+1][j]=='.') {
			q.push({i+1, j});
			mat[i+1][j] = 'U';
		}
 
		if(j+1<m && mat[i][j+1]=='.') {
			q.push({i, j+1});
			mat[i][j+1] = 'L';
		}
	}
	if(mat[end.first][end.second] == 'B')
		cout << "NO";
	else {
		stack<char> porcodio;
		while(end != start) {
			char tmp = mat[end.first][end.second];
			if(tmp == 'U') {
				porcodio.push('D');
				--end.first;
			}
			else if(tmp == 'D') {
				porcodio.push('U');
				++end.first;
			}
			else if(tmp == 'L') {
				porcodio.push('R');
				--end.second;
			}
			else {
				porcodio.push('L');
				++end.second;
			}
		}
		cout << "YES" << nl << porcodio.size() << nl;
		while(!porcodio.empty()) {
			cout << porcodio.top();
			porcodio.pop();
		}
	}
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

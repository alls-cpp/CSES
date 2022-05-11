#include <bits/stdc++.h>
using namespace std;

using ll=long long;
int n, q;
vector<ll> tree;

ll f(int node, int nodeL, int nodeH, int queryL, int queryH) {
	if(nodeH<queryL || nodeL>queryH)
		return 0;
	if(queryL<=nodeL && nodeH<=queryH)
		return tree[node];

	int mid=(nodeH+nodeL)/2;
	return 	(f(2*node, nodeL, mid, queryL, queryH) ^
			f(2*node+1, mid+1, nodeH, queryL, queryH));
}

int main() {

	#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    #endif

    cin >> n >> q;
    vector<int> v(n);
    for(int i=(0); i<(n); ++i) 
    	cin >> v[i];

    while(__builtin_popcount(n)!=1) {
    	v.push_back(0);
    	n++;
    }

    tree.resize(2*n);

    for(int i=(0); i<(n); ++i) 
    	tree[n+i]=v[i];

    for(int i=(n-1); i>=(1); --i) {
    	tree[i]=(tree[2*i]^tree[2*i+1]);
    }

    while(q--) {
    	int a, b;
    	cin >> a >> b;
    	cout << f(1, 0, n-1, a-1, b-1) << "\n";
    }
}
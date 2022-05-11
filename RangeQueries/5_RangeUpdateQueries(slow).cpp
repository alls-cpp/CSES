#include <bits/stdc++.h>
using namespace std;

using ll=long long;
int n, q;
vector<ll> tree;

ll f(int node, int nodeL, int nodeH, int pos) {
	if(nodeL==pos && pos==nodeH)
		return tree[node];
	if(pos<nodeL || pos>nodeH)
		return 0;

	int mid=(nodeL+nodeH)/2;
	return tree[node]+f(2*node, nodeL, mid, pos)+
	f(2*node+1, mid+1, nodeH, pos);
}

void update(int node, int nodeL, int nodeH, int queryL, int queryH, int u) {
	if(nodeH<queryL || nodeL>queryH)
		return;

	if(queryL<=nodeL && nodeH<=queryH) {
		tree[node]+=u;
		return;
	}

	int mid=(nodeH+nodeL)/2;
	update(2*node, nodeL, mid, queryL, queryH, u);
	update(2*node+1, mid+1, nodeH, queryL, queryH, u);
}

int main() {

	#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    #endif

    cin >> n >> q;
    vector<int> v(n);
    for(int i=(0); i<(n); ++i) 
    	cin >> v[i];

    while(__builtin_popcount(n)!=1)
    	n++;

    tree.resize(2*n);

    for(int i=(0); i<(n); ++i) 
    	tree[n+i]=v[i];

    while(q--) {
    	int x;
    	cin >> x;
    	if(x==1){
    		int a, b, u; cin >>a>>b>>u;
    		update(1, 0, n-1, a-1, b-1, u);
    	}
    	else {
    		int pos; cin >> pos;
    		cout << f(1, 0, n-1, pos-1) << "\n";
    	}
    }
}
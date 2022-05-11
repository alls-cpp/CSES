#include <bits/stdc++.h>
 
using namespace std;
vector<long long> tree;

long long sum(int node, int node_low, int node_high, int query_low, int query_high) {
    if(query_low<=node_low && node_high<=query_high)
        return tree[node];
    if(node_low>query_high || node_high<query_low)
        return 0;

    int mid=(node_low + node_high)/2;
    return  sum(2*node, node_low, mid, query_low, query_high)+
            sum(2*node+1, mid+1, node_high, query_low, query_high);
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    #endif

    int n, q;
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
        tree[n+i] = v[i];
    // tree=[0, ..., 0, v[0], v[1], ..., v[n], 0, ..., 0]

    for(int i=(n-1); i>=(1); --i)
        tree[i] = tree[2*i]+tree[2*i+1];

    while(q--) {
        int low, high;
        cin >> low >> high;
        low--; high--;//start from 0
        cout << sum(1, 0, n-1, low, high) << "\n";
    }
}

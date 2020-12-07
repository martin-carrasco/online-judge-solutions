#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int MAXN = 1e5 + 5;

ll b[MAXN];
template <class Node>
struct ST {
	Node tree[4*MAXN];

	// Node operation
	Node op(Node n1, Node n2){
		if (n1.first > n2.first){
			return n1;	
		}
		return n2;
	}

	// Node range update for children
	Node range_op(Node n1, int child_nodes){
		return n1;
	}

	/* 
	 * node: Node representing the range
	 * l: Left side of range
	 * r: Right side of range
	 */
	void build(ll a[], int node, int l, int r){
		if (l == r){
			tree[node] = {a[l], l};
			return;		
		}
		int mid = (l+r) / 2;
		build(a, 2*node, l, mid);
		build(a, 2*node+1, mid+1, r);
		tree[node] = op(tree[2*node], tree[2*node+1]);
	}

	/*
	 * node: Node respreseting the range
	 * l: Left side of range
	 * r: Right side of range
	 * pos: Position to update
	 * value: Value to set
	 */
	void set_point(int node, int l, int r, int pos, Node val){
		if (l == r){
			tree[node] = make_pair(val.first, tree[node].second);		
			return;
		}
		int mid = (l+r) / 2;
		if (pos <= mid){
			set_point(2*node, l, mid, pos, val);	
		} else {
			set_point(2*node+1, mid+1, r, pos, val);
		}
		tree[node] = op(tree[2*node], tree[2*node+1]);
	}

	/*
	 * node: Node representing the range
	 * l: Left side of range
	 * r: Right side of range
	 * a: Left side of query
	 * b: Right side of query
	 */
	Node query(int node, int l, int r, int a, int b){
		if (l > r or a > r or b < l)	return Node{};
		if (a <= l and r <= b) return tree[node]; 	

		int mid = (l+r)/2;

		return op(query(2*node, l, mid, a, b), query(2*node+1, mid+1, r, a, b));
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q, height;
	cin >> n;
	height = ceil(log2(n));

	ST<pair<ll, int>> st;
	for(int i = 0;i < n;i++) cin >> b[i];		
	st.build(b, 1, 0, n-1);

	cin >> q;
	while(q--){
		char c;
		ll x,y;
		cin >> c;
		cin >> x >> y;
		x--;
		if (c == 'U'){
			st.set_point(1, 0, n-1, x, {y, -1});	
		} else {
			y--;

			auto ans_x = st.query(1, 0, n-1, x, y);
			int idx_x = ans_x.second;
			ll ans_y = max(st.query(1, 0, n-1, x, idx_x - 1).first, st.query(1, 0, n-1, idx_x+1, y).first);
			//cout << "ans_x: " << ans_x.first << ", ans_y: " << ans_y << "\n";
			cout << ans_x.first + ans_y << "\n";
		}
	}
}

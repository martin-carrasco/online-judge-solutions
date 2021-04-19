#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 1e2 + 5;

int n,m, t;
vector<set<int>> a;

template <class Node>
struct ST {
	Node tree[4*MAXN];
	Node lazy[4*MAXN];

	// Node operation
	Node op(Node n1, Node n2){
		Node n3;
		set_union(n1.begin(), n1.end(), n2.begin(), n2.end(), inserter(n3, n3.begin()));
		return n3;
	}

	/* 
	 * node: Node representing the range
	 * l: Left side of range
	 * r: Right side of range
	 */
	void build(int node, int l, int r, vector<set<int>>& a){
		if (l == r){
			tree[node] = a[l];
			return;		
		}
		int mid = (l+r) / 2;
		build(2*node, l, mid, a);
		build(2*node+1, mid+1, r, a);
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
			tree[node] = val;		
		}
		int mid = (l+r) / 2;
		if (pos <= mid){
			update(2*node, l, mid, pos, val);	
		} else {
			update(2*node+1, mid+1, pos, val);
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

	cin >> t;
	while(t--){
		cin >> n >> m;
		set<int> general;
		general.insert(0);

		int cnt = 0;
		for(int i = 0;i < n;i++){
			char c;
			cin >> c;
			int num = c == '+' ? 1 : -1;
			cnt += num;
			general.insert(cnt);
			set<int> n_set;
			copy(general.begin(), general.end(), inserter(n_set, n_set.begin()));
			a.push_back(n_set);
		}
		ST<set<int>> st;
		st.build(1, 0, n, a);
		while(m--){
			int l,r;
			cin >> l >> r;
			--l;--r;
			set<int> l_set, r_set, ans;
			if (l > 0) {
				l_set = st.query(1, 0, n, 0, l-1);
			}
			if (r < n-1){
				r_set = st.query(1, 0, n, r+1, n-1);
			}
			set_union(l_set.begin(), l_set.end(), r_set.begin(), r_set.end(), inserter(ans, ans.begin()));
		}

		a.clear();
	}

	return 0;
}

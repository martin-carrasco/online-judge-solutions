#include "bits/stdc++.h"

using namespace std;
const int MAXN = 1e5;

int tree[4*MAXN];
int lazy[4*MAXN];

/* 
 * node: Node representing the range
 * l: Left side of range
 * r: Right side of range
 */
void build(int node, int l, int r){
	if (l == r){
		tree[node] = 0;
		return;		
	}
	int mid = (l+r) / 2;
	build(2*node, l, mid);
	build(2*node+1, mid+1, r);
	tree[node] = tree[2*node] + tree[2*node+1];
}

void push(int node, int l, int r){
	if(lazy[node] == 0)	return;
	tree[node] = abs(r-l+1 - tree[node]);
	if (l != r){
		int mid = (l+r)/2;
		push(node*2, l, mid);
		push(node*2+1, mid+1, r);
	}
	lazy[node] = 0;
}

void update_range(int node, int l, int r, int a, int b, int val){
	if (l > r or l > b or r < a)	return;
	if (a <= l and r <= b){
		lazy[node] = 1;
		return;
	}
	push(node, l, r);
	int mid = (l+r) / 2;
	update_range(2*node, l, mid, a, b, val);	
	update_range(2*node+1, mid+1, r, a, b, val);

	tree[node] = tree[2*node] + tree[2*node+1];
}

int query_range(int node, int l, int r, int a, int b){
	if (l > r or l > b or r < a) return 0;
	if (a <= l and  r <= b) return tree[node]; 	

	int mid = (l+r)/2;
	push(node, l, r);

	int q1 = query_range(2*node, l, mid, a, b);
	int q2 = query_range(2*node+1, mid+1, r, a, b);
	return q1 + q2;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	build(1, 0, n-1);
	while(q--){
		int t, a,b;
		cin >> t >> a >> b;
		if (t == 0){
			update_range(1, 0, n-1, a,b,1);
		} else {
			int res = query_range(1, 0, n-1, a, b);
			cout << res << "\n";
		}
	}
	

}



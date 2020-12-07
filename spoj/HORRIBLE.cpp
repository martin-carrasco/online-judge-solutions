#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int MAXN = 1e6 + 5;

ll tree[4*MAXN];
ll lazy[4*MAXN];

int n, c;

ll query(int a, int b, int k, int l, int r){
	if (b < l or a > r) return 0LL;
	if (a <= l and r <= b) return tree[k] + lazy[k]*(r-l+1);
	lazy[2*k] += lazy[k];
	lazy[2*k+1] += lazy[k];
	lazy[k] = 0;
	int mid = (l+r) / 2;
	ll s1 = query(a, b, 2*k, l, mid);
	ll s2 = query(a, b, 2*k+1, mid+1, r);
	tree[k] = tree[2*k] + lazy[2*k]*(r - l + 1)/2 + tree[2*k+1] + lazy[2*k+1]*(r-l+1)/2;

	return s1+s2;

}



void update_range(int a, int b, int k, int l, int r, ll add){
	if (b < l or a > r) return;	
	if (a <= l and r <= b) { lazy[k] += add; return;}
	lazy[2*k] += lazy[k];
	lazy[2*k+1] += lazy[k];
	lazy[k] = 0;
	int mid = (l+r)/2;
	update_range(a, b, 2*k, l, mid, add);
	update_range(a, b, 2*k+1, mid+1, r, add);
	tree[k] = tree[2*k] + lazy[2*k]*(r - l + 1)/2 + tree[2*k+1] + lazy[2*k+1]*(r-l+1)/2;

}

void query_1(){
	int p, q;
	ll v;
	cin >> p >> q >> v;

	update_range(min(p-1, q-1), max(p-1, q-1), 1, 0, n-1,  v); 
}

ll query_2(){
	int p, q;
	cin >> p >> q;
	return query(min(p-1, q-1), max(p-1, q-1), 1, 0, n-1);
}

int nextPow2(int v){
	v--;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v++;
	return v;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;

	while(t--){
		cin >> n >> c;

		n = nextPow2(n);

		while(c--){
			bool type;
			cin >> type;
			if (type)
				cout << query_2() << "\n";
			else
				query_1();
		}
		for(int i = 0; i <= min(4*n+1, MAXN);i++)
			lazy[i] = tree[i] = 0;
	}
	return 0;
}

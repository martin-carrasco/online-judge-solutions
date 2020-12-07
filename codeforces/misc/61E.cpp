#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int MAXN = 1e6 + 5;
int a[MAXN];

struct FenwickTree {
    vector<ll> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    ll sum(int r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += (ll) bit[r];
        return ret;
    }

    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, ll delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main(){
	int n;
	cin >> n;
	FenwickTree t(1e9);
	for(int i = 0;i < n;i++) {
		int val;
		cin >> val;
		t.add(i, val);
	}

	for(int i = 0;i < n;i++){
			
	}

	return 0;
}

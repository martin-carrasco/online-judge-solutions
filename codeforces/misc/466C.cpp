#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int MAX_N = 1e6 + 5;
int a[MAX_N];
ll p[MAX_N];

int main() {
	int n;
	map<ll, ll> mp;

	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		p[i] = (ll) a[i] + p[i-1];
	}

	ll count = 0;
	ll mx_val = p[n];
	for(int i = 1;i < n;i++){
		ll curr = mx_val - p[i];
		if (p[i] == curr * 2) {
			count += (ll) mp[curr];
		}
		mp[p[i]] += 1;
	}
	cout << count << endl;
	return 0;
}

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int MAXN = 1e5;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;

	ll cnt = 0;
	for(ll i = 2;i <= 2*n;i++){
		ll rem = i - k;
		ll contrib = min(i-1, 2*n+1 -i) * min(rem - 1, 2*n+1-rem);
		cnt += contrib;
	}
	cout << cnt << "\n";

	return 0;
}

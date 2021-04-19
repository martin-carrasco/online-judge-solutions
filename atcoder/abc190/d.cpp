#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int MAXN = 1e5;
ll n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	ll ans = 1;
	ll end_f =  sqrt(2*n);
	
	for(ll i = 1; i <= end_f;i++){
		if (n*1.0 / i < i*1.0 / 2) continue;
		if (i % 2 == 1){
			if (n % i == 0) ans++;
		} else {
			if ( (n + i/2)	% i == 0) ans++;
		}

		/*
		if (i*i % 2 == 1) continue;
		if ((n + (i*i / 2) + (i/2)) % i == 0) ans++;*/
	}	
	cout << 2LL*(ans) - 2 << "\n";
	
	return 0;
}

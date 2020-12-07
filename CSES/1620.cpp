#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int MAXN = 1e6;
ll a[MAXN];
int t, n;

bool valid(ll t_try){
	ll prods = 0;
	for(int i = 0;i < n;i++){	
		prods += t_try / a[i];									
	}
	return prods >= t; 
}

int main(){
	cin >> n >> t;


	for(int i = 0;i < n;i++) cin >> a[i];

	ll rhs, lhs;
	lhs = 0;
	rhs = 1;


	sort(a, a+n);

	while(not valid(rhs)){
		rhs *= 2;
	}

	ll ans = 0;
	while(lhs <= rhs){
		ll mid = (rhs+ lhs) / 2;

		if (valid(mid)) {
			ans = mid;
			rhs = mid - 1;
		} else {
			lhs = mid + 1;	
		}
	}
	cout << ans << "\n";

	return 0;
}

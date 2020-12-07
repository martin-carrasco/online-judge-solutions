#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int MAXN= 2e5 + 5;

ll a[MAXN];
ll n, k;

bool valid(ll m){
	ll sub_arrays, sum;
	sub_arrays = sum = 0;
	for(int i = 1;i <= n;i++){
		if (a[i] > m)
			return false;
		if (a[i] + sum > m){
			sub_arrays++;
			sum = 0;		
		}
		sum += a[i];
	}
	if(sum) sub_arrays++;
	return sub_arrays <= k;

}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for(int i = 1;i <= n;i++) cin >> a[i];

	ll l, r;
	l = 0, r = 1e18;

	ll ans = 0;
	while(l <= r){
		ll mid = (l+r) / 2;

		if (valid(mid)) {
			ans = mid;	
			r = mid -1;
		} else {
			l = mid+1;		
		}
	}

	cout << ans << "\n";
	return 0;
}

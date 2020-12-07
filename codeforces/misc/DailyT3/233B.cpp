#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const ll MAXN = 1e18 + 5;

ll digit_sum(ll numb){
	ll sum = 0;

	while(numb != 0){
		sum += numb % 10;
		numb /= 10;
	}

	return sum;
}

int main(){
	ll n;
	cin >> n;
	
	ll ans = numeric_limits<ll>::max();
	for(ll i = 0;i <= 90;i++){
		ll b = i;
		ll discri = b*b + 4*n;
		ll delta = sqrt(discri * 1.0);
		if (delta * delta != discri)
			continue;
		ll opt_1 = delta - b;

		if (opt_1 % 2 == 0){
			opt_1 = opt_1 /  2;
			ll dig = digit_sum(opt_1);
			if (dig == b){
				//cout << "b: " << b << ", dig: " <<dig <<   ", opt_1: " << opt_1 << ", discri: " << discri << "\n";
				ans = min(ans, opt_1);
			}
		}
	}
	if (ans == numeric_limits<ll>::max())
		cout << -1 << "\n";
	else
		cout << ans << "\n";
}


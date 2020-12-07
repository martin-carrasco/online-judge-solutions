#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main(){
	int q;
	cin >> q;
	while(q--){
		ll n, m;
		cin >> n  >> m;
		ll k = floor(n / m);

		ll sum = 0;
		for(int i = 0;i <= 9;i++){
			sum += m * (i+ 1) % 10	;
		}
		ll ans = floor(k / 10) * sum;
		for(int i = 0;i < (k % 10);i++){
			ans += m *(i+ 1) % 10;
		}
		cout << ans << "\n";

	}
	return 0;
}

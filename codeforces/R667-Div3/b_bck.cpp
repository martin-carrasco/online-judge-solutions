#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		ll a,b,x,y,n;

		cin >> a >> b >> x >> y >> n;

		ll f, comp_1, s, comp_2;
		if (a < b){
			f = a;
			s = b;
			comp_1 = x;
			comp_2 = y;
		} else{
			f = b;
			s = a;
			comp_1 = y;
			comp_2 = x;
		}


		if (f - n >= comp_1){
			f = f - n;
			n = 0;
		} else {
			ll tmp = f;
			f = comp_1;
			n = tmp - comp_1;
		}

		s = s - n >= comp_2 ? s-n : comp_2;
		ll ans = s * f;

		cout << ans << "\n";
	}

	return 0;
}

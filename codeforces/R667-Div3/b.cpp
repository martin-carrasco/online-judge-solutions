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


		ll best = max(a - n, x);
		ll best_2 = max(b - n, y);

		
		//cout << "Best: " << best << ", BEst2: " << best_2 << "\n";
		ll remain_n, f, s, ans;
		if (best <= best_2){
			f = best;
			remain_n = n - (a - f);
			s = b - remain_n >= y ? b - remain_n : y;
			ans = f * s;
		} else {
			f = best_2;
			remain_n = n - (b - f) ;
			s = a - remain_n >= x ? a- remain_n : x;
			ans = f * s;
		}

		cout << ans << "\n";
	}

	return 0;
}

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n, g, b;
		cin >> n >> g >> b;

		ll need = ceil(n*1.0 / 2);

		ll good_seasons = ceil(need*1.0 / g);
		ll bad_seasons = max((ll)good_seasons-1LL, 0LL);
		ll days_bad = bad_seasons*b;
		ll days_good = days_bad + need;
		ll total_days = days_bad + floor(need / g) + (need - floor(need / g));
		//cout << "Bad days: " << days_bad << "\n";
		//cout << "Total days: " << total_days << "\n";
		//cout << days_good << "\n";  
	
		ll ans = days_good;
		if (days_bad < n - need)
			ans += (n-need) - days_bad;


		cout << ans << "\n";
		
	}
}

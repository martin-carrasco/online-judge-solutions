#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		ll x_1, y_1, x_2, y_2;
		cin >> x_1 >> y_1 >> x_2 >> y_2;

		ll ans = abs(x_2 - x_1);
		ans += abs(y_2 - y_1);
		ans = y_2 != y_1 ? ans+2 : ans;	

		ll ans2 = abs( y_2 - y_1);
		ans2 += abs(x_2 - x_1);
		ans2 = x_2 != x_1 ? ans2+2 : ans2;

		cout << min(ans, ans2) << "\n";
	}

	return 0;
}

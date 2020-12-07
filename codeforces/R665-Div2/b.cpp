#include "bits/stdc++.h"

using namespace std;
using ll = long long;
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		ll x1, y1, z1, x2, y2, z2;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
 
		ll num_2s = min(z1, y2);
 
		if (z1 <= y2) {
			if (z2 <= x1)
				cout << z1 * 2 << "\n";
			else 
				cout <<  2LL * (z1  -  (z2 - x1)) << "\n";
		}
 
		else {
			if (z2 <= x1)
				cout << y2 * 2 << "\n";
			else {
				ll not_matched = z1 - y2;
				ll minus_amount = z2 - not_matched;
				if (minus_amount < 0) {
					cout << y2 * 2 << "\n";
					continue;
				}
				minus_amount -= x1;
				if (minus_amount < 0) {
					cout << y2 * 2 << "\n";
					continue;
				}
				cout << y2 * 2 - 2 * minus_amount << "\n";
			}
		}
	}
	return 0;
}

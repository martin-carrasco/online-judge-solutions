#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main(){

	int t;
	cin >> t;
	while(t--){
		int x, y;
		cin >> y >> x;

		ll max_b = max(x, y);
		ll min_b = min(x, y);
		ll dif = max_b - min_b;
		ll max_val = 1LL + (max_b*(max_b-1LL));

		if (x > y) {
			if (x % 2 == 1)
				max_val += dif;
			else
				max_val -= dif;	
		}
		else if (x < y) {
			if (y % 2 == 1)
				max_val -= dif;
			else
				max_val += dif;
		}

		cout << max_val << "\n";
	}
	return 0;
}

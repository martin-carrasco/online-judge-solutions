#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main(){
	int t;
	cin >> t;
	while(t--){
		ll x, y, k;
		cin >> x >> y >> k;

		ll sticks = (k * y + k - 1 + x - 2) / (x-1);

		cout << sticks + k << "\n";

	}
	return 0;
}

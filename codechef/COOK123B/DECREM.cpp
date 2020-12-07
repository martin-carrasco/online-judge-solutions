#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);


	int t;
	cin >> t;
	while(t--){
		ll l, r, diff;
		cin >> l >> r;
		diff = l - r;


		if (r % l == 0 or r-l > l) {
			cout << -1 << "\n";
			continue;
		}

		ll current = r;
		for(int i = 1;i < 30;i++){
			if (current % l >= diff){
				break;	
			}
			ll current = pow(r, i);
		}
		cout << current << "\n";
	}
	return 0;
}

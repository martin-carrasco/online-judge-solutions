#include "bits/stdc++.h"
 
using namespace std;
using vi = vector<int>;
using ll = unsigned long long;
 
const int MAXN = 1e3 + 5;
 

ll find_n(ll x){
	ll start = 1LL;

	ll ans = 0;
	int i = 1;
	for(;i < 64;i++){
		ll h = (start << i) - 1;
		ll cells = (h*(h+1)) / 2;
		if (cells > x) {
			i--;
			break;
		}
		x -= cells;
	}

	return i;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		ll x;
		cin >> x;
		ll ans = find_n(x);
		cout << ans << "\n";

	} 
	return 0;
}

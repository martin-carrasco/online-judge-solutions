#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 2e5;


int n,k,t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> k;
		ll x = ceil(n*1.0 / k);

		ll ans = ceil(x * k * 1.0 / n);
		cout << ans << "\n";

	}
	return 0;
}

#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 1e5 + 5;
ll a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		ll n, x;
		cin >> n >> x;
		ll sum = 0L;

		for(int i = 0;i < n;i++) cin >> a[i];

		int max_dep = 1e9;
		for(ll i = 0;i < n;i++){
			ll x_pow = 1;
			int dep = 0;
			while(1) {
				/*ll nn = a[i] / x_pow ;
				for (ll j = 0;j < pow(x, dep);j++){
					cout << nn << " ";
				}*/
				sum += a[i] / x_pow * (ll) pow(x, dep);

				x_pow *= x;
				dep += 1;

				if (a[i] < x_pow or a[i] % x_pow != 0 or dep >= max_dep) break;
			}
			max_dep = dep;
		}
		//cout << "\n";

		cout << sum << "\n";
	}


	return 0;
}

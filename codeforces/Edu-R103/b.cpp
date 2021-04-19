#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 100 + 5;


int t, n;
ll k, a[MAXN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> k;
		ld k_per = (k*1.0) / 100.0;
		ll sum = 0L;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
			sum += (ll) a[i];
		}

		/*
		ll ans = 0LL;
		for(int i = n;i > 1;i--){
			ll curr = a[i];	
			sum -= (ll) curr;
			double val = curr*1.0 / sum;
			if (val <= k_per) continue;

			ll new_val = (curr*100 - k * sum)*1.0 / k;
			cout << "i: " << i <<"\n";
			cout << "nv: " << new_val << "\n";
			a[1] += new_val;
			ans += new_val;
			sum += new_val;
		}*/

		ll ans = 0LL;
		ll acc = a[1];
		for(int i = 2;i <= n;i++){
			ll curr = a[i];
			ld val = curr*1.0 / acc;
			if (val > k_per) {
				ll new_val = ceil((curr*100 - k * acc)*1.0 / k);
				acc += new_val;
				ans += new_val;
			}
			acc += curr;
		}
		cout << ans << "\n";
	}
	return 0;
}

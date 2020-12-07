#include "bits/stdc++.h"
 
using namespace std;
using ii = pair<int, int>;
using ll = long long;
 
const int MAXN = 1e6;
ll a[MAXN];
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	set<ll> mp;
	int n;
	cin >> n;
 
	for(int i = 0;i < n; i++) cin >> a[i];
 
	ll ans = a[0];
	ll sum = a[0];
 
	mp.insert(sum);
	for(int j = 1;j < n;j++){
		sum += a[j];			
		//cout << "j: " << ", ans: " << ans << ", sum: " << sum << ", prefix: " << *mp.begin()  << endl;
		ans = max({ans, sum - *mp.begin(), sum});
		mp.insert(sum);
	}

	cout << ans << "\n";
 
	return 0;
}

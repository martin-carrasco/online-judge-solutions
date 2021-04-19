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
		ll tot = 0L;
		for(int i = 0;i < n;i++){
			cin >> a[i];
			sum += a[i];
			tot += ceil(a[i]*1.0 / x);
		}
		sum = ceil(sum*1.0 / x);
		cout << sum << " " << tot << "\n";
	}


	return 0;
}

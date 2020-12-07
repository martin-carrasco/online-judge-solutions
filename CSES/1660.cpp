#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int MAXN = 2e5;
ll a[MAXN];
ll prefix[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	map<ll, int> mp;
	ll n, k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i];

	
	mp[0] = 1;
	ll cnt = 0;
	for(int i = 1;i <= n;i++){
		prefix[i] = a[i] + prefix[i-1];	
		if (prefix[i] == k or mp.count(prefix[i] - k)){
			cnt++;
		}
		mp[prefix[i]] = 1;
	}
	cout << cnt << "\n";
	return 0;
}

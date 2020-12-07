#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int MAXN = 2e5;
ll a[MAXN];
ll prefix[MAXN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	map<ll, int> mp;

	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	mp[0] = 1;
	ll cnt = 0;
	for(int i = 1;i <= n;i++){
		prefix[i] = (a[i] % n + n + prefix[i-1]) % n;	
		if (mp.count(prefix[i])){
			cnt+=mp[prefix[i]];
		}
		mp[prefix[i]]++;

	}
	cout << cnt << "\n";
	return 0;
}

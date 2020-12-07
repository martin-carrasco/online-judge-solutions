#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;
using ll = long long;

const int MAXN = 1e6;

int a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	map<ll, int> mp;
	int n;
	cin >> n;

	for(int i = 0;i < n;i++) cin >> a[i];

	ll sum = 0;
	int cnt = 0;
	int ans = 0;
	mp[0] = 1;
	for(int i = 0;i < n;i++){
		sum += a[i];	
		if (mp.count(sum)){
			cnt++;
			sum = a[i];
			mp.clear();
			mp[0] = 1;
		}
		mp[sum]++;
	}
	cout << cnt << "\n";
	return 0;
}

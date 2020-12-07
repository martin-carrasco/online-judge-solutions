#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<ll, int>;
const int MAXN = 5000 + 5;

ii a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	ll x;
	cin >> n >> x;
	
	for(int i = 0;i < n;i++){
		ll tmp;
		cin >>tmp;
		a[i] = {tmp, i};
	}

	sort(a, a+n, greater<ii>());

	ll ans[3] = {0, 0, 0};
	bool found = false;
	for(int i = 0;i < n-2;i++){
		if (found) break;
		if (a[i].first >= x) continue;
		ll rem = x - a[i].first;

		for(int j = i+1;j < n-1;j++){
			if (a[j].first >= rem) continue;

			ll remain_2 = rem - a[j].first;
			int k;

			if (j == n-2)
				k = n-1;
			else
				k = lower_bound(a+j+1, a+n, make_pair(remain_2+1, 0), greater<ii>()) - a;

			/*cout << "i: " << i << ", j: " << j << ", k: " << k << endl;
			cout << a[i].first << endl;
			cout << a[j].first << endl;
			cout << a[k].first << endl;
			cout << remain_2 << endl << endl;*/

			if (a[k].first != remain_2)
				continue;
			ans[0] = a[i].second+1;
			ans[1] = a[j].second+1;
			ans[2] = a[k].second+1,
			found = true;
			break;
		}
	}

	sort(ans, ans+3);
	if (not found)
		cout << "IMPOSSIBLE" << "\n";
	else
		cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
	return 0;
}

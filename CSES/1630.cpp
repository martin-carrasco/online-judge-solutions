#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;
using ll = long long;

const int MAXN = 1e6;

ii a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		int s, e;
		cin >> s >> e;
		a[i] = {s, e};
	}

	sort(a, a+n);

	ll ans = 0;
	ll t = 0;
	for(int i = 0;i < n;i++){
		t += a[i].first;
		ans += a[i].second - t;
	}
	cout << ans << "\n";


	return 0;
}

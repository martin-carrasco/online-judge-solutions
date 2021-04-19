#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 1e4 + 5;
int n, a[MAXN];
set<int> unq;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		unq.insert(a[i]);
	}

	ll ans = 0LL;	
	for(auto it = unq.begin();it != unq.end();it++){
		int x = *it;
		ll max_sum = 0LL;
		ll current_sum = 0LL;
		for(int k = 0;k < n;k++){
			if (a[k] < x) {
				current_sum = 0LL;
				continue;
			}
			current_sum += (ll) (x);
			max_sum = max(current_sum, max_sum);
		}
		ans = max(ans, max_sum);
	}
	cout << ans << "\n";
	return 0;
}

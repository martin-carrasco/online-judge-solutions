#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 1e5 + 5;


int n, t;
ll c[MAXN], a[MAXN], b[MAXN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1;i <= n;i++)	cin >> c[i];
		for(int i = 1;i <= n;i++) cin >> a[i];
		for(int i = 1;i <= n;i++) cin >> b[i];

		ll ans = 0;
		ll sum = 0;
		for(int i = 2;i <= n;i++) {
			ll start_bound = a[i];
			ll end_bound = b[i];
			ll currLen = c[i] + 1LL + abs(start_bound - end_bound);
			if (start_bound != end_bound){
				currLen = max(currLen, c[i] + 1LL + sum - abs(start_bound - end_bound));
			}
			ans = max(ans, currLen);
			sum = currLen;
		}
		cout << ans << "\n";
	}
	return 0;
}

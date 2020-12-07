#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int MAXN = 100 + 5;
const int MAXV = 1e7 + 5;
const ll MOD = 1e9 + 7;
int a[MAXN];
ll dp[MAXV];
int n, x;


ll solve(){

	dp[0] = 1;
	for(int v = 1; v <= x;v++){
		ll cnt = 0;
		for(int i = 0;i < n;i++){
			if (a[i] > v) break;
			cnt = (cnt + dp[v-a[i]]) % MOD;
		}
		dp[v] = cnt;
	}

	return dp[x];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> x;
	for(int i = 0;i < n;i++) cin >> a[i];
	sort(a, a+n);
	ll ans = solve();

	cout << ans << "\n";
	return 0;
}

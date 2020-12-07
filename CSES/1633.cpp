#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int MAXN = 1e6;
const ll MOD = 1e9+7;

ll dp[MAXN];
bool vis[MAXN];

ll solve(int n){
	if (n == 0) return 1;
	if (vis[n]) return dp[n];
	ll cnt = 0;
	for(int i = 6;i > 0;i--){
		if (i > n) continue;
		cnt = (cnt +solve(n-i)) % MOD;
	}
	dp[n] = cnt;
	vis[n] = 1;
	return cnt;
}

int main(){
	int n;
	cin >> n;

	cout << solve(n) << "\n";
	return 0;
}

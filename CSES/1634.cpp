#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100;
const int MAXV = 1e7;
int a[MAXN];
int dp[MAXV];
bool vis[MAXV];
int n, x;


int solve(){

	dp[0] = 0;
	for(int v = 1; v <= x;v++){
		dp[v] = 1e9;
		for(int i = 0;i < n;i++){
			if (a[i] > v) break;
			dp[v] = min(dp[v], dp[v-a[i]] + 1);
		}
	}

	return dp[x];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> x;
	for(int i = 0;i < n;i++) cin >> a[i];
	sort(a, a+n);
	int ans = solve();

	if (ans == 1e9)
		cout << -1;
	else
		cout << ans;
	cout << "\n";
	return 0;
}

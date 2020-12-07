#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int MAXN = 5000 + 5;

ll a[MAXN];
int n;
ll dp[MAXN][MAXN][2], vis[MAXN][MAXN][2];

ll solve(int i, int j, bool player){
	if (i == j) {
		if (player) return a[i];
		return 0;
	}
	if (vis[i][j][player]) return dp[i][j][player];

	if (player)  
			dp[i][j][player] = max(solve(i, j-1, !player) + a[j],solve(i+1, j, !player) + a[i]);
	else
		dp[i][j][player] = min(solve(i, j-1, !player), solve(i+1, j, !player));

	vis[i][j][player] = 1;
	return dp[i][j][player];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0;i < n;i++) cin >> a[i];

	cout << solve(0, n-1, 1) << "\n";

	return 0;
}

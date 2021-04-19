#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
using ll = long long;

const int MAXN = 1000 + 5;
int a[MAXN], b[MAXN], n, m;
int dp[MAXN][MAXN];
bool vis[MAXN][MAXN];


int check(int p1){
	int cnt = 0;
	for(int i = 0;i <= p1;i++){
		cnt += (a[i] != b[i]);	
	}
	return cnt;
}

int solve(int p1, int p2){
	if (p1 == 0 or p2 == 0){
		return max(p1, p2);
	}
	if (vis[p1][p2]) return dp[p1][p2];

	dp[p1][p2] = min({solve(p1-1, p2) + 1, solve(p1, p2-1) + 1, solve(p1-1, p2-1) + (a[p1] != b[p2])});
	vis[p1][p2] = 1;
	return dp[p1][p2];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= m;i++) cin >> b[i];

	cout << solve(n, m) << "\n";	

	return 0;
}

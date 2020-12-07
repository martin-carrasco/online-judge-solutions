#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;
using ll = long long;

const int MAXN = 70 + 5;

int a[MAXN][MAXN], dp[MAXN][MAXN][MAXN/2][MAXN];


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, x;
	cin >> n >> m >> x;

	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin >> a[i][j];
		}
	}

	/*
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			for(int k = 1;k <= j/2;k++){
				for(int l = 1;l <= x;l++){
					dp[i][j][k][l] = -1e9;
				}
			}
		}
	}*/

	dp[0][0][0][0] = 0;


	int sum = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			for(int k = 1;k <= j/2;k++){
				for(int l = 1;l <= x;l++){
					dp[i][j][k][l] = max(dp[i][j-1][k][l], dp[i][j][k][l]);
					dp[i][j][k][l] = max(dp[i][j-1][k-1][l] + a[i][j], dp[i][j][k][(l + a[i][j]) % x]);
				}
			}
		}
	}
	cout << max(0, dp[n][m][m/2-1][0]) << "\n";

	return 0;
}


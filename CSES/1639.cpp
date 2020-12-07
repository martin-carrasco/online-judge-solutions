#include "bits/stdc++.h"

using namespace std;

const int MAXN = 5000 + 5;
int dp[MAXN][MAXN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s1, s2;
	cin >> s1 >> s2;

	int n = s1.size(), m=s2.size();
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= m;j++){
			if (i == 0)
				dp[i][j] = j;
			else if (j == 0)
				dp[i][j] = i;
			else if (s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
		}
	}
	cout << dp[n][m] << "\n";
	return 0;
}

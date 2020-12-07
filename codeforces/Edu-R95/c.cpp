#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;


const int MAXN = 1e6;
bool a[MAXN];
int dp[MAXN][2];


int n;
int solve(int f_t, int pos){
	if (pos >= n)
		return 0;
	if (dp[pos][f_t]) return dp[pos][f_t];

	if (f_t){
		int skips = 0;
		if (a[pos] == 1)
			skips++;	
		int opt1 = solve(!f_t, pos+1) + skips;
		int opt2 = solve(f_t, pos+1) + skips;

		int& res = dp[pos][f_t] = min(opt1, opt2);
		return res;
	} else{
		int opt1 = solve(!f_t, pos+1);
		int opt2 = solve(f_t, pos+1);
		int& res = dp[pos][f_t] = min(opt1, opt2);
		return res;
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		for(int i = 0;i <n;i++){
			for(int j = 0;j < 2;j++){
				dp[i][j] = 0;
			}
		}
		cin >> n;

		for(int i = 0;i < n;i++)
			cin >> a[i];

		cout << solve(1, 0) << "\n";

		cout << n << "\n";
	}
	return 0;
}

#include "bits/stdc++.h"
 
using namespace std;
using ll = long long;
 
const int MAXN = 1000 + 5;
const int MAXV = 1e5 + 5;
 
int w[MAXN], v[MAXN], dp[MAXV];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n, x;
	cin >> n >> x;
 
	for(int i = 0;i < n;i++) cin >> w[i];
	for(int i = 0;i < n;i++) cin >> v[i];
 
 
	for(int i = 0;i < n;i++){
		for(int j = x;j >= 0;j--){
			if (w[i] <= j)
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);	
		}
	}
	cout << dp[x] << "\n";	
	return 0;
}

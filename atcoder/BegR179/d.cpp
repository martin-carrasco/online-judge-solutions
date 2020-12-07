#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const ll MOD = 998244353;
const int MAXN = 1e6;

int dp[MAXN];
bool v[MAXN];

ll fast_mod(const ll input, const ll ceil) {
    return input >= ceil ? input % ceil : input;
}

vector<pair<int, int>> nums;
int solve(int n){

	if (v[n]) return dp[n];

	ll ways = 0;
	for(auto [l, r] : nums){
		for(int i = l;i <= r;i++) {
			int val = i;
			if (val >= n)
				break;
			int new_way = 0;
			if (v[n-val]){
				new_way = dp[n-val];
			} else {
				new_way = dp[n-val] = solve(n-val);	
				v[n-val] = 1;
			}
			ll ans = (ways + new_way);
			ways = fast_mod(ans, MOD);
		}
	}

	v[n] = 1;
	dp[n] = ways;
	return dp[n];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;


	for(int i = 0;i < k;i++){
		int l, r;
		cin >> l >> r;
		nums.push_back({l, r});
	}
	v[1] = 1;
	dp[1] = 1;

	cout << solve(n) << "\n";

	return 0;
}

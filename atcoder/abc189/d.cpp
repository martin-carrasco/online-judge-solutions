#include "bits/stdc++.h"

using namespace std;
using ll = unsigned long long;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 60 + 5;

int n;
bool logic_gate[MAXN];
int dp[i][

ll mask = 0LL;

bool is_set(int k){
	return mask & (1 << (k-1));
}

void set_bit(int k, int s){
	mask ^= (-s ^ mask) & (1UL << k);
}


bool check(){
	bool x_0 = is_set(0);
	for(int i = 1;i <= n;i++){
		x_0 = logic_gate[i] ? x_0 and is_set(i) : x_0 or is_set(i);
	}
	return x_0;
}

ll solve(int i){
	if (i == n+1) return (ll) check();

	if (dp.find(i) != dp.end() and dp[i].find(mask) != dp[i].end()) return dp[i][mask];

	ll ans = 0LL;

	set_bit(i, 0);
	ans += solve(i+1);
	set_bit(i, 1);
	ans += solve(i+1);

	dp[i][mask] = ans;
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 1;i <= n;i++){
		string s;
		cin >> s;
		logic_gate[i] = (s.compare("AND") == 0);
	}
	
	ll ans = solve(0) + 1;
	cout << ans << "\n";
	return 0;
}

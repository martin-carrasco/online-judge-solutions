#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;
using ll = long long;

const ll MOD = 1e9 + 7;
const int MAXN = 1e3 + 5;

bool g[MAXN][MAXN], vis[MAXN][MAXN];
ll paths[MAXN][MAXN];
int n;

ll add(ll a, ll b){
	if (a+b >= MOD)
		return a+b - MOD;
	return a+b;
}

bool invalid(int i, int j){
	return i == n or j == n or g[i][j];
}

ll dp(int i, int j){
	if (invalid(i, j)) return 0;
	if (i == n-1 and j == n-1) return 1;
	if (vis[i][j]) return paths[i][j];
	ll ans = dp(i+1, j);
	ans = add(ans, dp(i, j+1));
	vis[i][j] = 1;
	paths[i][j] = ans;
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			char c;
			 cin >> c;
			 g[i][j] = (c == '*');
		}
	}

	cout << dp(0, 0) << "\n";
	return 0;
}

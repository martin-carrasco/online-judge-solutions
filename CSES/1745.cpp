#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;

const int MAXN = 100 + 5;
const int MAXV = 1000*100 + 5;
int a[MAXN], vis[MAXN], seen[MAXV], v[MAXN][MAXV], dp[MAXN][MAXV], n;
vi seen_list;


int solve(int i, int sum){
	if (i == n)
		return 0;

	if (v[i][sum]) return dp[i][sum];
	
	int cnt = 0;
	int n_sum = sum + a[i];	
	vis[i] = 1;

	if (not seen[n_sum])  {
		seen[n_sum] = 1; 
		seen_list.push_back(n_sum);
		cnt++;
	}

	cnt += solve(i+1, n_sum);
	vis[i] = 0;
	
	cnt += solve(i+1, sum);

	dp[i][sum] = cnt;
	v[i][sum] = 1;

	return dp[i][sum];

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];

	solve(0, 0);
	cout << seen_list.size() << "\n";
	sort(seen_list.begin(), seen_list.end());
	for(auto seen_ele : seen_list)
		cout << seen_ele << " ";
	cout << "\n";
	return 0;
}

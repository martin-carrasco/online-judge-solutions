#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;

const int MAXN = 1e5 + 5;

int t, n, a[MAXN];
vector<int> A, B;

unordered_map<int, unordered_map<int, int>> dp;


int solve(int i, ){
	if (i == n) return 0;	

	if (dp.find(i) != dp.end() and dp[i].find(bts[0]) != dp[i].end()) return dp[i][bts[0]];

	int opt_1, opt_2;
	opt_1 = opt_2 = 0;

	int sum_n = 0;

	if (A.empty() or A.back() != a[i]) sum_n = 1;
	A.push_back(a[i]);

	opt_1 = solve(i+1, bts) + sum_n;
	A.pop_back();

	sum_n = 0;
	if (B.empty() or B.back() != a[i]) sum_n = 1;
	B.push_back(a[i]);
	cover.set(i);
	opt_2 = solve(i+1, modify) + sum_n;
	B.pop_back();

	dp[i][bts[0]] =  max({opt_1, opt_2});
	return dp[i][bts[0]];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	vector<bitset<MAXN>> wraper(1);
	for(int i = 0;i < n;i++) cin >> a[i];


	cout << solve(0, wraper) << "\n";
	return 0;
}

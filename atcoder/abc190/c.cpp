#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int MAXN = 100 + 5;

int n,m, a[MAXN], b[MAXN], c[MAXN], d[MAXN], k;
bool filled[MAXN];

int check() {
	int ans = 0;
	for(int i = 0;i < m;i++){
		//cout << filled[a[i]] << " " << filled[b[i]] << "\n";
		if (filled[a[i]] and filled[b[i]]) ans++;
	}
	//cout << "\n";
	return ans;
}

int solve(int i){
	if(i == k) return check();

	int opt1, opt2;
	opt1 = opt2 = 0;	

	bool last_fill = filled[c[i]];
	filled[c[i]] = 1;
	opt1 = solve(i+1);
	filled[c[i]] = last_fill;

	last_fill = filled[d[i]];
	filled[d[i]] = 1;
	opt2 = solve(i+1);
	filled[d[i]] = last_fill;

	return max(opt1,opt2);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i = 0;i < m;i++) cin >> a[i] >> b[i];

	cin >> k;
	for(int i = 0;i < k;i++) cin >> c[i] >> d[i];

	cout << solve(0) << "\n";
	return 0;
}

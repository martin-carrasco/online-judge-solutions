#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;

const int MAXN = 100+5;
ll a[MAXN][MAXN];
ll dif[MAXN*MAXN];
int n, m;
bool square_odd;

ll calc_dif(ll value){
	ll total = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if ((i == 0 and j == 0) or (i == n-1 and j == 0) or (i == 0 and j == m-1) or (i == n-1 and j == m-1) or square_odd)
				continue;
			total += abs(value - a[i][j]);
		}
	}
	return total;
}
ll calc_cornes(ll value){
	ll cors[4] = {a[0][0], a[0][m-1], a[n-1][0], a[n-1][m-1]};	
	ll total = 0;
	sort(cors, cors+4);
	ll median_c = (cors[2] + cors[1]) / 2;	
	for(int i = 0;i < 4;i++){
		total += abs(median_c - cors[i]);
	}
	return total;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;

		square_odd = m%2 == 1 and n%2 == 1;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++, s++){
				cin >> a[i][j];
			}
		}

		if (square_odd){
			int i = 0;
			while(i != n-i-1) {
				ll cors[4] = {a[i][n-1-i], a[i][i], a[n-1-i][i], a[n-i	
			}
		}

		ll ans = calc_dif(median_1);
		ans += calc_cornes(median_1);
		cout << ans << "\n";
	}

	return 0;
}

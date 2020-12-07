#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;

const int MAXN = 100+5;
ll a[MAXN][MAXN];
ll dif_row[MAXN];
ll dif_col[MAXN];
int n, m;

ll calc_dif(ll value){
	ll total = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
				total += abs(value - a[i][j]);
		}
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

		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				cin >> a[i][j];
			}
		}

		vi row_medians, col_medians;
		for(int i = 0;i < n;i++){
			vi vec;
			for(int j = 0;j < m;j++){
				vec.push_back(a[i][j]);
			}
			sort(vec.begin(), vec.end());
			ll median_1 = vec[(vec.size()-1) / 2];
			if (vec.size() % 2 == 0)
				row_medians.push_back((median_1+vec[vec.size() / 2]) / 2);
			else
				row_medians.push_back(median_1);
		}
	
		for(int j = 0;j < m;j++){
			vi vec;
			for(int i = 0;i < n;i++){
				vec.push_back(a[i][j]);
			}
			sort(vec.begin(), vec.end());
			ll median_1 = vec[(vec.size()-1) / 2];
			if ( vec.size() % 2 == 0)
				col_medians.push_back((median_1+vec[vec.size() / 2]) / 2);
			else
				col_medians.push_back(median_1);
		}

		sort(row_medians.begin(), row_medians.end());
		sort(col_medians.begin(), col_medians.end());

			
		ll median_1 = row_medians.size() % 2 == 0 ? (row_medians[(row_medians.size()-1) / 2] + row_medians[row_medians.size() / 2] ) / 2 : row_medians[(row_medians.size() - 1) / 2];
		ll median_2 = col_medians.size() % 2 == 0 ? (col_medians[(col_medians.size()-1) / 2] + col_medians[row_medians.size() / 2] ) / 2 : col_medians[(col_medians.size() - 1) / 2];

		ll ans = min(calc_dif(median_1), calc_dif(median_2));
		cout << ans << "\n";
	}

	return 0;
}

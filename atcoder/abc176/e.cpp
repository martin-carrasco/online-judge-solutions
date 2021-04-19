#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int MAX_N = 1e6;
int rc[MAX_N];
int cc[MAX_N];
int h, w, m;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	set<ii> pos;
	cin >> h >> w >> m;

	for(int i = 0;i < m;i++){
		int x, y;
		cin >> x >> y;
		rc[x] += 1;
		cc[y] += 1; 
		pos.insert({x, y});
	}

	int max_val_cols = 0;
	int max_col_idx = 0;
	int max_val_rows = 0;
	int max_row_idx = 0;

	for(int i = 1;i <= h;i++){
		int row_v = rc[i];
		if (row_v > max_val_rows) {
			max_val_rows= row_v;
			max_row_idx = i;
		}
	}

	for(int i = 1;i <= w;i++){
		int col_v = cc[i];
		if (pos.count(make_pair(max_row_idx, i)))
			col_v--;
		if (col_v > max_val_cols) {
			max_val_cols = col_v;
			max_col_idx = i;
		}
	}

	int ans1 = max_val_cols + max_val_rows;

	max_row_idx = max_val_rows = max_col_idx = max_val_cols = 0;

	for(int i = 1;i <= w;i++){
		int col_v = cc[i];
		if (col_v > max_val_cols) {
			max_val_cols = col_v;
			max_col_idx = i;
		}
	}

	for(int i = 1;i <= h;i++){
		int row_v = rc[i];
		if (pos.count(make_pair(i, max_col_idx)))
				row_v--;
		if (row_v > max_val_rows) {
			max_val_rows= row_v;
			max_row_idx = i;
		}
	}

	int ans2 = max_val_cols + max_val_rows;

	cout << max(ans2, ans1) << "\n";
	return 0;
}

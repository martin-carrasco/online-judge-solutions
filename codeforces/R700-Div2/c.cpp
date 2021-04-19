#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;

const int MAXN = 2e5 + 5;

int t, n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> n;

	int cnt = 100;
	int l = 0;
	int r = n-1;
	int ans = -1;
	while(cnt--){
		int mid = l +(r-l) / 2;	

		bool is_zero = mid == 0;
		bool is_final = mid == n-1;

		int val_mid, val_mid_u, val_mid_low;

		cout << "? " << mid + 1 << endl;	
		cout.flush();
		cin >> val_mid;

		if (not is_zero) {
			cout << "? " << mid << endl;	
			cout.flush();
			cin >> val_mid_low;
		}

		if (not is_final) {
			cout << "? " << mid + 2 << endl;	
			cout.flush();
			cin >> val_mid_u;
		}
		
		if( (mid == 0 or val_mid_low > val_mid) and (mid == n-1 or val_mid_u > val_mid)) {
			ans = mid;
			break;
		}

		else if (mid > 0 and val_mid_low < val_mid){
			r = mid - 1;
		} else {
			l = mid + 1;			
		}
	}
	cout << "! " << ans + 1 << endl;
	cout.flush();
	return 0;
}

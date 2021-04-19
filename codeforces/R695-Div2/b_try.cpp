#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
const int MAXN = 3e5 + 5;
int a[MAXN], n;

bool is_hill(int i){
	if (i <= 1 or i >= n) return false;
	return (a[i] > a[i-1] and a[i] > a[i+1]);
}
bool is_valley(int i){
	if (i <= 1 or i >= n) return false;
	return (a[i] < a[i-1] and a[i] < a[i+1]);

}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> a[i];
		
		int hills, valleys, minus;
		hills = valleys = minus = 0;
		for(int i = 1;i <= n;i++){
			int curr_minus = 0;

			if (i > 1 and i < n){
				if (is_hill(i)) hills++;
				if (is_valley(i))	valleys++;

				int tmp = a[i];
				int ad_terr = is_valley(i-1) + is_valley(i+1) + is_hill(i+1) + is_hill(i-1) + is_hill(i) + is_valley(i);

				a[i] = a[i-1];
				int eq_left = is_valley(i-1) + is_valley(i+1) + is_hill(i+1) + is_hill(i-1) + is_hill(i) + is_valley(i);
				a[i] = a[i+1];
				int eq_right = is_valley(i-1) + is_valley(i+1) + is_hill(i+1) + is_hill(i-1) + is_hill(i) + is_valley(i);
				a[i] = tmp;

				curr_minus = max({ad_terr-eq_right, ad_terr-eq_left, curr_minus});
				minus = max(minus, curr_minus);
			} else if (i == 1){
				int tmp = a[i];
				int ad_terr = is_valley(i+1) + is_hill(i+1);

				a[i] = a[i+1];
				int eq_right = is_valley(i+1) + is_hill(i+1);
				a[i] = tmp;

				curr_minus = max({ad_terr-eq_right, curr_minus});
				minus = max(minus, curr_minus);

			} else if (i == n){
				int tmp = a[i];
				int ad_terr = is_valley(i-1) + is_hill(i-1);

				a[i] = a[i-1];
				int eq_left = is_valley(i-1) + is_hill(i-1);
				a[i] = tmp;

				curr_minus = max({1-ad_terr,1-eq_left, curr_minus});
				minus = max(minus, curr_minus);
			}
		}
		int ans = max(hills + valleys - minus, 0);
		//cout << "hills: " << hills << "\n";
		//cout << "valleys: " << valleys << "\n";
		//cout << "minus: " << minus << "\n";

		cout << ans << "\n";
	}

	return 0;
}

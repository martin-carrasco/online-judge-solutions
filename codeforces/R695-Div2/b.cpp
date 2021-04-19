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
		for(int i = 2;i <= n-1;i++){
			if (is_hill(i)){
				hills++;
				minus = max(1, minus);
				if (is_valley(i-1) or is_valley(i+1)) minus = max(2, minus);
				if (is_valley(i-1) and is_valley(i+1)) minus = max(3, minus);
			}
			if (is_valley(i)){
				valleys++;
				minus = max(1, minus);
				if (is_hill(i-1) or is_hill(i+1)) minus = max(2, minus);
				if (is_hill(i-1) and is_hill(i+1)) minus = max(3, minus);
			}
		}
		int ans = hills + valleys - minus;
		//cout << "hills: " << hills << "\n";
		//cout << "valleys: " << valleys << "\n";

		cout << ans << "\n";
	}

	return 0;
}

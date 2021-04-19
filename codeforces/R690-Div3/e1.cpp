#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 2e5 +5;
ii a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		set<ii> ps;
		int n,m;
		m = 3;
		cin >> n;
		int ans = 0;

		for(int i = 0;i < n;i++){
			int tmp;
			cin >> tmp;
			a[i] = {tmp, i};
			ps.insert({tmp, i});
		}

		if (n < 3){
			cout << 0 << "\n";
			continue;
		}

		sort(a, a+n);

		for(int i = 0;i <= n-3;i++){
			int j = i+1;
			int k = j+1;

			auto it_up = ps.upper_bound(make_pair(a[i].first + 3, 0));
			auto it_low = ps.lower_bound(make_pair(a[i].first, -1));
			--it_up;
			int up_pos = distance(ps.begin(), it_up);
			int low_pos = distance(ps.begin(), it_low);

			cout << "i: " << i << endl;
			cout << "Upper bound:" << up_pos << endl;
			cout << "lower bound: " << low_pos << endl << endl;

			if (up_pos - i < 2) continue;

			for(int z = i+2;z <= up_pos;z++){
				ans += (z - i - 1); 
			}
		}
		cout << ans << "\n";
	}

	return 0;
}

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		set<int> seen;

		ll ans_neg = 0;
		ll ans_pos = 0;
		for(int i = 0;i < n;i++){
			ll tmp;
			cin >> tmp;

			if (seen.count(tmp))
				continue;
			seen.insert(tmp);
			if (tmp < 0)
				ans_neg += tmp;
			else
				ans_pos += tmp;	
		}

		cout << ans_pos << " " << ans_neg << "\n";
	}
	return 0;

}

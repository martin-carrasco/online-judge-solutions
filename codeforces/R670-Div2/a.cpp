#include "bits/stdc++.h"

using namespace std;
using vi =vector<int>;

int min_pres(vi & v){
	for(int i = 0;i < v.size();i++){
		if (v[i] != i)
			return i;
	}
	return v.size();
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vi v(n, 0);

		for(int i = 0;i < n;i++)
			cin >> v[i];

		sort(v.begin(), v.end());
		vi cp_v = v;

		v.erase(unique(v.begin(), v.end()), v.end());

		int ans = min_pres(v);

		for(auto it = v.begin();it != v.end();it++){
			int val = *it;
			cp_v.erase(find(cp_v.begin(), cp_v.end(), val));
		}

		cp_v.erase(unique(cp_v.begin(), cp_v.end()), cp_v.end());

		ans += min_pres(cp_v);

		cout << ans << "\n";

	}

	return 0;
}

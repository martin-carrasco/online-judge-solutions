#include "bits/stdc++.h"

using namespace std;

int a[11];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		for(int i = 0;i < n;i++){
			int v;
			cin >> v;
			a[v] += 1;
		}

		map<int, int> mp;

		for(int i=1;i <= 10;i++){
			if(mp.count(a[i]))
					mp[a[i]]++;
			else
				mp[a[i]]= 1;
		}
		
		int max_val = 0;
		for(auto [k, v] : mp){
			if (k != 0)
				max_val = max(v, max_val);
		}

		int ans = 1e9;
		for(auto [k, v] : mp){
			if (v == max_val and k > 0)	
				ans = min(ans, k);
		}
		cout << ans << "\n";
		for(int i = 1;i <= 10;i++)
			a[i] = 0;
	}
	return 0;
}

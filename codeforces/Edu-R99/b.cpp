#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int x;
		cin >> x;
		int st = 0;
		vi steps;
		for(int i = 1;i <= x;i++){
			st += i;	
			steps.push_back(i);
			if (st >= x)
				break;
		}
		int ans = steps.size();
		if (st > x){
			int res = st - x - 1;
			if (res < 1)
				ans++;
		}
		cout << ans << "\n";	
	}
	return 0;
}

#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;

const int MAXN = 1e6;
int a[MAXN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	set<ii> nums;
	for(int i = 0;i < n; i++){
		int t;
		cin >> t;
		nums.emplace(t, i);
	}
	
	bool found = false;
	while(nums.size() > 0){
		auto big = nums.lower_bound({x, 1e9});
		if (big == nums.end()) {
			if (big == nums.end())
				--big;
		}
		auto small = nums.lower_bound({x - big->first, 0});
		if (small != nums.end() and small != big and small->first == (x-big->first)){
			found = true;
			cout << big->second+1 << " " << small->second+1 << "\n";
			break;
		}
		if (big != nums.end())
			nums.erase(big);
	}
	if (not found)
		cout << "IMPOSSIBLE" << "\n";

	return 0;
}

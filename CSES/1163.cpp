#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	set<int> intervals; 
	multiset<int> lengths;

	int x, n;
	cin >> x >> n;

	intervals.insert(0);
	intervals.insert(x);

	lengths.insert(x);

	for(int i = 0;i < n;i++){
		int split;
		cin >> split;


		auto it = intervals.upper_bound(split);

		int up = *it;
		--it;
		int down = *it;

		lengths.erase(lengths.find(up-down));
		intervals.insert(split);
		lengths.insert(abs(down - split));
		lengths.insert(abs(up - split));
		
		auto res = lengths.end();
		--res;
		
		cout << *res << " ";
	}

	cout << "\n";
	return 0;
}

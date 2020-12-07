#include "bits/stdc++.h"
 
using namespace std;
using vi = vector<int>;
 
const int MAXN = 1e5 + 5;
 
int a[MAXN]; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	multiset<int, greater<int>> vals;
	vector<int> ans;

	for(int i = 0;i < n;i++){
		cin >> a[i];
		vals.insert(a[i]);
	}
	sort(a, a+n);

	if (n < 3){
		cout << 0 << "\n";
		for(int i = 0;i < n;i++)
			cout << a[i] << " ";
		cout << "\n";
		return 0;
	}

	auto best = vals.begin();
	auto second_best = next(vals.begin(), 1);
	auto best_mid = vals.lower_bound((*second_best)- 1);

	ans.push_back(*second_best);
	ans.push_back(*best_mid);
	ans.push_back(*best);

	vals.erase(second_best);
	vals.erase(best_mid);
	vals.erase(best);

	do{

		auto second_best = vals.begin();
		auto best_mid = vals.lower_bound((*second_best)- 1);

		if (best_mid == vals.end())
			best_mid = next(second_best, 1);

		ans.push_back(*best_mid);
		ans.push_back(*second_best);

		vals.erase(second_best);
		vals.erase(best_mid);
	}
	while(vals.size() > 2);

	if (vals.size() == 1) {
		ans.push_back(*vals.begin());
	}
	else if (vals.size() > 1) {
		auto tmp = next(vals.begin(), 1);
		ans.push_back(*tmp);
		ans.push_back(*vals.begin());
	}

	int cnt = 0;
	for(int k = 1;k < ans.size() - 1;k++){
		int l = ans[k-1];
		int r = ans[k+1];
		int v = ans[k];

		if (v < l and v < r)  {
			cnt++;
		}
	}

	cout << cnt << "\n";
	for(auto ele : ans)
		cout << ele << " ";
	cout << "\n";
		
	return 0;
}

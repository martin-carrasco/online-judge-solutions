#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1e6;
int a[MAXN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	multiset<int> min_list;

	for(int i = 0;i < n;i++) cin >> a[i];

	min_list.insert(a[0]);
	for(int i = 1;i < n;i++){
		auto big_ele = min_list.upper_bound(a[i]);

		if (big_ele != min_list.end() and *big_ele > a[i]){
			min_list.erase(big_ele);
			min_list.insert(a[i]);
		} else {
			min_list.insert(a[i]);
		}
	}
	cout << min_list.size() << "\n";


	return 0;
}

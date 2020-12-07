#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include "bits/stdc++.h"

using namespace std;
using namespace __gnu_pbds; 
using ii = pair<int, int>;

using idx_set = tree<ii, null_type, less<ii>, rb_tree_tag, 
             tree_order_statistics_node_update>; 

const int MAXN = 2e5 + 5;
ii a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	idx_set q;
	int n, k;
	cin >> n >> k;
	for(int i = 0;i < n;i++){
		int val;
		cin >> val;
		a[i] = {val, i};
	}

	for(int i = 0;i < k;i++)
		q.insert(a[i]);

	for(int i = k;i < n;i++){
		int median_idx = (k-1) / 2;
		int median =q.find_by_order(median_idx)->first; 
		cout << median << " ";
		
		q.erase(q.find(a[i-k]));
		q.insert(a[i]);
	}
	int median_idx = (k-1) / 2;
	int median = q.find_by_order(median_idx)->first;
	cout << median << " ";

	cout << "\n";
	return 0;
}

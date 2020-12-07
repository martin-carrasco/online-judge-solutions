#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int MAXN = 2e5;


int a[MAXN];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		for(int i  = 0;i < n;i++) cin >> a[i];

		sort(a, a+n, greater<int>());
		ll max_water = a[0];
		for(int i = 1;i < min(k,n)+1;i++){
			max_water += (ll)a[i];
		}
		cout << max_water << "\n";
	}

	return 0;
}


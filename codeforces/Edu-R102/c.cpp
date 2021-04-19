#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;


int t, n, k;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--){
		cin >> n >> k;
		if (n == k){
			for(int i = 1;i <= n;i++){
				cout << i << " ";
			}
			cout << "\n";
			continue;
		}

		for(int i = 1; i <= k-2;i++){
			cout << i << " ";	
		}
		cout << k << " " << k-1 << "\n";
	}
	return 0;
}

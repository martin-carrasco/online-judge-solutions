#include "bits/stdc++.h"

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;

		int hs = n / k;
		int mj = min(hs, m);
		int lj = m - mj;

		cout << max(mj - ceil(lj*1.0 / (k-1)), 0.0) << "\n";

	}
}

#include "bits/stdc++.h"

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int  t;
	cin >> t;
	while(t--){
		int n, x;
		cin >> n >> x;
		
		if (n == 1 or n == 2) {
			cout << 1 << "\n";
			continue;
		}

		int times_x = ceil((n-2)*1.0 / x);
		cout << times_x + 1 << "\n";
	}
	return 0;
}

#include "bits/stdc++.h"

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int dif = abs(k - n);

		if (k < n) {
			if (k % 2 == 0 and n % 2 == 0 or ( k % 2 == 1 and n % 2 == 1))
				cout << 0 << "\n";
			else
				cout << 1 << "\n";
		}
		else {
			cout << dif << "\n";
		}

	}

	return 0;
}

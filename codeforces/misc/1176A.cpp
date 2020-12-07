#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main(){
	int q;
	cin >> q;
	while(q--) {
		ll n;
		cin >> n;

		int cnt = 0;
		while(n > 1){
			if (n % 2 == 0)
				n = n / 2;
			else if (n % 3 == 0)
				n = (2 * n) / 3;
			else if (n % 5 == 0)
				n = (4 * n) / 5;
			else
				break;
			cnt++;
		}

		if(n == 1)
			cout << cnt << "\n";
		else
			cout << -1 << "\n";
	}


	return 0;
}

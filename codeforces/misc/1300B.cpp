#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		ll sum_1 = 0;
		ll sum_2 = 0;
		for(int i = 0;i < 2*n;i++){
			ll val;
			cin >> val;
			if(i % 2 == 0)
				sum_1 += val;
			else
				sum_2 += val;
		}

		cout << abs(sum_1 - sum_2) << "\n";
	}
	return 0;
}

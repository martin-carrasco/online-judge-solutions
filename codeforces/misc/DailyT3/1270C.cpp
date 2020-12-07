#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int MAX_N = 1e5 + 5;

int a[MAX_N];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		ll sum = 0;
		ll xor_bitwise = 0;
		for(int i = 0;i < n;i++) {
			cin >> a[i];
			sum+=a[i];
			xor_bitwise ^= a[i];
		}
		cout << 2 << endl<< xor_bitwise << " " << (2 * xor_bitwise  + 2 * sum) / 2  << endl;
	}
	return 0;
}

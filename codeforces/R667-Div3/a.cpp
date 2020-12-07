#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		ll a,b;
		cin >> a >> b;

		ll v = ceil(abs(b - a) * 1.0 / 10);

		cout << v << "\n";
	}

	return 0;
}

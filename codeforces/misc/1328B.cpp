#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;


		ll i = n-2 - min(k-1 + (ll)floor((k-1)*(k)*1.0 / 2), n-2);
		int j = n-1;

		cout << i  << "\n";

		string s = "";
		for(int x = 0;x < n;x++){
			if (x == i or x == j)
				s.append("b");
			else
				s.append("a");
		}
		cout << s << "\n";
	}
	return 0;
}

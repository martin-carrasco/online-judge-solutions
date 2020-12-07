#include "bits/stdc++.h"

using namespace std;
using ll = long long;

ll sum_digits(string& s){
	ll sum = 0;
	for(auto c : s){
		sum += (ll)(c - '0');
	}
	return sum;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		string n;
		int s;
		cin >> n;
		cin >> s;

		int digit = n.size() - 1;
		ll moves = 0;
		ll sum_d = sum_digits(n);
		cout << sum_d << "\n";
		while(sum_digits(n) > s){
			int dif = 10 - (n[digit] - '0');
			moves += dif;
			if (digit == 0)
				digit = n.size() - 1;
			else{
				int prop_count = digit - 1;
				while(n[prop_count] - '0' == 9){
					n[prop_count] = '0';			
					prop_count++;
				}
				n[prop_count] += 1;
			}
		}
		cout << moves << "\n";

	}

	return 0;
}

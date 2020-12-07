#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin  >> t;
	while(t--){
		int n;
		cin >> n;
		if (n % 2){ 
			int nn = n;
			int mid = ceil(n*1.0 / 2);
			while(nn != 0){
				if (nn == n){
					cout << mid << " ";	
				} else if (nn == mid) {
					cout << n << " ";	
				}
				else {
					cout << nn << " ";
				}
				nn--;
			}
		} else {
			while(n != 0){
				cout << n-- << " ";
			}
		}
		cout << "\n";

	}

	return 0;
}

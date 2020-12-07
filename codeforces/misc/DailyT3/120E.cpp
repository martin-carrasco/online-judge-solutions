#include "bits/stdc++.h"

using namespace std;

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if (n == 1) {
			cout << 0 << "\n";
		} else if(n == 2) {
			cout << 1 << "\n";
		} else {
			bool b = n % 2 == 0;
			cout << b << "\n";
		}
	}
	return 0;
}

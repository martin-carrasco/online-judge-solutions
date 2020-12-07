#include "bits/stdc++.h"

using namespace std;

int main(){
	int n, x ,t;
	cin >> n >> x >> t;
	if (n % x == 0)
		cout <<  (n / x) * t << "\n";
	else
		cout << (floor(n/x) + 1) * t << "\n";
	return 0;
}

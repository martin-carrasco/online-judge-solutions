#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;
using ll = long long;


unsigned int current = 0;
set<unsigned int> mp;
int n;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	ll ans = 1;
	for(int i = 1;i < n;i++){
		ans *= i;
	}


	cout << (ans / (n/2)) << "\n";	


	return 0;
}


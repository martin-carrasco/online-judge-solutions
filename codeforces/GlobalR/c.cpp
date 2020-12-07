#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int MAX_N =  1e6;
ll a[MAX_N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		for(int i = 0; i < n;i++){
			cin >> a[i];
		}
	
		ll sum = 0;
		for(int i = 1; i < n;i++){
			if (a[i - 1] > a[i])
				sum += a[i-1] - a[i];
		}

		cout << sum << "\n";
	}
	return 0;
}

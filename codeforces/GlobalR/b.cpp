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
		ll k;
		cin >> n >> k;

		for(int i = 0;i < n;i++) {
			cin >> a[i];
		}

		ll d = *max_element(a, a+n);

		for(int i = 0; i < n;i++){
			a[i] = d - a[i];
		}

		if (k % 2 == 0){
			d = *max_element(a, a+n);

			for(int i = 0; i < n;i++){
				a[i] = d - a[i];
			}
		}
		for(int i = 0;i < n;i++)
			cout << a[i] << " ";
		cout << "\n";
	}
	return 0;
}

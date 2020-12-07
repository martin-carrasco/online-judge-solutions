#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int MAXN = 1e6;

ll a[MAXN];
int main(){
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> a[i];
	
	ll sum = 0;
	for(int i = 1;i < n;i++){
		if (a[i] < a[i - 1]) {
			sum += a[i-1] - a[i];
			a[i] = a[i-1];
		}
	}
	cout << sum << "\n";
	return 0;
}

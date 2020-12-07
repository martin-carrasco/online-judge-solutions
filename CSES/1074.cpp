#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int MAXN = 1e6;


ll a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	ll sum = 0;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		sum += a[i];
	}

	sort(a, a+n);

	ll mid = a[n/2];

	ll cnt = 0;
	for (int i = 0;i < n;i++) {
		cnt += abs(mid - a[i]);	
	}
	cout << cnt << "\n";
	return 0;
}

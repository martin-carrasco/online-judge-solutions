#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;
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

	cout << max(sum, 2LL*a[n-1]) << "\n";


	return 0;
}

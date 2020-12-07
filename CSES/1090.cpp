#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int MAXN = 1e6;

ll a[MAXN];
int main(){
	ll n, x;
	cin >> n >> x;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}

	sort(a, a+n, greater<ll>());

	int gondolas = 1;
	for(int i = 0;i < n;i++){
		ll val = a[i];		
		if (val + a[n-1] <= x)
			n--;
		if (i < n-1)
			gondolas++;
	}

	return 0;
}


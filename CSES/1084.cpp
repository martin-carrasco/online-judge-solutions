#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int MAXN = 1e6;
ll a[MAXN];
ll b[MAXN];

int main(){
	ll n, m, k;
	cin >> n >> m >> k;

	for(int i = 0;i < n;i++) cin >> a[i];	
	for(int i = 0;i < m;i++) cin >> b[i];	

	sort(a, a+n);
	sort(b, b+m);

	int idx_apt = 0;
	int cnt = 0;
	for(int i = 0;i < n;i++){
		if (idx_apt == m)
			break;

		ll curr = b[idx_apt];		
		ll pref = a[i];

		while(pref - k > curr) {
			if (idx_apt == m-1)
				break;
			curr = b[++idx_apt];

		}

		if (abs(pref - curr) <= k){
			cnt++;
			idx_apt++;
		}

	}

	cout << cnt << "\n";	
	return 0;
}

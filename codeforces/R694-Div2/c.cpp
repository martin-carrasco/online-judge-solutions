#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 3e5 + 5;
int k[MAXN], c[MAXN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		set<int> taken;
		set<ii> prices;
		ll tot = 0L;
		int n, m;
		cin >> n >> m;
		for(int i = 1;i <= n;i++) cin >> k[i];
		for(int i = 1;i <= m;i++) {
			cin >> c[i];
			prices.push({c[i], i});
		}

		for(int i = 1;i <= n;i++){
			if (taken.count(
			if (c[i] 	
		}


	}


	return 0;
}

#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
using ll = long long;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	set<ll> pos;
	vector<ll> interval_size;
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		int p;
		cin>> p;
		pos.insert(p);
	}
	pos.insert(n+1);


	ll last = 0;
	ll k = 1e18;
	for(auto val : pos){
		if (val - last == 1) {last = val;continue;}
		interval_size.push_back(val - last - 1);
		k = min(val - last - 1, k);
		last = val;
	}
	if (k == 1e18)
		k = 0;
	ll ans = 0;
	for(auto inter : interval_size){
		ans += ceil(inter*1.0 / k);
	}

	cout << ans << "\n";
	return 0;
}
